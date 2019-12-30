#pragma once

#include "basic_def/basic_def.h"


enum STRUCT_TYPE : unsigned char
{
    NULL_TYPE = 0,  // VarBase专属类型
    ATOMIC,         // 元子类型 int, byte, double, bool, string
    ARRAY,          // 数组
    DYNAMIC,        // 结构体
};

/*!
 * \class   ClassBase
 * \brief   纯虚基类，限定子类必须提供的接口
 * \author  chengx
 * \date    2019.12.24
 */
struct ClassBase
{
public:
    ClassBase() : 
        m_use_cnt(0)
    {

    }
    virtual ~ClassBase() {};

    // 输出自己的信息，结构未定
    virtual std::string ClassInfo() = 0;

    virtual const STRUCT_TYPE StructType() = 0;

    virtual const std::string& VarType() = 0;

    virtual void Reset() = 0;

    // 内存池中的下一个对象
    ClassBase* next_in_pool = nullptr;

    // 引用计数，方便内存池管理
    unsigned int m_use_cnt;

};