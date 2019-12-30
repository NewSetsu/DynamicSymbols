#pragma once
//
//#include "base_class.hpp"
//#include <map>
//
//class VarBase;
//
///*!
// * \class   ArrayDescrip
// * \brief   动态数组描述类
// * \author  chengx
// * \date    2019.12.24
// */
//struct ArrayDescrip final : public ClassBase
//{
//public:
//    ArrayDescrip(std::string& type);
//    virtual ~ArrayDescrip();
//public:
//    virtual std::string ClassInfo() override;
//
//    virtual const STRUCT_TYPE StructType() override {
//        return STRUCT_TYPE::ARRAY;
//    }
//
//    virtual const std::string& VarType() override {
//        return m_type;
//    }
//
//    virtual ClassBase* VarInstance() override {
//        return nullptr;
//    }
//
//    const bool AppendArray(VarBase* unit);
//
//    VarBase* GetUnit(const uint32_t num);
//
//    const bool EraseUnit(const uint32_t num);
//public:
//    // 数组只能有一种类型
//    std::string m_type;
//
//    std::vector<VarBase*> m_array;
//};
//
//
///*!
// * \class   DynamicDescrip
// * \brief   动态结构体描述类
// * \author  chengx
// * \date    2019.12.20
// * \note1   ToDo
// */
//struct DynamicDescrip final : public ClassBase
//{
//public:
//    DynamicDescrip(std::string& type);
//    virtual ~DynamicDescrip();
//public:
//    virtual std::string ClassInfo() override;
//
//    virtual const STRUCT_TYPE StructType() override {
//        return STRUCT_TYPE::DYNAMIC;
//    }
//
//    virtual const std::string& VarType() override {
//        return m_type;
//    }
//
//    virtual ClassBase* VarInstance() override {
//        return nullptr;
//    }
//
//    VarBase* GetMember(const std::string type_name);
//
////protected:
//    const bool AddMember(std::string type_name, VarBase* member);
//
//public:
//    std::string m_type;
//    std::map<std::string, VarBase*> m_members;
//};