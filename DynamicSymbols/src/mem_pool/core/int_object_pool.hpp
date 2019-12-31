#pragma once

#include "mem_block.hpp"
#include "object/atomic_object.h"
#include "utils/singleton.hpp"

namespace _MEM_POOL_ {
    // 取消了小整数池的设计

    class IntObjectPool final : public SingletonBase<IntObjectPool>
    {
        friend class SingletonBase<IntObjectPool>;
    public:

        IntObject* CreateIntObject(const int val);

        void Recycle(IntObject* ptr);

        virtual ~IntObjectPool() {
            delete first_block;
        }
    private:
        IntObjectPool();
    private:
        IntObject* free_num_cursor;
        IntObject* m_small_pool;
        MemoryBlock<IntObject>* first_block;
    };
}   // !namespace _MEM_POOL_

