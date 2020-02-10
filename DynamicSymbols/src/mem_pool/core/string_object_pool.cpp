#include "string_object_pool.hpp"

_MEM_POOL_::StringObjectPool::StringObjectPool()
{
    m_template = StringObject();
    first_block = new MemoryBlock<StringObject>;
    free_num_cursor = first_block->m_buf;
}

StringObject* _MEM_POOL_::StringObjectPool::CreateStringObject(const char* val)
{
    auto ans = free_num_cursor;
    ans->SetVal(val);

    free_num_cursor = static_cast<StringObject*>(free_num_cursor->next_in_pool);

    if (nullptr == free_num_cursor)
    {
        auto tmp_block = new MemoryBlock<StringObject>;
        tmp_block->next = first_block;
        first_block = tmp_block;
        free_num_cursor = tmp_block->m_buf;
    }
    return ans;
}

void _MEM_POOL_::StringObjectPool::Recycle(StringObject* ptr)
{
    ptr->Reset();
    ptr->next_in_pool = free_num_cursor;
    free_num_cursor = ptr;
}

StringObject* _MEM_POOL_::StringObjectPool::GetTemplate()
{
    return &m_template;
}
