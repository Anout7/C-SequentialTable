#include "SeqList.h"

void TestSeqList1() {
	SL sl;
	SeqListInit(&sl); 
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);


	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);


	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);


	SeqListPushBack(&sl, 10);
	SeqListPushBack(&sl, 20);
	SeqListPrint(&sl);

	SeqListPushFront(&sl, 100);
	SeqListPushFront(&sl, 200);
	SeqListPushFront(&sl, 300);
	SeqListPushFront(&sl, 400);
	SeqListPushFront(&sl, 500);
	SeqListPushFront(&sl, 600);
	SeqListPushFront(&sl, 700);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListFind(&sl, 100);

	SeqListInsert(&sl, 3, 999);
	SeqListPrint(&sl);

	SeqListErase(&sl, 0);
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}

int main() {

	TestSeqList1();

	return 0;
}