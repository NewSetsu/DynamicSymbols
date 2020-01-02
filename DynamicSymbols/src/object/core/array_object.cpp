#include "array_object.h"
#include "utils/transfer_check.hpp"
#include "mem_pool/mem_pool.hpp"

ArrayObject::ArrayObject() :
    m_temp_id(-1),
    m_template_ptr(nullptr)
{

}

void ArrayObject::CreateArrayTemplate(VarBase* sub_unit_ptr, const int arr_id)
{
    m_template_ptr = const_cast<VarBase*>(sub_unit_ptr->VarTemplate());
    m_type = sub_unit_ptr->VarType() + "'s Array \r\n";
    m_temp_id = arr_id;
}

void ArrayObject::InitByTemplate(ArrayObject* arr_temp)
{
    m_temp_id = arr_temp->m_temp_id;
    m_template_ptr = arr_temp->m_template_ptr;
    m_type = arr_temp->m_type;
}

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

VarBase* ArrayObject::VarCopy()
{
    auto ans = _MEM_POOL_::ArrayPool::GetInstance()->CreateNewArray(m_temp_id);
    for (auto& itor : m_array)
    {
        ans->PushBack(itor);
    }
    return ans;
}

const VarBase* ArrayObject::VarTemplate()
{
    return _MEM_POOL_::ArrayPool::GetInstance()->GetTemplate(m_temp_id);
}

//VarBase* ArrayObject::VarInstance()
//{
//    return nullptr;
//}

const bool ArrayObject::Erase()
{
    // 从数组管理器中回收
    _MEM_POOL_::ArrayPool::GetInstance()->Recycle(this);
    return true;
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

const uint32_t ArrayObject::PushBack(VarBase* _unit)
{
    if (m_template_ptr == _unit->VarTemplate())
        m_array.push_back(_unit->VarCopy());
    else
    {
        // 输出错误
    }
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
