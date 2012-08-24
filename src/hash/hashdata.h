/**
 * 通用平台逻辑模块组
 * Copyright (c) 2009 Tiros.
 * @file hash.h
 * @brief 哈希表
 * @author 小逗
 * @date 2012/08/23
 * @par 修改记录
 */

#ifndef HASH_H_
#define HASH_H_
#include "../include/hash.h"

/**
 * @brief 哈希表结构体数据
 */
struct _HashStruct
{
    int value;             /// < 整型数据值
    struct _HashStruct * next;  /// < 指向下一个结构体
};

#endif /* HASH_H_ */
