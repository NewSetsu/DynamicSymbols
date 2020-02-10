#pragma once
#include "mem_block.hpp"
#include "object/atomic_object.h"

namespace _MEM_POOL_ {
    int GetBoolArrID();
    int GetByteArrID();
    int GetIntArrID();
    int GetDoubleArrID();
    int GetStringArrID();
    
    /*!
     * \class   ArrayPool
     * \author  chengx
     * \date    2020.1.2
     * \brief   数组池，提供注册新数组类型 和 创建数组类型接口
     *          使用流程:
     *          1. 确定数组的组成元素是什么类型(VarBase指针)
     *          2. 在数组池中注册该类型数组，获得唯一id(RegAnArray)
     *          3. 创建数组对象(CreateNewArray)
     */
    class ArrayPool final
    {
    private:
        ArrayPool();
        virtual ~ArrayPool();
        ArrayPool(const ArrayPool&) = default;
        ArrayPool& operator=(const ArrayPool&) = default;
    public:
        static ArrayPool* GetInstance() {
            static ArrayPool instance;
            return &instance;
        }

        // 创建某个对象的数组
        ArrayObject* CreateNewArray(const int arr_id);

        // 回收数组
        void Recycle(ArrayObject* ptr);

        // 注册一个数组类型
        const int RegAnArray(VarBase* sub_unit);

        // 获得数组模板
        VarBase* GetTemplate(const int arr_id);
    private:

    private:
        ArrayObject* free_num_cursor;
        MemoryBlock<ArrayObject>* first_block;

        std::vector<ArrayObject> m_array_template;
    };
}; // ! _MEM_POOL_
