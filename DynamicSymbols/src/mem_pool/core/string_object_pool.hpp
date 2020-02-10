#pragma once

#include "mem_block.hpp"
#include "object/atomic_object.h"
#include "utils/singleton.hpp"

namespace _MEM_POOL_ {
    class StringObjectPool final
    {
    private:
        virtual ~StringObjectPool() {
            delete first_block;
        }
        StringObjectPool();
        StringObjectPool(const StringObjectPool&) = default;
        StringObjectPool& operator=(const StringObjectPool&) = default;
    public:
        static StringObjectPool* GetInstance() {
            static StringObjectPool instance;
            return &instance;
        }

        StringObject* CreateStringObject(const char* val);

        void Recycle(StringObject* ptr);

        StringObject* GetTemplate();
    private:
        StringObject m_template;
        StringObject* free_num_cursor;
        MemoryBlock<StringObject>* first_block;

    };

} // !namespace _MEM_POOL_