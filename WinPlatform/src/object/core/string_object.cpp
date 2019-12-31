#include "string_object.h"
#include "basic_def/var_type.hpp"
#include "utils/transfer_check.hpp"
#include "mem_pool/mem_pool.hpp"

StringObject::StringObject() : m_str("")
{

}

StringObject::~StringObject()
{
    // do nothing
}

std::string StringObject::ClassInfo()
{
    return std::string("IntObject, Var: ") + m_str + "\r\n";
}

VarBase* StringObject::VarRef()
{
    m_use_cnt++;
    return this;
}

const bool StringObject::Erase()
{
    --m_use_cnt;
    if (m_use_cnt == 0)
    {
        _MEM_POOL_::StringObjectPool::GetInstance()->Recycle(this);
    }
    return true;
}

const std::string& StringObject::VarType()
{
    return ATOMIC_TYPES::STRING_TYPE;
}

const bool StringObject::CheckType(VarBase* other)
{
    return TransferCheck::GetInstance()->TypeCheck(
        this->VarType(), other->VarType()
    );
}

const bool StringObject::IsEqual(VarBase* other)
{
    // 类型不匹配，不比较
    if (!this->CheckType(other))
        return false;

    return m_str == other->GetStrVar();
}

//VarBase* StringObject::VarAssign(VarBase* right)
//{
//    if (!this->CheckType(right))
//        return nullptr;
//
//    this->Erase();
//    return right->VarRef();
//}

VarBase* StringObject::OP_Add(VarBase* right)
{
    if (!this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::StringObjectPool::GetInstance()->CreateStringObject(
        std::string(m_str + right->GetStrVar()).c_str()
    );
}

VarBase* StringObject::OP_Ge(VarBase* right)
{
    if (!this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(
        m_str >= right->GetStrVar()
    );
}

VarBase* StringObject::OP_Gr(VarBase* right)
{
    if (!this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(
        m_str > right->GetStrVar()
    );
}

VarBase* StringObject::OP_low(VarBase* right)
{
    if (!this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(
        m_str < right->GetStrVar()
    );
}

VarBase* StringObject::OP_le(VarBase* right)
{
    if (!this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(
        m_str <= right->GetStrVar()
    );
}

VarBase* StringObject::OP_Equ(VarBase* right)
{
    if (!this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(
        m_str == right->GetStrVar()
    );
}

VarBase* StringObject::OP_Neq(VarBase* right)
{
    if (!this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(
        m_str != right->GetStrVar()
    );
}
