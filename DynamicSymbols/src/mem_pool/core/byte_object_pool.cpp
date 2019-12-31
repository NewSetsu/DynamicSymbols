#include "byte_object_pool.hpp"
#include "byte_object_pool.hpp"

ByteObject* _MEM_POOL_::ByteObjectPool::CreateByteObject(const unsigned char val)
{
    auto ans = free_num_cursor;
    ans->SetVal(val);

    free_num_cursor = static_cast<ByteObject*>(free_num_cursor->next_in_pool);

    if (nullptr == free_num_cursor)
    {
        auto tmp_block = new MemoryBlock<ByteObject>();
        tmp_block->next = first_block;
        first_block = tmp_block;
        free_num_cursor = first_block->m_buf;
    }

    return ans;
}

void _MEM_POOL_::ByteObjectPool::Recycle(ByteObject* ptr)
{
    ptr->Reset();
    ptr->next_in_pool = free_num_cursor;
    free_num_cursor = ptr;
}

_MEM_POOL_::ByteObjectPool::ByteObjectPool()
{
    first_block = new MemoryBlock<ByteObject>;
    free_num_cursor = first_block->m_buf;

    for (int i = 0; i < CONST_BYTE_POOL_MAX - CONST_BYTE_POOL_MIN; i++)
    {
        free_num_cursor[i].SetVal(static_cast<unsigned char>(i));
    }
}
