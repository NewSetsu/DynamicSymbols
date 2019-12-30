#include "string_object_pool.hpp"

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
    return static_cast<StringObject*>(ans->VarRef());
}

void _MEM_POOL_::StringObjectPool::Recycle(StringObject* ptr)
{
    ptr->Reset();
    ptr->next_in_pool = free_num_cursor;
    free_num_cursor = ptr;
}

_MEM_POOL_::StringObjectPool::StringObjectPool()
{
    first_block = new MemoryBlock<StringObject>;
    first_block->next = nullptr;

    free_num_cursor = first_block->m_buf;
}
