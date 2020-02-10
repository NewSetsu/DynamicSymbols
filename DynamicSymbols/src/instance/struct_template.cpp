#include "struct_template.h"
#include "mem_pool/mem_pool.hpp"
#include "instance.hpp"

StructObject INNER_STRUCT::PositionStruct()
{
    StructObject ans;
    auto dbl_x = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_y = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_z = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_arm = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    ans.AddMember(dbl_x, "X");
    ans.AddMember(dbl_y, "Y");
    ans.AddMember(dbl_z, "Z");
    ans.AddMember(dbl_arm, "ARM");
    ans.SetTemplateType("POSITION");
    return std::move(ans);
}

StructObject INNER_STRUCT::OrientStruct()
{
    StructObject ans;
    auto dbl_1 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_2 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_3 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_4 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    ans.AddMember(dbl_1, "Q1");
    ans.AddMember(dbl_2, "Q2");
    ans.AddMember(dbl_3, "Q3");
    ans.AddMember(dbl_4, "Q4");
    ans.SetTemplateType("ORIENT");
    return std::move(ans);
}

StructObject INNER_STRUCT::ClockStruct()
{
    StructObject ans;
    auto dbl_1 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_2 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_3 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    ans.AddMember(dbl_1, "TIMES");
    ans.AddMember(dbl_2, "CLKSTART");
    ans.AddMember(dbl_3, "CLKEND");
    ans.SetTemplateType("CLOCK");
    return std::move(ans);

}

StructObject INNER_STRUCT::ConfdataStruct()
{
    StructObject ans;
    auto int_1 = _MEM_POOL_::IntObjectPool::GetInstance()->GetTemplate();
    auto int_2 = _MEM_POOL_::IntObjectPool::GetInstance()->GetTemplate();
    auto int_3 = _MEM_POOL_::IntObjectPool::GetInstance()->GetTemplate();
    auto int_4 = _MEM_POOL_::IntObjectPool::GetInstance()->GetTemplate();
    ans.AddMember(int_1, "CF1");
    ans.AddMember(int_2, "CF4");
    ans.AddMember(int_3, "CF6");
    ans.AddMember(int_4, "CFX");
    ans.SetTemplateType("CONFDATA");
    return std::move(ans);
}

StructObject INNER_STRUCT::FcBoxVolStruct()
{
    StructObject ans;
    auto dbl_1 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_2 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_3 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_4 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_5 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_6 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();

    ans.AddMember(dbl_1, "XMIN");
    ans.AddMember(dbl_2, "XMAX");
    ans.AddMember(dbl_3, "YMIN");
    ans.AddMember(dbl_4, "YMAX");
    ans.AddMember(dbl_5, "ZMIN");
    ans.AddMember(dbl_6, "ZMAX");
    ans.SetTemplateType("FCBOXVOL");

    return std::move(ans);
}

StructObject INNER_STRUCT::FcCartNumVolStruct()
{
    StructObject ans;
    auto dbl_1 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_2 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_3 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_4 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_5 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_6 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();

    ans.AddMember(dbl_1, "NUM1");
    ans.AddMember(dbl_2, "NUM2");
    ans.AddMember(dbl_3, "NUM3");
    ans.AddMember(dbl_4, "NUM4");
    ans.AddMember(dbl_5, "NUM5");
    ans.AddMember(dbl_6, "NUM6");
    ans.SetTemplateType("FCCARTNUMVOL");

    return std::move(ans);
}

StructObject INNER_STRUCT::FcCylinderVolStruct()
{
    StructObject ans;
    auto dbl_1 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_2 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_3 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_4 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_5 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();

    ans.AddMember(dbl_1, "XCBOTTOM");
    ans.AddMember(dbl_2, "YCBOTTOM");
    ans.AddMember(dbl_3, "ZCBOTTOM");
    ans.AddMember(dbl_4, "HEIGHT");
    ans.AddMember(dbl_5, "RADIUS");
    ans.SetTemplateType("FCCYLINDERVOL");

    return std::move(ans);
}

StructObject INNER_STRUCT::FcSphereVolVolStruct()
{
    StructObject ans;
    auto dbl_1 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_2 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_3 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_4 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();

    ans.AddMember(dbl_1, "XC");
    ans.AddMember(dbl_2, "YC");
    ans.AddMember(dbl_3, "ZC");
    ans.AddMember(dbl_4, "RADIUS");
    ans.SetTemplateType("FCSPHEREVOL");

    return std::move(ans);
}

StructObject INNER_STRUCT::FcXyzNumVolStruct()
{
    StructObject ans;
    auto dbl_1 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_2 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    auto dbl_3 = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();

    ans.AddMember(dbl_1, "X");
    ans.AddMember(dbl_2, "Y");
    ans.AddMember(dbl_3, "Z");
    ans.SetTemplateType("FCXYZNUMVOL");

    return std::move(ans);
}

StructObject INNER_STRUCT::IntNumStruct()
{
    StructObject ans;
    auto bool_1 = _MEM_POOL_::BoolObjectPool::GetInstance()->GetTemplate();
    auto bool_2 = _MEM_POOL_::BoolObjectPool::GetInstance()->GetTemplate();
    auto bool_3 = _MEM_POOL_::BoolObjectPool::GetInstance()->GetTemplate();
    auto str_1 = _MEM_POOL_::StringObjectPool::GetInstance()->GetTemplate();

    ans.AddMember(bool_1, "SINGLE");            // 单次触发或循环触发
    ans.AddMember(bool_2, "SAFE");              // 单次且安全
    ans.AddMember(bool_3, "SIG_EFFECT_VALUE");  // 有效电平
    ans.AddMember(str_1, "DI_NAME");            // DI的名字

    ans.SetTemplateType("INTNUM");

    return std::move(ans);
}

StructObject INNER_STRUCT::LoadStruct()
{
    StructObject ans;
    auto dbl_template = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();

    ans.AddMember(dbl_template, "MASS");
    ans.AddMember(dbl_template, "COGX");
    ans.AddMember(dbl_template, "COGY");
    ans.AddMember(dbl_template, "COGZ");
    ans.AddMember(dbl_template, "Q1");
    ans.AddMember(dbl_template, "Q2");
    ans.AddMember(dbl_template, "Q3");
    ans.AddMember(dbl_template, "Q4");

    ans.SetTemplateType("LOAD");

    return std::move(ans);
}

StructObject INNER_STRUCT::PoseStruct()
{
    StructObject ans;
    auto dbl_template = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    ans.AddMember(dbl_template, "X");
    ans.AddMember(dbl_template, "Y");
    ans.AddMember(dbl_template, "Z");
    ans.AddMember(dbl_template, "Q1");
    ans.AddMember(dbl_template, "Q2");
    ans.AddMember(dbl_template, "Q3");
    ans.AddMember(dbl_template, "Q4");

    ans.SetTemplateType("POSE");
    return std::move(ans);
}

StructObject INNER_STRUCT::SignalStruct()
{
    
}

StructObject INNER_STRUCT::SpeedStruct()
{
    StructObject ans;
    auto dbl_template = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();
    ans.AddMember(dbl_template, "PER");
    ans.AddMember(dbl_template, "TCP");
    ans.AddMember(dbl_template, "ORI");
    ans.AddMember(dbl_template, "EXJ_L");
    ans.AddMember(dbl_template, "EXJ_R");

    ans.SetTemplateType("SPEED");
    return std::move(ans);
}


StructObject INNER_STRUCT::JointTargetStruct()
{
    StructObject ans;
    auto dbl_arr_1 = _MEM_POOL_::ArrayPool::GetInstance()->GetTemplate(_MEM_POOL_::GetDoubleArrID());
    auto dbl_arr_2 = _MEM_POOL_::ArrayPool::GetInstance()->GetTemplate(_MEM_POOL_::GetDoubleArrID());

    ans.AddMember(dbl_arr_1, "ROBOT_AXES");
    ans.AddMember(dbl_arr_2, "EXTER_AXES");

    ans.SetTemplateType("INTNUM");

    return std::move(ans);
}

StructObject INNER_STRUCT::RobTargetStruct()
{
    StructObject ans;
    auto position = RL_Template::GetInstance()->GetTemplate("POSITION");
    auto orient = RL_Template::GetInstance()->GetTemplate("ORIENT");
    auto confdata = RL_Template::GetInstance()->GetTemplate("CONFDATA");
    auto extax = _MEM_POOL_::ArrayPool::GetInstance()->GetTemplate(_MEM_POOL_::GetIntArrID());

    ans.AddMember(position, "TRANS");
    ans.AddMember(orient, "ROT");
    ans.AddMember(confdata, "CONF");
    ans.AddMember(extax, "EXTAX");
    ans.SetTemplateType("ROBTARGET");
    return std::move(ans);
}

StructObject INNER_STRUCT::SyncidentStruct()
{
    StructObject ans;
    auto str_arr = _MEM_POOL_::ArrayPool::GetInstance()->GetTemplate(_MEM_POOL_::GetStringArrID());
    ans.AddMember(str_arr, "WAIT_TASKS");
    ans.SetTemplateType("SYNCIDENT");
    return std::move(ans);
}

StructObject INNER_STRUCT::TasksStruct()
{
    StructObject ans;
    auto str_arr = _MEM_POOL_::ArrayPool::GetInstance()->GetTemplate(_MEM_POOL_::GetStringArrID());
    ans.AddMember(str_arr, "WAIT_TASKS");
    ans.SetTemplateType("TASKS");
    return std::move(ans);
}

StructObject INNER_STRUCT::ToolStruct()
{
    StructObject ans;
    auto bool_template = _MEM_POOL_::BoolObjectPool::GetInstance()->GetTemplate();
    auto pose_template = RL_Template::GetInstance()->GetTemplate("POSE");
    auto load_template = RL_Template::GetInstance()->GetTemplate("LOAD");

    ans.AddMember(bool_template, "ROBHOLD");
    ans.AddMember(pose_template, "TFRAME");
    ans.AddMember(load_template, "TLOAD");
    ans.SetTemplateType("TOOL");
    return std::move(ans);
}

StructObject INNER_STRUCT::TriggDataStruct()
{
    StructObject ans;
    auto bool_template = _MEM_POOL_::BoolObjectPool::GetInstance()->GetTemplate();
    auto double_template = _MEM_POOL_::DoubleObjectPool::GetInstance()->GetTemplate();


}

