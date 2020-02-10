#pragma once

#include "mem_block.hpp"
#include "object/atomic_object.h"
#include "utils/singleton.hpp"

namespace _MEM_POOL_ {

    class DoubleObjectPool final
    {
    private:
        DoubleObjectPool();
        virtual ~DoubleObjectPool() {
            delete first_block;
        }
        DoubleObjectPool(const DoubleObjectPool&) = default;
        DoubleObjectPool& operator=(const DoubleObjectPool&) = default;
    public:
        static DoubleObjectPool* GetInstance() {
            static DoubleObjectPool instance;
            return &instance;
        }

        DoubleObject* CreateDoubleObject(const double val);

        void Recycle(DoubleObject* ptr);

        DoubleObject* GetTemplate();
    private:
        DoubleObject m_template;
        DoubleObject* free_num_cursor;
        MemoryBlock<DoubleObject>* first_block;
    };

}   // !namespace _MEM_POOL_