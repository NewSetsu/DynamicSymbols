﻿#include "double_object.h"
#include "basic_def/var_type.hpp"
#include "utils/transfer_check.hpp"
#include "mem_pool/mem_pool.hpp"

DoubleObject::DoubleObject() : m_num(0)
{

}

DoubleObject::~DoubleObject()
{
    // do nothing
}

std::string DoubleObject::ClassInfo()
{
    return std::string("DoubleObject, Var: ") + std::to_string(m_num) + "\r\n";
}

VarBase* DoubleObject::VarCopy()
{
    return _MEM_POOL_::DoubleObjectPool::GetInstance()->CreateDoubleObject(m_num);
}

VarBase* DoubleObject::VarRef()
{
    return this;
}

const VarBase* DoubleObject::VarTemplate()
{
    return _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
}

const bool DoubleObject::Erase()
{
    return false;
}

const std::string& DoubleObject::VarType() const
{
    return ATOMIC_TYPES::DOUBLE_TYPE;
}

const bool DoubleObject::CheckType(VarBase* other)
{
    return TransferCheck::GetInstance()->TypeCheck(
        this->VarType(), other->VarType()
    );
}

const bool DoubleObject::IsEqual(VarBase* other)
{
    // 类型不匹配，不比较
    if (!this->CheckType(other))
        return false;

    return m_num == other->GetDoublVar();
}

VarBase* DoubleObject::VarAssign(VarBase* right)
{
    // 类型不匹配，不比较
    if (!this->CheckType(right))
        return nullptr;

    this->m_num = right->GetDoublVar();
    return this;
}

VarBase* DoubleObject::TransToBool()
{
    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(this->GetBoolVar());
}

VarBase* DoubleObject::TransToByte()
{
    return _MEM_POOL_::ByteObjectPool::GetInstance()->CreateByteObject(this->GetByteVar());
}

VarBase* DoubleObject::TransToInt()
{
    return _MEM_POOL_::IntObjectPool::GetInstance()->CreateIntObject(this->GetIntVar());
}

VarBase* DoubleObject::TransToDouble()
{
    return this;
}

//VarBase* DoubleObject::TransToString()
//{
//    return nullptr;
//}

VarBase* DoubleObject::OP_Add(VarBase* right)
{
    if (!this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::DoubleObjectPool::GetInstance()->CreateDoubleObject(
        m_num + right->GetDoublVar()
    );
}

VarBase* DoubleObject::OP_Sub(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::DoubleObjectPool::GetInstance()->CreateDoubleObject(
        m_num - right->GetDoublVar()
    );
}

VarBase* DoubleObject::OP_Mul(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::DoubleObjectPool::GetInstance()->CreateDoubleObject(
        m_num * right->GetDoublVar()
    );
}

VarBase* DoubleObject::OP_Div(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    if (right->GetDoublVar() != 0)
    {
        return _MEM_POOL_::DoubleObjectPool::GetInstance()->CreateDoubleObject(
            m_num / right->GetDoublVar()
        );
    }

    // 报错机制？
    return nullptr;

}

//VarBase* DoubleObject::OP_Res(VarBase* right)
//{
//    if (this->CheckType(right))
//        return nullptr;
//
//    if (right->GetIntVar() != 0)
//    {
//        return _MEM_POOL_::DoubleObjectPool::GetInstance()->CreateDoubleObject(
//            m_num % right->GetIntVar()
//        );
//    }
//
//    // 报错机制？
//    return nullptr;
//}

VarBase* DoubleObject::OP_SelfAdd()
{
    this->Erase();
    return _MEM_POOL_::DoubleObjectPool::GetInstance()->CreateDoubleObject(m_num + 1);
}

VarBase* DoubleObject::OP_SelfSub()
{
    this->Erase();
    return _MEM_POOL_::DoubleObjectPool::GetInstance()->CreateDoubleObject(m_num - 1);
}

VarBase* DoubleObject::OP_Ge(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num >= right->GetIntVar());
}

VarBase* DoubleObject::OP_Gr(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num > right->GetIntVar());
}

VarBase* DoubleObject::OP_low(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num < right->GetIntVar());
}

VarBase* DoubleObject::OP_le(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num <= right->GetIntVar());
}

VarBase* DoubleObject::OP_Equ(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num == right->GetIntVar());
}

VarBase* DoubleObject::OP_Neq(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num != right->GetIntVar());
}

VarBase* DoubleObject::OP_Neg()
{
    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(!m_num);
}

VarBase* DoubleObject::OP_Or(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num || right->GetIntVar());
}

VarBase* DoubleObject::OP_And(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num && right->GetIntVar());
}
