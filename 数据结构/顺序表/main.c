#include "seqlist.h"

int main() {
    SeqList list;
    SeqListInit(&list);

    SeqListPushBack(&list, 1);
    SeqListPushBack(&list, 2);
    SeqListPushBack(&list, 3);
    SeqListPushBack(&list, 3);
    printf("顺序表大小: %zu\n", SeqListSize(&list));
    printf("顺序表元素: ");
    SeqListPrintf(&list);
    SeqListSearch(&list, 3);
    SeqListSearch(&list, 4);
    SeqListPopFront(&list);
    SeqListPopBack(&list);

    printf("删除头尾元素后的顺序表大小: %zu\n", SeqListSize(&list));
    printf("删除头尾元素后的顺序表元素: ");
    SeqListPrintf(&list);

    SeqListDesTory(&list);

    return 0;
}
