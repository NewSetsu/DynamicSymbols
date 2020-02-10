#include "array_object_pool.hpp"
#include "../mem_pool.hpp"

static int BOOL_ARRAY_ID = -1;
static int BYTE_ARRAY_ID = -1;
static int INT_ARRAY_ID = -1;
static int DOUBLE_ARRAY_ID = -1;
static int STRING_ARRAY_ID = -1;

_MEM_POOL_::ArrayPool::ArrayPool()
{
    this->first_block = new MemoryBlock<ArrayObject>();
    this->free_num_cursor = first_block->m_buf;


    // 创建基元类型的数组
    BOOL_ARRAY_ID = RegAnArray(BoolObjectPool::GetInstance()->GetTemplate());
    BYTE_ARRAY_ID = RegAnArray(const_cast<ByteObject*>(ByteObjectPool::GetInstance()->GetTemplate()));
    INT_ARRAY_ID = RegAnArray(const_cast<IntObject*>(IntObjectPool::GetInstance()->GetTemplate()));
    DOUBLE_ARRAY_ID = RegAnArray(const_cast<DoubleObject*>(DoubleObjectPool::GetInstance()->GetTemplate()));
    STRING_ARRAY_ID = RegAnArray(const_cast<StringObject*>(StringObjectPool::GetInstance()->GetTemplate()));
}

_MEM_POOL_::ArrayPool::~ArrayPool()
{
    delete first_block;
}

ArrayObject* _MEM_POOL_::ArrayPool::CreateNewArray(const int arr_id)
{
    if (arr_id < 0 || arr_id >= static_cast<int>(m_array_template.size()))
    {
        return nullptr;
    }

    auto ans = free_num_cursor;
    ans->InitByTemplate(&m_array_template[arr_id]);
    free_num_cursor = static_cast<ArrayObject*>(free_num_cursor->next_in_pool);

    if (free_num_cursor == nullptr)
    {
        auto tmp_block = new MemoryBlock<ArrayObject>();
        tmp_block->next = first_block;
        first_block = tmp_block;
        free_num_cursor = first_block->m_buf;
    }

    return ans;
}

void _MEM_POOL_::ArrayPool::Recycle(ArrayObject* ptr)
{
    ptr->Reset();
    ptr->next_in_pool = free_num_cursor;
    free_num_cursor = ptr;
}

const int _MEM_POOL_::ArrayPool::RegAnArray(VarBase* sub_unit)
{
    if (sub_unit == nullptr)
        return -1;

    auto new_array = ArrayObject();

    int ans_id = static_cast<int>(m_array_template.size());

    new_array.CreateArrayTemplate(sub_unit, ans_id);

    m_array_template.push_back(new_array);

    return ans_id;
}

VarBase* _MEM_POOL_::ArrayPool::GetTemplate(const int arr_id)
{
    if (arr_id < 0 || arr_id >= static_cast<int>(m_array_template.size()))
        return nullptr;

    return &m_array_template[arr_id];
}

int _MEM_POOL_::GetBoolArrID()
{
    return BOOL_ARRAY_ID;
}

int _MEM_POOL_::GetByteArrID()
{
    return BYTE_ARRAY_ID;
}

int _MEM_POOL_::GetIntArrID()
{
    return INT_ARRAY_ID;
}

int _MEM_POOL_::GetDoubleArrID()
{
    return DOUBLE_ARRAY_ID;
}

int _MEM_POOL_::GetStringArrID()
{
    return STRING_ARRAY_ID;
}
