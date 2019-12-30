#include "bool_object.h"
#include "basic_def/var_type.hpp"
#include "utils/transfer_check.hpp"
#include "mem_pool/mem_pool.hpp"

BoolObject::BoolObject() : m_num(false)
{

}

BoolObject::~BoolObject()
{
    // do nothing
}

std::string BoolObject::ClassInfo()
{
    return std::string("BoolObject, Var: ") + \
        (m_num ? "TRUE" : "FALSE") + "\r\n";
}

VarBase* BoolObject::VarRef()
{
    m_use_cnt++;
    return this;
}

const bool BoolObject::Erase()
{
    --m_use_cnt;
    if (m_use_cnt == 0)
    {
        _MEM_POOL_::BoolObjectPool::GetInstance()->Recycle(this);
    }
    return true;
}

const std::string& BoolObject::VarType()
{
    return ATOMIC_TYPES::BOOL_TYPE;
}

const bool BoolObject::CheckType(VarBase* other)
{
    return TransferCheck::GetInstance()->TypeCheck(
        this->VarType(), other->VarType()
    );
}

const bool BoolObject::IsEqual(VarBase* other)
{
    // 类型不匹配，不比较
    if (!this->CheckType(other))
        return false;

    return m_num == other->GetBoolVar();
}

VarBase* BoolObject::VarAssign(VarBase* right)
{
    // 类型不匹配，不比较
    if (!this->CheckType(right))
        return nullptr;

    this->Erase();
    return right->VarRef();
}

VarBase* BoolObject::TransToBool()
{
    return this;
}

VarBase* BoolObject::TransToByte()
{
    return _MEM_POOL_::ByteObjectPool::GetInstance()->CreateByteObject(this->GetByteVar());
}

VarBase* BoolObject::TransToInt()
{
    return _MEM_POOL_::IntObjectPool::GetInstance()->CreateIntObject(this->GetIntVar());
}

VarBase* BoolObject::TransToDouble()
{
    return _MEM_POOL_::DoubleObjectPool::GetInstance()->CreateDoubleObject(this->GetDoublVar());
}

VarBase* BoolObject::OP_Add(VarBase* right)
{
    if (!this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(
        m_num + right->GetBoolVar()
    );
}

VarBase* BoolObject::OP_Sub(VarBase* right)
{
    if (!this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(
        m_num - right->GetBoolVar()
    );
}

VarBase* BoolObject::OP_Mul(VarBase* right)
{
    if (!this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(
        m_num * right->GetBoolVar()
    );
}

VarBase* BoolObject::OP_Div(VarBase* right)
{
    if (!this->CheckType(right))
        return nullptr;

    if (right->GetBoolVar() != 0)
    {
        return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(
            m_num / right->GetBoolVar()
        );
    }

    // 报错机制？
    return nullptr;
}

VarBase* BoolObject::OP_Res(VarBase* right)
{
    if (!this->CheckType(right))
        return nullptr;

    if (right->GetBoolVar() != 0)
    {
        return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(
            m_num % right->GetBoolVar()
        );
    }

    // 报错机制？
    return nullptr;
}

VarBase* BoolObject::OP_SelfAdd()
{
    this->Erase();
    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num + 1);
}

VarBase* BoolObject::OP_SelfSub()
{
    this->Erase();
    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num - 1);
}

VarBase* BoolObject::OP_Ge(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num >= right->GetBoolVar());
}

VarBase* BoolObject::OP_Gr(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num > right->GetBoolVar());
}

VarBase* BoolObject::OP_low(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num < right->GetBoolVar());
}

VarBase* BoolObject::OP_le(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num < right->GetBoolVar());
}

VarBase* BoolObject::OP_Equ(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num == right->GetBoolVar());
}

VarBase* BoolObject::OP_Neq(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num != right->GetBoolVar());
}

VarBase* BoolObject::OP_Neg()
{
    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(!m_num);
}

VarBase* BoolObject::OP_Or(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num || right->GetBoolVar());
}

VarBase* BoolObject::OP_And(VarBase* right)
{
    if (this->CheckType(right))
        return nullptr;

    return _MEM_POOL_::BoolObjectPool::GetInstance()->CreateBoolObject(m_num && right->GetBoolVar());
}
