#pragma once

#include "basic_def/basic_def.h"


enum class STRUCT_TYPE : unsigned short
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
    ClassBase() : next_in_pool(nullptr)
    {

    }
    virtual ~ClassBase() {};

    // 输出自己的信息，结构未定
    virtual std::string ClassInfo() = 0;

    virtual const STRUCT_TYPE StructType() = 0;

    virtual const std::string& VarType() const = 0;

    // 内存池中的下一个对象
    ClassBase* next_in_pool;

};