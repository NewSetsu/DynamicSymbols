#include "byte_object_pool.hpp"
#include "byte_object_pool.hpp"

ByteObject* _MEM_POOL_::ByteObjectPool::CreateByteObject(const unsigned char val)
{
    // return static_cast<ByteObject*>(m_buf[val].VarRef());
    return &m_buf[val];
}

void _MEM_POOL_::ByteObjectPool::Recycle(ByteObject* ptr)
{
    ptr->Reset();
    // Byte内存池资源只有程序结束才会释放
}

_MEM_POOL_::ByteObjectPool::ByteObjectPool()
{
    byte_block = new MemoryBlock<ByteObject>;
    m_buf = byte_block->m_buf;

    for (int i = 0; i < CONST_BYTE_POOL_MAX - CONST_BYTE_POOL_MIN; i++)
    {
        m_buf[i].SetVal(static_cast<unsigned char>(i));
        m_buf[i].m_use_cnt = 1;
    }
}
