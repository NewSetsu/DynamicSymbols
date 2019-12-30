#pragma once

#include "struct_block.hpp"
#include "object/atomic_object.h"
#include "utils/singleton.hpp"



namespace _MEM_POOL_ {
    class StructObjectPool;
    
    class DynamicPool : public utils::SingletonBase<DynamicPool>
    {
        friend class SingletonBase<DynamicPool>;
    public:
        const bool NewStructPool(std::string& type_name);

        StructObject* CreateStructObject(std::string& type_name);

        void Recycle(StructObject* ptr);

    private:
        DynamicPool();

        virtual ~DynamicPool();

    private:
        std::map<std::string, StructObjectPool*> all_struct_pool;
    };

    /******************************************************************************
    * 结构体内存池，其结构和用法与基本变量的内存池几乎一样
    * 唯一的差别是它不是单例模式，因为不能确定动态语言究竟有多少种结构体
    * 所有的结构体内存池将由一个管理器管理
    *******************************************************************************/
    class StructObjectPool
    {
    public:
        StructObjectPool(std::string &type_name);

        virtual ~StructObjectPool();

        // 暂时先用纯默认的，之后再添加数组作为参数
        StructObject* CreateStructObject();

        void Recycle(StructObject* ptr);
    private:
        StructBlock* first_block;
        StructObject* free_cursor;
        std::string m_type_name;
    };

} // ! _MEM_POOL_