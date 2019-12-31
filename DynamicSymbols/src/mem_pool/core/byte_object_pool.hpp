#pragma once

#include "mem_block.hpp"
#include "object/atomic_object.h"
#include "utils/singleton.hpp"

namespace _MEM_POOL_ {
#define CONST_BYTE_POOL_MIN 0
#define CONST_BYTE_POOL_MAX 256

    // Byte内存池
    // 由于Byte只有 0~255，所以只需要一个内存块就可表示所有数据
    class ByteObjectPool final 
    {
    private:
        ByteObjectPool();
        virtual ~ByteObjectPool() {
            delete first_block;
            free_num_cursor = nullptr;
            first_block = nullptr;
        }
        ByteObjectPool(const ByteObjectPool&) = default;
        ByteObjectPool& operator=(const ByteObjectPool&) = default;
    public:
        static ByteObjectPool* GetInstance() {
            static ByteObjectPool instance;
            return &instance;
        }
        ByteObject* CreateByteObject(const unsigned char val);

        void Recycle(ByteObject* ptr);

        const ByteObject* GetTemplate();
    private:
        ByteObject m_template;
        MemoryBlock<ByteObject>* first_block;
        ByteObject* free_num_cursor;
    };


}   // !namespace _MEM_POOL_