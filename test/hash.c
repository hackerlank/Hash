/**
 * 通用平台逻辑模块组
 * Copyright (c) 2009 Tiros.
 * @file hash.c
 * @brief 哈希表测试
 * @author 小逗
 * @date 2012/08/23
 * @par 修改记录
 *  2012/08/16 小逗-哈希表	<br>
 */

#include "../src/include/hash.h" 	/// < 定义和实现头文件均要
#include "../src/hash/hashdata.h"

int main(void)
{
	/// < 哈希表初始化 
	if (!HashInitial(pHashStructArr, NUM))
	{
		printf("initial failed\n");	
		return -1;
	}
	printf("initial success\n");

	/// < 结构体创建	
	HashStruct * pH0 = HashStructCreate(408);
	if (!pH0)
	{
		printf("hashstruct create failed\n");
		return -1;	
	}
	
	/// < 哈希表元素插入
	HashInsert(pHashStructArr, pH0);	
	/// < 结构体创建	
	HashStruct * pH1 = HashStructCreate(409);
	if (!pH1)
	{
		printf("hashstruct create failed\n");
		return -1;	
	}
	
	/// < 哈希表元素插入
	HashInsert(pHashStructArr, pH1);	
	/// < 结构体创建	
	HashStruct * pH2 = HashStructCreate(509);
	if (!pH2)
	{
		printf("hashstruct create failed\n");
		return -1;	
	}
	
	/// < 哈希表元素插入
	HashInsert(pHashStructArr, pH2);	

	/// < 简单打印测试
	printf("pHashStructArr[8]->value = %d 9->value = %d 9->value_t = %d\n", pHashStructArr[8]->next->value, pHashStructArr[9]->next->value, pHashStructArr[9]->next->next->value);
	
	/// < 释放
	FreeHash(pHashStructArr, NUM);		
	
	return 0;
}
