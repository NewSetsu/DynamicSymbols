#pragma once

#include "mem_block.hpp"
#include "object/atomic_object.h"
#include "utils/singleton.hpp"

namespace _MEM_POOL_ {

    /*
     * \brief   bool类型内存池，好像可以只存两个数据
     * \note    暂时先做成大内存池，后续考虑只有两个数据
     */
    class BoolObjectPool final
    {
    private:
        BoolObjectPool();
        virtual ~BoolObjectPool() {
            delete first_block;
        }
        BoolObjectPool(const BoolObjectPool&) = default;
        BoolObjectPool& operator=(const BoolObjectPool&) = default;
    public:
        static BoolObjectPool* GetInstance() {
            static BoolObjectPool instance;
            return &instance;
        }

        BoolObject* CreateBoolObject(const bool val);

        void Recycle(BoolObject* ptr);

        BoolObject* GetTemplate();

    private:
        BoolObject m_template;
        BoolObject* free_num_cursor;
        MemoryBlock<BoolObject>* first_block;
    };

}   // !namespace _MEM_POOL_