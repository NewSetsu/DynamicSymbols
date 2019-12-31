#include "array_object.h"
#include "utils/transfer_check.hpp"

std::string ArrayObject::ClassInfo()
{
    std::string ans = "ArrayObject type: ";
    ans += m_type + " , size: " + std::to_string(m_array.size());
    return ans;
}

VarBase* ArrayObject::VarRef()
{
    return this;
}

//VarBase* ArrayObject::VarInstance()
//{
//    return nullptr;
//}

const bool ArrayObject::Erase()
{
    // 从数组管理器中回收
    return false;
}

const std::string& ArrayObject::VarType() const
{
    return m_type;
}

const bool ArrayObject::CheckType(VarBase* other)
{
    return TransferCheck::GetInstance()->TypeCheck(this->VarType(), other->VarType());
}

void ArrayObject::Reset()
{
    for (auto& itor : m_array)
        itor->Erase();
    m_array.clear();
}

const bool ArrayObject::MakeInstance(const ArrayObject* source)
{
    m_type = source->VarType();
    
    for (auto& itor : source->m_array)
    {
        if (nullptr == itor)
            return false;

        m_array.push_back(itor->VarCopy());
    }

    return false;
}

const uint32_t ArrayObject::GetVecSize() const
{
    return static_cast<uint32_t>(m_array.size());
}

const uint32_t ArrayObject::GetCapacity() const
{
    return static_cast<uint32_t>(m_array.capacity());
}

const uint32_t ArrayObject::AppendArr(VarBase* _unit)
{
    m_array.push_back(_unit);
    return static_cast<uint32_t>(m_array.size());
}

const bool ArrayObject::EraseUnit(const uint32_t _num, const bool is_check)
{
    return false;
}

VarBase* ArrayObject::GetArrUnit(const uint32_t num)
{
    return m_array[num];
}

const bool ArrayObject::SetArrUnit(VarBase* unit, const bool is_check)
{
    for (int i = 0; i < m_array.size(); i++)
    {
        if (m_array[i] == unit)
        {
            if (is_check)
                return true;
            m_array[i] = unit;
            return true;
        }
    }

    return false;
}
