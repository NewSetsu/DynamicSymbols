#pragma once

namespace _MEM_POOL_ {

    // 单个内存块的数据量， 实际占据空间为 512 * sizeof(T)
    constexpr const int BLOCK_SIZE = 4096;

    /*!
     * \struct  MemoryBlock
     * \brief   避免连续在内存中申请空间，内存池使用的内存都来自MemoryBlock
     * \author  chengx
     * \date    2019.12.24
     */
    template<typename T>
    struct MemoryBlock
    {
        MemoryBlock* next;
        T* m_buf;
        // 申请一片512 * sizeof(T)的空间
        // m_buf指向空间首地址
        MemoryBlock() 
        {
            m_buf = new T[BLOCK_SIZE];

            for (int i = 0; i < BLOCK_SIZE - 1; i++)
            {
                m_buf[i].next_in_pool = &m_buf[i + 1];
            }
            m_buf[BLOCK_SIZE - 1].next_in_pool = nullptr;

            next = nullptr;
        }

        ~MemoryBlock()
        {
            if (next != nullptr)
                next->~MemoryBlock();
            delete[] m_buf;
            m_buf = nullptr;
            next = nullptr;
        }
    };
}

