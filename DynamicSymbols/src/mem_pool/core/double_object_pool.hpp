#pragma once

#include "mem_block.hpp"
#include "object/atomic_object.h"
#include "utils/singleton.hpp"

namespace _MEM_POOL_ {

    class DoubleObjectPool : public SingletonBase<DoubleObjectPool>
    {
        friend class SingletonBase<DoubleObjectPool>;
    public:
        DoubleObject* CreateDoubleObject(const double val);

        void Recycle(DoubleObject* ptr);

    private:
        virtual ~DoubleObjectPool() {
            delete first_block;
        }

        DoubleObjectPool();
    private:
        DoubleObject* free_num_cursor;
        MemoryBlock<DoubleObject>* first_block;
    };

}   // !namespace _MEM_POOL_