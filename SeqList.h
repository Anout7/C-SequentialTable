#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>

typedef struct SeqList {
	int* a;
	int size;	//表示数组中储存了多少个数据
	int capacity;	//数据实际能存数据的空间容量是多大
} SL;

void SeqListInit(SL* ps);
void SeqListDestory(SL* ps);
void SeqListPrint(SL* ps);
void SeqListCheckCapacity(SL* ps);
void SeqListPushBack(SL* ps, int x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, int x);
void SeqListPopFront(SL* ps);
void SeqListFind(SL* ps, int x);
void SeqListInsert(SL* ps, int pos, int x);
void SeqListErase(SL* ps, int pos);