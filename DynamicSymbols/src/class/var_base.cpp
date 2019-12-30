#include "var_base.hpp"
#include "basic_def/var_type.hpp"

VarBase::VarBase()
{
    // todo 注意内存安全
    m_holder = nullptr;
}

VarBase::~VarBase()
{
    // todo 注意内存安全
}

const STRUCT_TYPE VarBase::StructType()
{
    return STRUCT_TYPE::NULL_TYPE;
}

//VarBase* VarBase::VarCopy()
//{
//    return nullptr;
//}

VarBase* VarBase::VarRef()
{
    return nullptr;
}

const bool VarBase::Erase()
{
    return false;
}

const std::string& VarBase::VarType()
{
    return ATOMIC_TYPES::EMPTY_TYPE;
}

const bool VarBase::CheckType(VarBase* other)
{
    return false;
}

const bool VarBase::IsEqual(VarBase* other)
{
    return false;
}

//VarBase* VarBase::VarAssign(VarBase* right)
//{
//    return nullptr;
//}

const bool VarBase::GetBoolVar()
{
    return false;
}

const unsigned char VarBase::GetByteVar()
{
    return 0;
}

const int VarBase::GetIntVar()
{
    return 0;
}

const double VarBase::GetDoublVar()
{
    return 0.0;
}

const std::string VarBase::GetStrVar()
{
    return std::string();
}

VarBase* VarBase::TransToBool()
{
    return nullptr;
}

VarBase* VarBase::TransToByte()
{
    return nullptr;
}

VarBase* VarBase::TransToInt()
{
    return nullptr;
}

VarBase* VarBase::TransToDouble()
{
    return nullptr;
}

VarBase* VarBase::TransToString()
{
    return nullptr;
}

VarBase* VarBase::OP_Add(VarBase* _right)
{
    return nullptr;
}

VarBase* VarBase::OP_Sub(VarBase* _right)
{
    return nullptr;
}

VarBase* VarBase::OP_Mul(VarBase* _right)
{
    return nullptr;
}

VarBase* VarBase::OP_Div(VarBase* _right)
{
    return nullptr;
}

VarBase* VarBase::OP_Res(VarBase* _right)
{
    return nullptr;
}

VarBase* VarBase::OP_SelfAdd()
{
    return nullptr;
}

VarBase* VarBase::OP_SelfSub()
{
    return nullptr;
}

VarBase* VarBase::OP_Ge(VarBase* _right)
{
    return nullptr;
}

VarBase* VarBase::OP_Gr(VarBase* _right)
{
    return nullptr;
}

VarBase* VarBase::OP_low(VarBase* _right)
{
    return nullptr;
}

VarBase* VarBase::OP_le(VarBase* _right)
{
    return nullptr;
}

VarBase* VarBase::OP_Equ(VarBase* _right)
{
    return nullptr;
}

VarBase* VarBase::OP_Neq(VarBase* _right)
{
    return nullptr;
}

VarBase* VarBase::OP_Neg()
{
    return nullptr;
}

VarBase* VarBase::OP_Or(VarBase* _right)
{
    return nullptr;
}

VarBase* VarBase::OP_And(VarBase* _right)
{
    return nullptr;
}

const uint32_t VarBase::GetVecSize() const
{
    return uint32_t();
}

const uint32_t VarBase::GetCapacity() const
{
    return uint32_t();
}

const uint32_t VarBase::GetUnitSize() const
{
    return uint32_t();
}

const uint32_t VarBase::AppendArr(VarBase* _unit)
{
    return uint32_t();
}

const bool VarBase::EraseUnit(const uint32_t _num)
{
    return false;
}

const bool VarBase::AddMember(VarBase* new_member, std::string member_name)
{
    return false;
}

VarBase* VarBase::GetMember(std::string& sub_type)
{
    return nullptr;
}

const bool VarBase::SetMembers(VarBase* member, VarBase* value)
{
    return false;
}
