#include "struct_block.hpp"
#include "instance.hpp"

namespace _MEM_POOL_ {
    // 结构体的数量相对小一点 待定
    constexpr const int STRUCT_BLOCK_SIZE = 64;

    StructBlock::StructBlock(std::string type_name)
    {
        auto struct_template = RL_Template::GetInstance()->GetTemplate(type_name);

        // 很危险，程序正在实例化一个不存在的对象
        if (struct_template == nullptr)
            return;

        m_buf = new StructObject[STRUCT_BLOCK_SIZE];

        for (int i = 0; i < STRUCT_BLOCK_SIZE - 1; i++)
        {
            m_buf[i].next_in_pool = &m_buf[i + 1];
            m_buf[i].MakeInstance(struct_template);
        }

        m_buf[STRUCT_BLOCK_SIZE - 2].next_in_pool = &m_buf[STRUCT_BLOCK_SIZE - 1];
        m_buf[STRUCT_BLOCK_SIZE - 1].next_in_pool = nullptr;
        m_buf[STRUCT_BLOCK_SIZE - 1].MakeInstance(struct_template);
    }

    StructBlock::~StructBlock()
    {
        if (next)
            next->~StructBlock();

        for (int i = 0; i < 64; i++)
        {
            m_buf[i].Erase();
        }

        delete[] m_buf;
    }

} // ! _MEM_POOL_