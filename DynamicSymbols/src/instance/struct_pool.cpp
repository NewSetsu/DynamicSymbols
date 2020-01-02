#include "struct_pool.hpp"
#include "instance.hpp"
#include <iostream>

const bool _MEM_POOL_::DynamicPool::NewStructPool(std::string type_name)
{
    if (!RL_Template::GetInstance()->TypeExist(type_name))
        return false;

    auto new_pool = new StructObjectPool(type_name);
    all_struct_pool.insert(std::make_pair(type_name, std::move(new_pool)));

    return true;
}

StructObject* _MEM_POOL_::DynamicPool::CreateStructObject(std::string type_name)
{
    if (all_struct_pool.count(type_name) == 0)
        return nullptr;

    return all_struct_pool.at(type_name)->CreateStructObject();
}

void _MEM_POOL_::DynamicPool::Recycle(StructObject* ptr)
{
    // 此处应有错误机制
    if (all_struct_pool.count(ptr->VarType()) == 0)
        return;

    all_struct_pool.at(ptr->VarType())->Recycle(ptr);
}

//const bool _MEM_POOL_::DynamicPool::InitDynamicPool()
//{
//    auto template_vecs = RL_Template::GetInstance()->GetAllTemplate();
//
//    for (auto& itor : template_vecs)
//    {
//        auto new_pool = new StructObjectPool(itor);
//        //all_struct_pool.insert(std::make_pair(itor, std::move(new_pool)));
//        all_struct_pool.insert(std::make_pair(itor, std::move(new_pool)));
//    }
//
//    return false;
//}

_MEM_POOL_::DynamicPool::DynamicPool()
{

}

_MEM_POOL_::DynamicPool::~DynamicPool()
{
    while (!all_struct_pool.empty())
    {
        delete (*all_struct_pool.begin()).second;
        all_struct_pool.erase(all_struct_pool.begin());
    }
}

_MEM_POOL_::StructObjectPool::StructObjectPool(std::string& type_name)
{
    m_type_name = type_name;

    first_block = new StructBlock(type_name);
    first_block->next = nullptr;

    free_cursor = first_block->m_buf;
}

_MEM_POOL_::StructObjectPool::~StructObjectPool()
{
    if (first_block)
        delete first_block;
    first_block = nullptr;
}

StructObject* _MEM_POOL_::StructObjectPool::CreateStructObject()
{
    auto ans = free_cursor;
    free_cursor = static_cast<StructObject*>(free_cursor->next_in_pool);

    if (nullptr == free_cursor)
    {
        auto tmp_block = new StructBlock(m_type_name);
        tmp_block->next = first_block;
        first_block = tmp_block;
        free_cursor = first_block->m_buf;
    }

    return static_cast<StructObject*>(ans->VarRef());
}

void _MEM_POOL_::StructObjectPool::Recycle(StructObject* ptr)
{
    ptr->Reset();
    ptr->next_in_pool = free_cursor;
    free_cursor = ptr;
}
