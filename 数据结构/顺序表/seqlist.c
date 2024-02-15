#include "seqlist.h"


/// @brief 初始化顺序表
/// @param psl 
void SeqListInit(SeqList* psl)
{
    assert(psl != NULL);
    psl->a = NULL;
    psl->size = 0;
    psl->capacity = 0;
}

/// @brief 销毁顺序表
/// @param psl 
void SeqListDesTory(SeqList* psl)
{
    assert(psl != NULL);
    free(psl->a);
    psl->a = NULL;
    psl->size = 0;
    psl->capacity = 0;
}


/// @brief 检查顺序表是否满了
/// @param psl 
void SeqlistCapacity(SeqList* psl)
{
    assert(psl != NULL);
    size_t NewCapacity;
    /*若当前的有效数据与最大数据大小相等，则代表顺序表已经满了*/
    if(psl->size == psl->capacity)
    {
       if(psl->size == 0) /*此时的有效长度是0代表顺序表为空*/
       {
            NewCapacity = 4;/*此情况下直接将最大空间扩容到4*/
       }
       else
       {
            NewCapacity = psl->size * 2;/*其它情况下直接将最大空间大小翻倍*/
       }
    }
    /*根据NewCpacity的值开辟新的空间*/
    SlType* p = realloc(psl->a, NewCapacity * sizeof(SlType));
    if(p == NULL)
    {
        perror("realloc");
    }
    /*开辟成功更新容量*/
    psl->a = p;
    psl->capacity = NewCapacity;

}

/// @brief 顺序表尾插
/// @param psl 
/// @param x 
void SeqListPushBack(SeqList* psl, SlType x)
{
    assert(psl != NULL);
    SeqlistCapacity(psl);
    psl->a[psl->size] = x;
    psl->size++;
}

/// @brief 顺序表尾删
/// @param psl 
void SeqListPopBack(SeqList* psl)
{
    assert(psl != NULL);
    assert(psl->size != 0 && psl->capacity != 0);
    psl->size--;
}

/// @brief 顺序表头插
/// @param psl 
/// @param x 
void SeqListPushFront(SeqList* psl, SlType x)
{
    assert(psl != NULL);
    SeqlistCapacity(psl);
    size_t i = 0;
    for(i = psl->size - 1; i >= 0; i--)
    {
        psl->a[i + 1] = psl->a[i]; 
    }
    psl->a[0] = x;
    psl->size++;
}


/// @brief 顺序表头删
/// @param psl 
void SeqListPopFront(SeqList* psl)
{
    assert(psl != NULL);
    assert(psl->size > 0);
    size_t i = 0;
    for(i = 1; i < psl->size - 1; i++)
    {
        psl->a[i - 1] = psl->a[i]; 
    }
    psl->size--;
}


/// @brief 打印顺序表
/// @param psl 
void SeqListPrintf(SeqList* psl)
{
    assert(psl != NULL);
    size_t i = 0;
    if (psl->size == 0)
    {
        printf("顺序表为空");
    }
    for(i = 0; i < psl->size; i++)
    {
       printf("%d ",psl->a[i]);
    }
    printf("\n");
}





/// @brief 顺序表对应值查找指定值
/// @param psl 
/// @param x 
void SeqListSearch(SeqList* psl, SlType x)
{
    assert(psl != NULL);
    size_t FoundCount = 0;
    size_t i = 0;
    for(i = 0; i < psl->size; ++i)
    {
      if(psl->a[i] == x)
      {
        printf("在索引 %ld 处找到值 %d\n", i, x);
        FoundCount++;
      }

    }
    if(FoundCount == 0)
    {
       printf("值 %d 在顺序表中没有找到。\n", x);
    }
}



/// @brief 在顺序表指定的下标处插入数据
/// @param psl 
/// @param pos 
/// @param x 
void SeqListListInsert(SeqList* psl, size_t pos, SlType x)
{
    assert(psl != NULL);
    assert(pos >= 0 && pos <= psl->size);/*检查pos的值合法*/
    SeqlistCapacity(psl);/*检查顺序表是否已满*/
    
    size_t i = 0;
    for(i = psl->size; i > pos; i--)
    {
      psl->a[i] = psl->a[i - 1]; 
    }
    psl->a[pos] = x;
    psl->size++;
}



/// @brief 在顺序表指定的下标处删除数据
/// @param psl 
/// @param pos 
void SeqListDelate(SeqList* psl, size_t pos)
{
    assert(psl != NULL);
    assert(psl->size > 0);/*检查顺序表不为空*/
    assert(pos >= 0 && pos <= psl->size);/*检查pos的值合法*/

    size_t i = 0;
    for(i = pos + 1; i < psl->size; i++)
    {
      psl->a[i - 1] = psl->a[i]; 
    }
    psl->size--;
}


/// @brief 查看书勋表的有效数据个数
/// @param psl 
/// @return 
size_t SeqListSize(SeqList* psl)
{
    assert(psl != NULL);

    return psl -> size;
}

/// @brief 修改顺序表指定位置的数据
/// @param psl 
/// @param pos 
/// @param x 
void SeqListDataChange(SeqList* psl, size_t pos, SlType x)
{
    assert(psl != NULL);
    assert(psl->size > 0);/*检查顺序表不为空*/
    assert(pos >= 0 && pos <= psl->size);/*检查pos的值合法*/

    psl->a[pos] = x; 

}