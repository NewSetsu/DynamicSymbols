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
    return this;
}

const VarBase* StringObject::VarTemplate()
{
    return _MEM_POOL_::StringObjectPool::GetInstance()->GetTemplate();
}

VarBase* StringObject::VarCopy()
{
    return _MEM_POOL_::StringObjectPool::GetInstance()->CreateStringObject(m_str.c_str());
}

const bool StringObject::Erase()
{
    _MEM_POOL_::StringObjectPool::GetInstance()->Recycle(this);
    return true;
}

const std::string& StringObject::VarType() const
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

VarBase* StringObject::VarAssign(VarBase* right)
{
    if (!this->CheckType(right))
        return nullptr;

    this->m_str = right->GetStrVar();
    return this;
}

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
