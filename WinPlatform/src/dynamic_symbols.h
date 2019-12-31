﻿#pragma once

/* include everything */
#include "mem_pool/mem_pool.hpp"
#include "object/atomic_object.h"
#include "instance/struct_pool.hpp"
#include "instance/instance.hpp"
#include "utils/transfer_check.hpp"
#include <iostream>

#define BOOL_OBJECT_POOL (_MEM_POOL_::BoolObjectPool::GetInstance())
#define BYTE_OBJECT_POOL (_MEM_POOL_::ByteObjectPool::GetInstance())
#define INT_OBJECT_POOL (_MEM_POOL_::IntObjectPool::GetInstance())
#define DOUBLE_OBJECT_POOL (_MEM_POOL_::DoubleObjectPool::GetInstance())
#define STRING_OBJECT_POOL (_MEM_POOL_::StringObjectPool::GetInstance())
#define STRUCT_OBJECT_POOL (_MEM_POOL_::DynamicPool::GetInstance())

// 初始化所有全局变量
// 顺序依次为 类型转换器、模板、基元内存池、数组内存池、结构体内存池
void Init()
{
    TransferCheck::GetInstance();

    RL_Template::GetInstance();

    BOOL_OBJECT_POOL;

    BYTE_OBJECT_POOL;

    INT_OBJECT_POOL;

    DOUBLE_OBJECT_POOL;

    STRING_OBJECT_POOL;

    STRUCT_OBJECT_POOL;
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