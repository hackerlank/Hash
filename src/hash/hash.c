/**
 * 通用平台逻辑模块组
 * Copyright (c) 2009 Tiros.
 * @file hash.c
 * @brief 哈希表
 * @author 小逗
 * @date 2012/08/23
 * @par 修改记录
 *  2012/08/16 小逗-哈希表    <br>
 */
#include "../include/hash.h"
#include "./hashdata.h"
#include <stdlib.h>

/**
 * @brief 哈希表结构体释放.
 */
static void FreeHashStruct(HashStruct * pHashStruct);

/**
 * @brief 哈希表结构体指针数组 初始化.
 */
bool HashInitial(HashStruct *pHashStructArr[], int num)
{
    int i = 0;
    HashStruct * pHashStruct = NULL;
    
    //if (!pHashStruct || num <= 0)
      //  return false;
    
    for ( ; i < num; ++i)
    {
        pHashStruct = (HashStruct *)malloc(sizeof(HashStruct));
        if (!pHashStruct)
            return false;
        pHashStruct->value = i;
        pHashStruct->next = NULL;
        pHashStructArr[i] = pHashStruct;
    }
    return true;
}

/**
 * @brief 哈希表结构体创建.
 */
HashStruct * HashStructCreate(int value)
{
    HashStruct * pHashStruct = (HashStruct *)malloc(sizeof(HashStruct));
    if (!pHashStruct)
        return NULL;
    pHashStruct->value = value;
    pHashStruct->next = NULL;
    
    return pHashStruct;
}

/**
 * @brief 哈希表结构体指针数组插入 - 哈希函数h(x) = x % 10.
 */
void HashInsert(HashStruct *pHashStructArr[], HashStruct * pHashStruct)
{
    int pos = pHashStruct->value % 10;     /// < 哈希值
    HashStruct * head = pHashStructArr[pos];    /// < 头指针
    
    if (!pHashStructArr || !pHashStruct)
    {
        FreeHashStruct(pHashStruct);
        return;
    }
    
    while (head->next) head = head->next;       /// < 指向最后一个节点
    
    head->next = pHashStruct;                   /// < 插入
    pHashStruct->next = NULL;
}

/**
 * @brief 哈希表结构体指针数组释放.
 */
void FreeHash(HashStruct *pHashStructArr[], int num)
{
    int i = 0;
    for ( ; i < num; ++i)
        FreeHashStruct(pHashStructArr[i]);
    free(pHashStructArr);
    pHashStructArr = NULL;
}

/**
 * @brief 哈希表结构体释放.
 */
void FreeHashStruct(HashStruct * pHashStruct)
{
    HashStruct * head = pHashStruct, * pfree = NULL;
    if (!head)
        return;
    while (head != NULL)
    {
        pfree = head;
        head = head->next;
        free(pfree);
        pfree = NULL;
    }
    free(pHashStruct);
    pHashStruct = NULL;
}

