#include "bool_object_pool.hpp"

_MEM_POOL_::BoolObjectPool::BoolObjectPool()
{
    // 申请512个数据的空间
    first_block = new MemoryBlock<BoolObject>();

    // 指针指向空间首地址
    free_num_cursor = first_block->m_buf;
}

BoolObject* _MEM_POOL_::BoolObjectPool::CreateBoolObject(const bool val)
{
    auto ans = free_num_cursor;
    ans->SetVal(val);

    free_num_cursor = static_cast<BoolObject*>(free_num_cursor->next_in_pool);

    if (nullptr == free_num_cursor)
    {
        auto tmp_block = new MemoryBlock<BoolObject>();
        tmp_block->next = first_block;
        first_block = tmp_block;
        free_num_cursor = first_block->m_buf;
    }

    return static_cast<BoolObject*>(ans->VarRef());
}

void _MEM_POOL_::BoolObjectPool::Recycle(BoolObject* ptr)
{
    ptr->Reset();
    ptr->next_in_pool = free_num_cursor;
    free_num_cursor = ptr;
}

