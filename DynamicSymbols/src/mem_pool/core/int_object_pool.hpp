#pragma once

#include "mem_block.hpp"
#include "object/atomic_object.h"
#include "utils/singleton.hpp"

namespace _MEM_POOL_ {
    // 取消了小整数池的设计

    class IntObjectPool final 
    {
    private:
        IntObjectPool();
        virtual ~IntObjectPool() {
            delete first_block;
        }
        IntObjectPool(const IntObjectPool&) = default;
        IntObjectPool& operator=(const IntObjectPool&) = default;
    public:
        static IntObjectPool* GetInstance() {
            static IntObjectPool instance;
            return &instance;
        }

        IntObject* CreateIntObject(const int val);

        IntObject* GetTemplate();

        void Recycle(IntObject* ptr);
    private:
        IntObject m_template;
        IntObject* free_num_cursor;
        MemoryBlock<IntObject>* first_block;
    };
}   // !namespace _MEM_POOL_

