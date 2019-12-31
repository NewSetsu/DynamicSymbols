#pragma once
#include "class/var_base.hpp"

struct StringObject : public VarBase
{
public:
    StringObject();
    virtual ~StringObject();
public:
    /*
     * 拷贝，类型检查等
     */
    virtual std::string ClassInfo() override;

    virtual const STRUCT_TYPE StructType()  override { return STRUCT_TYPE::ATOMIC; }

    virtual VarBase* VarCopy() override;

    virtual VarBase* VarRef() override;

    virtual const bool Erase() override;

    virtual const std::string& VarType() const override;

    virtual const bool CheckType(VarBase* other) override;

    virtual void Reset() override { m_str.clear(); }
    /*
     * 运算
     */
    virtual const bool IsEqual(VarBase* other) override;

    virtual VarBase* VarAssign(VarBase* right) override;

    virtual const std::string GetStrVar() override { return m_str; }

    // 暂时不支持字符串转换
    //// 转换为布尔
    //virtual VarBase* TransToBool();
    //// 转换为字节类型
    //virtual VarBase* TransToByte();
    //// 转换为整型
    //virtual VarBase* TransToInt();
    //// 转换为浮点型
    //virtual VarBase* TransToDouble();
    //// 转换为字符串
    //virtual VarBase* TransToString();   

    // 加法
    virtual VarBase* OP_Add(VarBase* right) override;
    //// 减法
    //virtual VarBase* OP_Sub(VarBase* right) override;
    //// 乘法
    //virtual VarBase* OP_Mul(VarBase* right) override;
    //// 除法
    //virtual VarBase* OP_Div(VarBase* right) override;
    //// 取余
    //virtual VarBase* OP_Res(VarBase* right) override;

    //// 自加
    //virtual VarBase* OP_SelfAdd() override;
    //// 自减
    //virtual VarBase* OP_SelfSub() override;


    // 大于等于 >=
    virtual VarBase* OP_Ge(VarBase* right) override;
    // 大于 >
    virtual VarBase* OP_Gr(VarBase* right) override;
    // 小于 <
    virtual VarBase* OP_low(VarBase* right) override;
    // 小于等于 <=
    virtual VarBase* OP_le(VarBase* right) override;
    // 等于 ==
    virtual VarBase* OP_Equ(VarBase* right) override;
    // 不等于 !=
    virtual VarBase* OP_Neq(VarBase* right) override;

    //// 取反 !
    //virtual VarBase* OP_Neg() override;
    //// 逻辑或 ||
    //virtual VarBase* OP_Or(VarBase* right) override;
    //// 逻辑与 &&
    //virtual VarBase* OP_And(VarBase* right) override;
public:
    // 该函数最后应该只能由内存池调用
    void SetVal(const char* val) { m_str = val; }

    std::string m_str;

};

