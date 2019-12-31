#include "struct_object.h"
#include "utils/transfer_check.hpp"
#include "instance/struct_pool.hpp"

const bool StructObject::SetTemplateType(std::string type)
{
    m_type = type;
    return true;
}

std::string StructObject::ClassInfo()
{
    auto info = std::string("Struct: ") + m_type + "\r\n";
    for (auto& itor : m_members)
        info += "   " + itor.first + " : " + itor.second->ClassInfo();
    return info;
}

VarBase* StructObject::VarRef()
{
    return this;
}

VarBase* StructObject::VarCopy()
{
    // 从内存池中实例化一个
    return _MEM_POOL_::DynamicPool::GetInstance()->CreateStructObject(m_type);
}

//VarBase* StructObject::VarInstance()
//{
//    
//}

const bool StructObject::Erase()
{
    for (auto& itor : m_members)
        itor.second->Erase();

    _MEM_POOL_::DynamicPool::GetInstance()->Recycle(this);
    return true;
}

const std::string& StructObject::VarType() const
{
    return m_type;
}

const bool StructObject::CheckType(VarBase* other)
{
    return TransferCheck::GetInstance()->TypeCheck(m_type, other->VarType());
}

void StructObject::Reset()
{
    for (auto& itor : m_members)
    {
        itor.second->Reset();
    }
}

const bool StructObject::MakeInstance(const StructObject* source)
{
    // warning 这给了Struct改变type的能力
    // 变量类型应该交给模板管理器管理
    m_type = source->VarType();

    for (auto& itor : source->m_members)
    {
        if (nullptr == itor.second)
            return false;
        m_members[itor.first] = itor.second->VarInstance();
        m_members[itor.first]->m_holder = this;
    }
    return true;
}

const bool StructObject::AddMember(VarBase* new_member, std::string member_name)
{
    if (new_member == nullptr)
        return false;

    // 变量名检测
    // 检测不通过也false

    m_members.insert(std::make_pair(member_name, new_member));
    return true;
}

VarBase* StructObject::GetMember(std::string& sub_type)
{
    if (m_members.count(sub_type) != 0)
        return m_members[sub_type];

    return nullptr;
}

const bool StructObject::SetMembers(VarBase* member, VarBase* value, const bool is_check)
{
    for (auto& itor : m_members)
    {
        if (itor.second == member)
        {
            // 检查阶段直接返回true，不进行实际操作
            if (is_check)
                return true;
            itor.second->Erase();
            itor.second = value->VarRef();
            return true;
        }
    }
    return false;
}