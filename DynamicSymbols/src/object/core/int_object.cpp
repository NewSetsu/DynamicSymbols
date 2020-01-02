#include "int_object.h"
#include "basic_def/var_type.hpp"
#include "utils/transfer_check.hpp"
#include "mem_pool/mem_pool.hpp"

IntObject::IntObject() : m_num(0) 
{

}

IntObject::~IntObject() 
{
    // do nothing
}

std::string IntObject::ClassInfo()
{
    return std::string("IntObject, Var: ") + std::to_string(m_num) + "\r\n";
}

VarBase* IntObject::VarCopy()
{
    return _MEM_POOL_::IntObjectPool::GetInstance()->CreateIntObject(m_num);
}

VarBase* IntObject::VarRef()
{
    return this;
}

const VarBase* IntObject::VarTemplate()
{
    return _MEM_POOL_::IntObjectPool::GetInstance()->GetTemplate();
}

const bool IntObject::Erase()
{

    _MEM_POOL_::IntObjectPool::GetInstance()->Recycle(this);
    return true;
}

const std::string& IntObject::VarType() const
{
    return ATOMIC_TYPES::INTNUM_TYPE;
}

const bool IntObject::CheckType(VarBase* other)
{
    return TransferCheck::GetInstance()->TypeCheck(
        this->VarType(), other->VarType()
    );
}

const bool IntObject::IsEqual(VarBase* other)
{
    // 类型不匹配，不比较
    if (!this->CheckType(other))
        return false;

    return m_num == other->GetIntVar();
}

VarBase* IntObject::VarAssign(VarBase* right)
{
    // 类型不匹配，不比较
    if (!this->CheckType(right))
        return nullptr;

    this->m_num = right->GetIntVar();
    return this;
}

VarBase* IntObject::TransToBool()
{
    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(this->GetBoolVar());
}

VarBase* IntObject::TransToByte()
{
    return _MEM_POOL_::ByteObjectPool::GetInstance()->CreateByteObject(this->GetByteVar());
}

VarBase* IntObject::TransToInt()
{
    return this;
}

VarBase* IntObject::TransToDouble()
{
    return _MEM_POOL_::DoubleObjectPool::GetInstance()->CreateDoubleObject(this->GetDoublVar());
}

//VarBase* IntObject::TransToString()
//{
//    return nullptr;
//}

VarBase* IntObject::OP_Add(VarBase* right)
{
    if (!this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::IntObjectPool::GetInstance()->CreateIntObject(
        m_num + right->GetIntVar()
    );
}

VarBase* IntObject::OP_Sub(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::IntObjectPool::GetInstance()->CreateIntObject(
        m_num - right->GetIntVar()
    );
}

VarBase* IntObject::OP_Mul(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::IntObjectPool::GetInstance()->CreateIntObject(
        m_num * right->GetIntVar()
    );
}

VarBase* IntObject::OP_Div(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    if (right->GetIntVar() != 0)
    {
        return _MEM_POOL_::IntObjectPool::GetInstance()->CreateIntObject(
            m_num / right->GetIntVar()
        );
    }

    // 报错机制？
    return nullptr;
    
}

VarBase* IntObject::OP_Res(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    if (right->GetIntVar() != 0)
    {
        return _MEM_POOL_::IntObjectPool::GetInstance()->CreateIntObject(
            m_num % right->GetIntVar()
        );
    }

    // 报错机制？
    return nullptr;
}

VarBase* IntObject::OP_SelfAdd()
{
    this->Erase();
    return _MEM_POOL_::IntObjectPool::GetInstance()->CreateIntObject(m_num + 1);
}

VarBase* IntObject::OP_SelfSub()
{
    this->Erase();
    return _MEM_POOL_::IntObjectPool::GetInstance()->CreateIntObject(m_num - 1);
}

VarBase* IntObject::OP_Ge(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num >= right->GetIntVar());
}

VarBase* IntObject::OP_Gr(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num > right->GetIntVar());
}

VarBase* IntObject::OP_low(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num < right->GetIntVar());
}

VarBase* IntObject::OP_le(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num <= right->GetIntVar());
}

VarBase* IntObject::OP_Equ(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num == right->GetIntVar());
}

VarBase* IntObject::OP_Neq(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num != right->GetIntVar());
}

VarBase* IntObject::OP_Neg()
{
    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(!m_num);
}

VarBase* IntObject::OP_Or(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num || right->GetIntVar());
}

VarBase* IntObject::OP_And(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num && right->GetIntVar());
}
