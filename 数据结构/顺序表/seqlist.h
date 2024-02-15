/*
 * Copyright (C) 2022 Yansheyang
 * All Rights Reserved.
 *
 * File: sqlist.h
 *
 * Description: Provides the structure of a sequential list and corresponding APIs.
 *
 * Processing flow:
 *   1. The SQLIST structure defines the elements and properties of a sequential list.
 *   2. APIs such as sqlist_init(), sqlist_insert(), sqlist_delete(), etc.
 *      are provided to manipulate the sequential list.
 *
 * Version: V0.1
 *
 * Modifications: .
 *
 * Note: 1 tab == 4 spaces!
 */

#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stddef.h>

typedef int SlType;  /*用于之后创建不同类型的顺序表*/

typedef struct seqlist
{
   SlType* a;
   size_t size;
   size_t capacity; 
}SeqList;

void SeqListInit(SeqList *psl);
void SeqListDesTory(SeqList* psl);
void SeqlistCapacity(SeqList *psl);
void SeqListPushBack(SeqList *psl, SlType x);
void SeqListPopBack(SeqList *psl);
void SeqListPushFront(SeqList *psl, SlType x);
void SeqListPopFront(SeqList *psl);
void SeqListPrintf(SeqList *psl);
void SeqListSearch(SeqList *psl, SlType x);
void SeqListListInsert(SeqList *psl, size_t pos, SlType x);
void SeqListDelate(SeqList *psl, size_t pos);
size_t SeqListSize(SeqList *psl);
void SeqListDataChange(SeqList *psl, size_t pos, SlType x);
#endif
