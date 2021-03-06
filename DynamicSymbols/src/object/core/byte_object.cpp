﻿#include "byte_object.h"
#include "basic_def/var_type.hpp"
#include "utils/transfer_check.hpp"
#include "mem_pool/mem_pool.hpp"


ByteObject::ByteObject() : m_num(0)
{

}

ByteObject::~ByteObject()
{
    // do nothing
}

std::string ByteObject::ClassInfo()
{
    return std::string("ByteObject, Var: ") + std::to_string(m_num) + "\r\n";
}

VarBase* ByteObject::VarCopy()
{
    return _MEM_POOL_::ByteObjectPool::GetInstance()->CreateByteObject(m_num);
}

VarBase* ByteObject::VarRef()
{
    return this;
}

const VarBase* ByteObject::VarTemplate()
{
    return _MEM_POOL_::ByteObjectPool::GetInstance()->GetTemplate();
}

const bool ByteObject::Erase()
{
    _MEM_POOL_::ByteObjectPool::GetInstance()->Recycle(this);
    return true;
}

const std::string& ByteObject::VarType() const
{
    return ATOMIC_TYPES::BYTE_TYPE;
}

const bool ByteObject::CheckType(VarBase* other)
{
    return TransferCheck::GetInstance()->TypeCheck(
        this->VarType(), other->VarType()
    );
}

const bool ByteObject::IsEqual(VarBase* other)
{
    // 类型不匹配，不比较
    if (!this->CheckType(other))
        return false;

    return m_num == other->GetByteVar();
}

VarBase* ByteObject::VarAssign(VarBase* right)
{
    // 类型不匹配，不比较
    if (!this->CheckType(right))
        return nullptr;

    this->m_num = right->GetByteVar();
    return this;
}

VarBase* ByteObject::TransToBool()
{
    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(this->GetBoolVar());
}

VarBase* ByteObject::TransToByte()
{
    return this;
}

VarBase* ByteObject::TransToInt()
{
    return _MEM_POOL_::IntObjectPool::GetInstance()->CreateIntObject(this->GetIntVar());
}

VarBase* ByteObject::TransToDouble()
{
    return _MEM_POOL_::DoubleObjectPool::GetInstance()->CreateDoubleObject(this->GetDoublVar());
}

//VarBase* ByteObject::TransToString()
//{
//    return nullptr;
//}

VarBase* ByteObject::OP_Add(VarBase* right)
{
    if (!this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::ByteObjectPool::GetInstance()->CreateByteObject(
        static_cast<unsigned char>(m_num + right->GetByteVar())
    );
}

VarBase* ByteObject::OP_Sub(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::ByteObjectPool::GetInstance()->CreateByteObject(
        static_cast<unsigned char>(m_num - right->GetByteVar())
    );
}

VarBase* ByteObject::OP_Mul(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::ByteObjectPool::GetInstance()->CreateByteObject(
        static_cast<unsigned char>(m_num * right->GetByteVar())
    );
}

VarBase* ByteObject::OP_Div(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    if (right->GetByteVar() != 0)
    {
        return _MEM_POOL_::ByteObjectPool::GetInstance()->CreateByteObject(
            static_cast<unsigned char>(m_num / right->GetByteVar())
        );
    }

    // 报错机制？
    return nullptr;

}

VarBase* ByteObject::OP_Res(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    if (right->GetByteVar() != 0)
    {
        return _MEM_POOL_::ByteObjectPool::GetInstance()->CreateByteObject(
            static_cast<unsigned char>(m_num % right->GetByteVar())
        );
    }

    // 报错机制？
    return nullptr;
}

VarBase* ByteObject::OP_SelfAdd()
{
    this->Erase();
    return _MEM_POOL_::ByteObjectPool::GetInstance()->CreateByteObject(
        static_cast<unsigned char>(m_num + 1)
    );
}

VarBase* ByteObject::OP_SelfSub()
{
    this->Erase();
    return _MEM_POOL_::ByteObjectPool::GetInstance()->CreateByteObject(
        static_cast<unsigned char>(m_num - 1)
    );
}

VarBase* ByteObject::OP_Ge(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num >= right->GetByteVar());
}

VarBase* ByteObject::OP_Gr(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num > right->GetByteVar());
}

VarBase* ByteObject::OP_low(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num < right->GetByteVar());
}

VarBase* ByteObject::OP_le(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num <= right->GetByteVar());
}

VarBase* ByteObject::OP_Equ(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num == right->GetByteVar());
}

VarBase* ByteObject::OP_Neq(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num != right->GetByteVar());
}

VarBase* ByteObject::OP_Neg()
{
    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(!m_num);
}

VarBase* ByteObject::OP_Or(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num || right->GetByteVar());
}

VarBase* ByteObject::OP_And(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num && right->GetByteVar());
}
