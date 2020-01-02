#include "double_object_pool.hpp"

using namespace _MEM_POOL_;

_MEM_POOL_::DoubleObjectPool::DoubleObjectPool()
{
    m_template = DoubleObject();
    first_block = new MemoryBlock<DoubleObject>;
    free_num_cursor = first_block->m_buf;
}

DoubleObject* _MEM_POOL_::DoubleObjectPool::CreateDoubleObject(const double val)
{
    auto ans = free_num_cursor;
    ans->SetVal(val);

    free_num_cursor = static_cast<DoubleObject*>(free_num_cursor->next_in_pool);

    if (nullptr == free_num_cursor)
    {
        auto tmp_block = new MemoryBlock<DoubleObject>;
        tmp_block->next = first_block;
        first_block = tmp_block;
        free_num_cursor = first_block->m_buf;
    }

    return ans;
}

void _MEM_POOL_::DoubleObjectPool::Recycle(DoubleObject* ptr)
{
    ptr->Reset();
    ptr->next_in_pool = free_num_cursor;
    free_num_cursor = ptr;
}

const DoubleObject* _MEM_POOL_::DoubleObjectPool::GetTemplate()
{
    return &m_template;
}

