#pragma once

#include "object/atomic_object.h"

namespace INNER_STRUCT {
    // 基本元素组成的结构体
    StructObject PositionStruct();

    StructObject OrientStruct();

    StructObject ConfdataStruct();

    // 高级结构体
    StructObject PoseStruct();
} // ! INNER_STRUCT