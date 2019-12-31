#include "description.hpp"
#include "var_base.hpp"
//
//ArrayDescrip::ArrayDescrip(std::string& type) : m_type(type)
//{
//}
//
//ArrayDescrip::~ArrayDescrip()
//{
//    for (auto itor : m_array)
//    {
//        itor->Erase();
//    }
//}
//
//std::string ArrayDescrip::ClassInfo()
//{
//    return m_type + " array, size: " + std::to_string(m_array.size()) + "\r\n";
//}
//
//const bool ArrayDescrip::AppendArray(VarBase* unit)
//{
//    m_array.push_back(unit->VarRef());
//    return true;
//}
//
//VarBase* ArrayDescrip::GetUnit(const uint32_t num)
//{
//    if (num < m_array.size())
//        return m_array[num];
//
//    return nullptr;
//}
//
//const bool ArrayDescrip::EraseUnit(const uint32_t num)
//{
//    if (num >= m_array.size())
//        return false;
//
//    m_array[num]->Erase();
//    m_array.erase(m_array.begin() + num);
//    return true;
//}
//
//DynamicDescrip::DynamicDescrip(std::string& type) : m_type(type)
//{
//
//}
//
//DynamicDescrip::~DynamicDescrip()
//{
//    for (auto& itor : m_members)
//    {
//        itor.second->Erase();
//    }
//}
//
//std::string DynamicDescrip::ClassInfo()
//{
//    return std::string();
//}
//
//const bool DynamicDescrip::AddMember(std::string type_name, VarBase* member)
//{
//    if (type_name.empty() || nullptr != member)
//    {
//        // 错误的结构体语法
//        return false;
//    }
//    if (m_members.count(type_name) != 0)
//    {
//        // 重复的命名
//        return false;
//    }
//
//    m_members[type_name] = member->VarRef();
//    return true;
//}
//
//VarBase* DynamicDescrip::GetMember(const std::string type_name)
//{
//    if (m_members.count(type_name) != 0)
//        return m_members[type_name];
//    return nullptr;
//}
