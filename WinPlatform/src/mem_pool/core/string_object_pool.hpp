#pragma once

#include "mem_block.hpp"
#include "object/atomic_object.h"
#include "utils/singleton.hpp"

namespace _MEM_POOL_ {
    class StringObjectPool : public SingletonBase<StringObjectPool>
    {
        friend class SingletonBase<StringObjectPool>;
    public:
        StringObject* CreateStringObject(const char* val);

        void Recycle(StringObject* ptr);

    private:
        virtual ~StringObjectPool() {
            delete first_block;
        }
        StringObjectPool();
    private:
        StringObject* free_num_cursor;
        MemoryBlock<StringObject>* first_block;

    };

} // !namespace _MEM_POOL_