#pragma once

#include "class/var_base.hpp"
#include <map>

class RL_Template;

// todo : 添加递归的 使用vector数组的构造函数
struct StructObject : public VarBase
{
public:
    StructObject() {};

    virtual ~StructObject() {};
public:
    // 只有把对象当做模板处理的时候需要调用该函数
    // 设定模板的类型
    const bool SetTemplateType(std::string type);

    /**
     * 拷贝，类型检查等
     */
    virtual std::string ClassInfo() override;

    virtual const STRUCT_TYPE StructType()  override { return STRUCT_TYPE::DYNAMIC; }

    virtual VarBase* VarRef() override;

    virtual VarBase* VarCopy() override;

    virtual const VarBase* VarTemplate() override;

    // virtual VarBase* VarInstance() override;

    virtual const bool Erase() override;

    virtual const std::string& VarType() const override;

    virtual const bool CheckType(VarBase* other) override;

    virtual void Reset() override;
    /**
     * @brief   "模板"实例化，结构体内存池会一次申请若干个同类结构体，并使用模板进行实例化
     * @return  实例化成功 | 失败
     * @param   结构体的模板
     */
    const bool MakeInstance(const StructObject* source);

    /**
     * @brief   结构体添加一个成员
     * @return  添加是否成功
     * @param   new_member 新成员的"模板"的指针
     * @param   member_name 成员在结构体内部名字
     */
    virtual const bool AddMember(VarBase* new_member, std::string member_name) override;

    /**
     * @brief   DynamicMethod
     *          动态结构体相关操作
     */
    virtual VarBase* GetMember(std::string& sub_type) override;

    /**
     * @brief   更新成员变量的值
     * @return  更新成功 | 失败
     * @param   member 成员变量的地址
     * @param   value 赋值
     */
    virtual const bool SetMembers(VarBase* member, VarBase* value, const bool is_check = false) override;
private:
    std::string m_type;
    std::map<std::string, VarBase*> m_members;
};

