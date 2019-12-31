#include "transfer_check.hpp"
#include "basic_def/var_type.hpp"
#include <algorithm>

// 这四种类型允许隐式转换
static std::vector<std::string> basic_types = {
        ATOMIC_TYPES::BOOL_TYPE,
        ATOMIC_TYPES::BYTE_TYPE,
        ATOMIC_TYPES::DOUBLE_TYPE,
        ATOMIC_TYPES::INTNUM_TYPE
};

TransferCheck::TransferCheck()
{
    for (auto& itor : basic_types)
    {
        m_trans_map[itor] = &basic_types;
    }
}


const bool TransferCheck::TypeCheck(const std::string& str1, const std::string& str2)
{
    if (m_trans_map.count(str1) != 0)
    {
        for (auto& itor : *(m_trans_map[str1]))
        {
            if (itor == str2)
                return true;
        }
    }

    return str1 == str2;
}