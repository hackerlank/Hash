/**
 * 通用平台逻辑模块组
 * Copyright (c) 2009 Tiros.
 * @file hash.h
 * @brief 哈希表
 * @author 小逗
 * @date 2012/08/23
 * @par 修改记录
 */

#ifndef HASHDATA_H_
#define HASHDATA_H_
#include <stdio.h>
#include <stdbool.h>

#define NUM 10

/**
 * @brief 哈希表结构体数据.
 */
typedef struct _HashStruct HashStruct;

/**
 * @brief 哈希表结构体指针数组 - 10个结构体指针.
 */
HashStruct * pHashStructArr[NUM];

/**
 * @brief 哈希表结构体指针数组 初始化.
 * @param[out] pHashStructArr[] - 指针数组（存储结构体指针）.
 * @param[in] num - 指针数组个数.
 * @return if success return true, else return false.
 */
bool HashInitial(HashStruct *pHashStructArr[], int num);

/**
 * @brief 哈希表结构体创建.
 * @param[in] value - 赋值.
 * @return if success return structure pointer, else return NULL.
 */
HashStruct * HashStructCreate(int value); 

/**
 * @brief 哈希表结构体指针数组插入 - 哈希函数h(x) = x % 10.
 * @param[out] pHashStructArr[] - 指针数组（存储结构体指针）.
 * @param[in] pHashStruct - 结构体指针.
 */
void HashInsert(HashStruct *pHashStructArr[], HashStruct * pHashStruct);

/**
 * @brief 哈希表结构体指针数组释放.
 * @param[out] pHashStructArr[] - 指针数组（存储结构体指针）.
 * @param[in] num - 指针数组个数.
 */
void FreeHash(HashStruct *pHashStructArr[], int num);


#endif /* HASHDATA_H_ */

