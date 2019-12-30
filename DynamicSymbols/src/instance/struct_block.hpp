#pragma once
#include "object/atomic_object.h"

namespace _MEM_POOL_ {
    struct StructBlock
    {
        StructBlock(std::string type_name);

        ~StructBlock();

        // 成员
        StructBlock* next;
        StructObject* m_buf;
    };

} // ! _MEM_POOL_