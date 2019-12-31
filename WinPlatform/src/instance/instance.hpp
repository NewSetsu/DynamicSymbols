#pragma once

#include "utils/singleton.hpp"
#include "object/atomic_object.h"

/*************************************************************************
*   RL 的 “模板” 自带内嵌类型的结构体
*   还支持创建新的结构体
*   能通过这个模板获得对象的 “实例”
**************************************************************************/

class RL_Template final : public SingletonBase<RL_Template>
{
    friend class SingletonBase<RL_Template>;
public:
    // 判断一个模板名是否被占用
    const bool TypeExist(std::string type);

    // 添加一个模板
    const bool AddTemplate(StructObject&& struct_template);

    // 获得一个模板
    StructObject* GetTemplate(std::string type);

    // 获得所有模板
    std::vector<std::string> GetAllTemplate();

    const bool InitTemplate();
private:
    RL_Template();

    virtual ~RL_Template();
private:
    // 模板池， 任何结构体的初始模板都在模板池中
    std::map<std::string, StructObject> m_struct_template;
};