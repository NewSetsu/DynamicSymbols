#include "instance.hpp"
#include "struct_template.h"
#include "struct_pool.hpp"

std::vector<std::string> RL_Template::GetAllTemplate()
{
    std::vector<std::string> ans;

    for (auto& itor : m_struct_template)
        ans.push_back(itor.second.VarType());

    return ans;
}

const bool RL_Template::InitTemplate()
{
    // 基本结构体
    this->AddTemplate(INNER_STRUCT::PositionStruct());
    this->AddTemplate(INNER_STRUCT::OrientStruct());
    this->AddTemplate(INNER_STRUCT::ConfdataStruct());

    // 高级结构体
    this->AddTemplate(INNER_STRUCT::PoseStruct());
    return true;
}

RL_Template::RL_Template()
{
    // 依次记录内建结构体的模板

}

RL_Template::~RL_Template()
{
    // do nothing
}

const bool RL_Template::TypeExist(std::string type)
{
    return m_struct_template.count(type) != 0;
}

const bool RL_Template::AddTemplate(StructObject&& struct_template)
{
    // 模板不能重名
    if (TypeExist(struct_template.VarType()))
        return false;

    m_struct_template[struct_template.VarType()] = struct_template;

    _MEM_POOL_::DynamicPool::GetInstance()->NewStructPool(struct_template.VarType());

    return true;
}

StructObject* RL_Template::GetTemplate(std::string type)
{
    if (this->TypeExist(type))
        return &m_struct_template[type];

    return nullptr;
}