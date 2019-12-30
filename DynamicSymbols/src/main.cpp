#include "dynamic_symbols.h"
#include "instance/struct_pool.hpp"
#include "instance/instance.hpp"
#include "utils/transfer_check.hpp"
#include <iostream>

using namespace std;

// 初始化所有全局变量
// 顺序依次为 类型转换器、模板、基元内存池、数组内存池、结构体内存池
void Init()
{
    TransferCheck::GetInstance();

    RL_Template::GetInstance();

    _MEM_POOL_::BoolObjectPool::GetInstance();

    _MEM_POOL_::IntObjectPool::GetInstance();

    _MEM_POOL_::ByteObjectPool::GetInstance();

    _MEM_POOL_::DoubleObjectPool::GetInstance();

    _MEM_POOL_::StringObjectPool::GetInstance();

    _MEM_POOL_::DynamicPool::GetInstance();
}

// 全局单例析构，顺序与初始化相反
void Destory()
{
    _MEM_POOL_::DynamicPool::ReleaseInstance();

    _MEM_POOL_::StringObjectPool::ReleaseInstance();

    _MEM_POOL_::DoubleObjectPool::ReleaseInstance();

    _MEM_POOL_::ByteObjectPool::ReleaseInstance();

    _MEM_POOL_::IntObjectPool::ReleaseInstance();

    _MEM_POOL_::BoolObjectPool::ReleaseInstance();

    RL_Template::ReleaseInstance();

    TransferCheck::ReleaseInstance();
}

int main()
{
    Init();

    std::string point_type = "POSITION";
    std::string point_x = "X";
    auto new_point = _MEM_POOL_::DynamicPool::GetInstance()->CreateStructObject(point_type);
    auto new_point_x = new_point->GetMember(point_x);

    std::cout << new_point->ClassInfo();

    std::cout << new_point_x->ClassInfo();

    Destory();

    return 0;
}