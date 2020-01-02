#pragma once
#include "class/var_base.hpp"

struct ArrayObject : public VarBase
{
public:
    ArrayObject();
    virtual ~ArrayObject() {};

public:
    /************************************************************************
    *           对数组池开放的接口
    *************************************************************************/
    /**
     * @brief   创建数组模板
     * @return  null
     * @param   数组子元素
     */
    void CreateArrayTemplate(VarBase* sub_unit_ptr, const int arr_id);

    void InitByTemplate(ArrayObject* arr_temp);

    /************************************************************************
    *           基类接口
    *************************************************************************/
    virtual std::string ClassInfo() override;

    virtual const STRUCT_TYPE StructType() override { return STRUCT_TYPE::ARRAY; }

    virtual VarBase* VarRef() override;

    virtual VarBase* VarCopy() override;

    virtual const VarBase* VarTemplate() override;
    // virtual VarBase* VarInstance() override;

    virtual const bool Erase() override;

    virtual const std::string& VarType() const override;

    virtual const bool CheckType(VarBase* other) override;

    virtual void Reset() override;

    const bool MakeInstance(const ArrayObject* source);

    // 数组的大小
    virtual const uint32_t GetVecSize() const override;

    // 数组已申请的空间
    virtual const uint32_t GetCapacity() const override;

    // 扩展数组，返回扩展后数组的大小，不允许扩展返回 0
    virtual const uint32_t PushBack(VarBase* _unit)  override;

    // 删除数组的元素
    virtual const bool EraseUnit(const uint32_t _num, const bool is_check = false)  override;

    // 获得数组的元素
    virtual VarBase* GetArrUnit(const uint32_t num) override;

    // 修改数组对象的值
    virtual const bool SetArrUnit(VarBase* unit, const bool is_check = false) override;
public:
    //
    int m_temp_id;
    VarBase* m_template_ptr;
    std::string m_type;
    std::vector<VarBase*> m_array;


};

