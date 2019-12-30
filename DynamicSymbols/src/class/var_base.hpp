#pragma once

#include "base_class.hpp"
#include "description.hpp"

struct VarBase;

/*!
 * \class   VarBase
 * \brief   RL最基本变量，除了类型比较之外没有  !任何实际意义的函数!
 * \note1   若新的变量不需要基类方法，则不重载即可，但若调用了未重载的函数，系统会抛出异常
 * \note2   系统编写的VarBase系列，每个类型应该能够描述自己，而不是通过C代码来表达特征
 * \author chengx
 * \date 2019.12.17
 */
struct VarBase : public ClassBase
{
public:
    VarBase();
    virtual ~VarBase();
public:
    /*
     * @brief   返回class类型，目前分为 1:Atomic, 2:Array, 3:Struct, 0: no_type
     * @return
     * @param
     */
    virtual const STRUCT_TYPE StructType();

    /*
     * @brief   变量引用
     * @return  返回owner
     * @param   void
     */
    virtual VarBase* VarRef();

    /**
     * @brief   一个变量类型 实例化自己 (通过内存池 或者 模板管理器)
     * @return  实例化对象后的指针
     */
    virtual VarBase* VarInstance() { return this->VarRef(); }

    /*
     * @brief   RL语言层面的数据销毁，派生类应该在销毁后调用内存池的回收功能
     * @param   void
     */
    virtual const bool Erase();

    /*
     * @brief   变量类型
     * @return  str 要添加动态类型，不能使用枚举类型作为type
     * @param   void
     */
    virtual const std::string& VarType() override;

    /*
     * @brief   变量类型检测，检测通过两个变量才能进行运算
     * @return  bool 是否接受对方的类型(除了基本变量可以隐式转换，其他变量只接受同类型变量)
     */
    virtual const bool CheckType(VarBase *other);

    /*
     * @brief   判断两个数据是否相等
     * @return  true 相等 / false 不相等 | 不同类型
     */
    virtual const bool IsEqual(VarBase* other);

    /*
     * @brief   变量赋值，实际上不会改变this的值，而是用right替换this
     *          但基类的仍然返回null
     */
    virtual VarBase* VarAssign(VarBase* right);

    /*
     * @brief   NumberMethods
     *          数字相关的操作，默认返回空指针
     */
     // 获得数值
    virtual const bool GetBoolVar();

    virtual const unsigned char GetByteVar();

    virtual const int GetIntVar();

    virtual const double GetDoublVar();

    virtual const std::string GetStrVar();

    // 转换为布尔
    virtual VarBase* TransToBool();
    // 转换为字节类型
    virtual VarBase* TransToByte();
    // 转换为整型
    virtual VarBase* TransToInt();
    // 转换为浮点型
    virtual VarBase* TransToDouble();
    // 转换为字符串
    virtual VarBase* TransToString();

    // 加法
    virtual VarBase* OP_Add(VarBase* _right);
    // 减法
    virtual VarBase* OP_Sub(VarBase* _right);
    // 乘法
    virtual VarBase* OP_Mul(VarBase* _right);
    // 除法
    virtual VarBase* OP_Div(VarBase* _right);
    // 取余
    virtual VarBase* OP_Res(VarBase* _right);

    // 自加
    virtual VarBase* OP_SelfAdd();
    // 自减
    virtual VarBase* OP_SelfSub();

    // 大于等于 >=
    virtual VarBase* OP_Ge(VarBase* _right);
    // 大于 >
    virtual VarBase* OP_Gr(VarBase* _right);
    // 小于 <
    virtual VarBase* OP_low(VarBase* _right);
    // 小于等于 <=
    virtual VarBase* OP_le(VarBase* _right);
    // 等于 ==
    virtual VarBase* OP_Equ(VarBase* _right);
    // 不等于 !=
    virtual VarBase* OP_Neq(VarBase* _right);

    // 取反 !
    virtual VarBase* OP_Neg();
    // 逻辑或 ||
    virtual VarBase* OP_Or(VarBase* _right);
    // 逻辑与 &&
    virtual VarBase* OP_And(VarBase* _right);

    /*
     * @brief   SequenceMethods
     *          序列相关操作，主要是数组
     */
    // 获取数组的大小 
    virtual const uint32_t GetVecSize() const;

    // 数组已申请的空间
    virtual const uint32_t GetCapacity() const;

    // 数组单个元素的大小
    virtual const uint32_t GetUnitSize() const;

    // 扩展数组，返回扩展后数组的大小，不允许扩展返回 0
    virtual const uint32_t AppendArr(VarBase* _unit);

    // 删除数组的元素
    virtual const bool EraseUnit(const uint32_t _num);


    /**
     * @brief   结构体添加一个成员
     * @return  添加是否成功
     * @param   new_member 新成员的"模板"的指针
     * @param   member_name 成员在结构体内部名字
     */
    virtual const bool AddMember(VarBase* new_member, std::string member_name);

    /*
     * @brief   DynamicMethod
     *          动态结构体相关操作
     */
    virtual VarBase* GetMember(std::string& sub_type);

//public:  // 成员变量
//    DynamicDescrip*  m_dynamic_struct;      // 结构体描述
//    ArrayDescrip*    m_array;               // 数组描述
};