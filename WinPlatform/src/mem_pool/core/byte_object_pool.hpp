#pragma once

#include "mem_block.hpp"
#include "object/atomic_object.h"
#include "utils/singleton.hpp"

namespace _MEM_POOL_ {
#define CONST_BYTE_POOL_MIN 0
#define CONST_BYTE_POOL_MAX 256

    // Byte内存池
    // 由于Byte只有 0~255，所以只需要一个内存块就可表示所有数据
    class ByteObjectPool final : public SingletonBase<ByteObjectPool>
    {
        friend class SingletonBase<ByteObjectPool>;
    public:
        ByteObject* CreateByteObject(const unsigned char val);

        void Recycle(ByteObject* ptr);

    private:
        virtual ~ByteObjectPool() {
            delete byte_block;
            m_buf = nullptr;
            byte_block = nullptr;
        }

        ByteObjectPool();
    private:
        MemoryBlock<ByteObject>* byte_block;
        ByteObject* m_buf;
    };


}   // !namespace _MEM_POOL_