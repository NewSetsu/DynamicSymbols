#include "struct_template.h"
#include "mem_pool/mem_pool.hpp"

StructObject INNER_STRUCT::PositionStruct()
{
    StructObject ans;
    auto dbl_x = _MEM_POOL_::DoubleObjectPool::GetInstance()->CreateDoubleObject(0.0);
    auto dbl_y = _MEM_POOL_::DoubleObjectPool::GetInstance()->CreateDoubleObject(0.0);
    auto dbl_z = _MEM_POOL_::DoubleObjectPool::GetInstance()->CreateDoubleObject(0.0);
    ans.AddMember(dbl_x, "X");
    ans.AddMember(dbl_y, "Y");
    ans.AddMember(dbl_z, "Z");
    ans.SetTemplateType("POSITION");
    return ans;
}

StructObject INNER_STRUCT::OrientStruct()
{
    StructObject ans;
    auto dbl_1 = _MEM_POOL_::DoubleObjectPool::GetInstance()->CreateDoubleObject(0.0);
    auto dbl_2 = _MEM_POOL_::DoubleObjectPool::GetInstance()->CreateDoubleObject(0.0);
    auto dbl_3 = _MEM_POOL_::DoubleObjectPool::GetInstance()->CreateDoubleObject(0.0);
    auto dbl_4 = _MEM_POOL_::DoubleObjectPool::GetInstance()->CreateDoubleObject(0.0);
    ans.AddMember(dbl_1, "Q1");
    ans.AddMember(dbl_2, "Q2");
    ans.AddMember(dbl_3, "Q3");
    ans.AddMember(dbl_4, "Q4");
    ans.SetTemplateType("ORIENT");
    return ans;
}

StructObject INNER_STRUCT::ConfdataStruct()
{
    StructObject ans;
    auto int_1 = _MEM_POOL_::IntObjectPool::GetInstance()->CreateIntObject(0);
    auto int_2 = _MEM_POOL_::IntObjectPool::GetInstance()->CreateIntObject(0);
    auto int_3 = _MEM_POOL_::IntObjectPool::GetInstance()->CreateIntObject(0);
    auto int_4 = _MEM_POOL_::IntObjectPool::GetInstance()->CreateIntObject(0);
    ans.AddMember(int_1, "CF1");
    ans.AddMember(int_2, "CF2");
    ans.AddMember(int_3, "CF3");
    ans.AddMember(int_4, "CF4");
    ans.SetTemplateType("CONFDATA");
    return ans;
}
