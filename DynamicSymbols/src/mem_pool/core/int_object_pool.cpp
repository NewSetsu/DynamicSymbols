#include "int_object_pool.hpp"

using namespace _MEM_POOL_;

_MEM_POOL_::IntObjectPool::IntObjectPool()
{
    // 申请第一块空间，大小512
    first_block = new MemoryBlock<IntObject>();
    first_block->next = nullptr;

    // 指向空间的首地址
    free_num_cursor = first_block->m_buf;
    m_small_pool = free_num_cursor;

    // 小整数池填充
    for (int i = 0; i < CONST_INT_POOL_MAX; i++)
    {
        m_small_pool[i].SetVal(i + CONST_INT_POOL_MIN);
        m_small_pool[i].m_use_cnt = 1;
    }
    // 
    free_num_cursor += CONST_INT_POOL_MAX;
}


IntObject* _MEM_POOL_::IntObjectPool::CreateIntObject(const int val)
{
    // 小整数
    if (val > CONST_INT_POOL_MIN && val < CONST_INT_POOL_MAX)
    {
        return static_cast<IntObject*>(
            m_small_pool[val - CONST_INT_POOL_MIN].VarRef()
            );
    }
    
    auto ans = free_num_cursor;
    ans->SetVal(val);

    // 游标指向内存池下一个数据
    free_num_cursor = static_cast<IntObject*>(free_num_cursor->next_in_pool);
    // 若下一个数据地址为空指针，则创建一个新的数据块
    if (nullptr == free_num_cursor)
    {
        auto tmp_block = new MemoryBlock<IntObject>();
        tmp_block->next = first_block;
        first_block = tmp_block;
        free_num_cursor = first_block->m_buf;
    }

    return static_cast<IntObject*>(ans->VarRef());
}

void _MEM_POOL_::IntObjectPool::Recycle(IntObject* ptr)
{
    ptr->Reset();
    ptr->next_in_pool = free_num_cursor;
    free_num_cursor = ptr;
}

