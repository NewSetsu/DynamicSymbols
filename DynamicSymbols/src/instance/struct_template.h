#pragma once

#include "object/atomic_object.h"

namespace INNER_STRUCT {
    /*****************************************************************
    *           基本元素组成的结构体
    ******************************************************************/

    // CLOCK
    // double type member: TIMES, CLKSTART, CLKEND
    StructObject ClockStruct();         

    // CONFDATA
    // int type member: CF1, CF4, CF6, CFX
    StructObject ConfdataStruct();      

    // FcBoxVol
    // double type member: XMAX, XMIN, YMAX, YMIN, ZMAX, ZMIN
    StructObject FcBoxVolStruct();      

    // FcCartNum
    // double type member: NUM1 ~ NUM6
    StructObject FcCartNumVolStruct();  

    // FcCylinder
    // double type member: X|Y|Z_CBOTOOM, HEIGHT, RADIUS
    StructObject FcCylinderVolStruct(); 

    // FcSphereVol
    // double type member: XC, YC, ZC
    StructObject FcSphereVolVolStruct();

    // FcXyzNum
    // double type member: X, Y, Z
    StructObject FcXyzNumVolStruct();   

    // IntNum
    // bool type member:    SINGLE  单次 or 循环触发
    //                      SAFE    单次且安全模式
    //                      SIG_EFFECT_VALUE 有效电平
    // string type member:  DI_NAME DI的名字
    StructObject IntNumStruct();        

    // Load
    // double type member: mass, cogx|y|z, q1~q4
    StructObject LoadStruct();          // Load

    // ORI
    // member: Q1, Q2, Q3, Q4
    StructObject OrientStruct();

    // POS
    // member: X, Y, Z, ARM
    StructObject PositionStruct();

    // POSE
    // member: X, Y, Z, Q1~Q4
    StructObject PoseStruct();

    // Signal
    // member: bool, int, double 一个信号变量的值可能是三种类型之一
    // member: str type 表明一个信号变量的类型 DI DO GI GO AI AO
    StructObject SignalStruct();

    // SPEED
    // member: PER, TCP, ORI, EXJ_L, EXJ_R
    StructObject SpeedStruct();

    /*************************************************************
    *               高级结构体,由其他结构体组成
    /*************************************************************/
    // JointTarget
    // double 一维数组  ROBOT_AXES, EXTER_AXES
    StructObject JointTargetStruct();   

    // RobTarget
    // POSITION type: trans 坐标
    // ORI type     : rot   姿态角
    // CONFDATA type: conf  位形配置
    // double一维数组 extax 外部轴
    StructObject RobTargetStruct();

    // Syncident
    // STR一维数组 : WAIT_TASKS 等待同步的任务
    StructObject SyncidentStruct();

    // Tasks
    // STR一维数组 : WAIT_TASKS 等待同步的任务
    StructObject TasksStruct();

    // Tool
    // bool type    : robhold   夹具是否安装
    // pose type    : tframe    工具坐标系
    // load type    : tload     工具动力学参数
    StructObject ToolStruct();

    // Triggdata
    // double type  :   distance    距离|时间
    // bool type    :   timeflag, startflag, trigglevel
    // do | go | ao :   output      触发的输出类型，目前应该支持DO GO
    StructObject TriggDataStruct();

} // ! INNER_STRUCT