#include "SeqList.h"

void SeqListInit(SL* ps) {
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListDestory(SL* ps) {
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListPrint(SL* ps) {
	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListCheckCapacity(SL* ps) {
	if (ps->size == ps->capacity) {
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		int* tmp = (int*)realloc(ps->a, newcapacity * sizeof(int*));
		if (tmp == NULL) {
			printf("realloc fail\n");
			exit(-1);	//终止程序，异常退出
		}

		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

void SeqListPushBack(SL* ps, int x) {
	if (ps->size == ps->capacity) {
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		int* tmp = (int*)realloc(ps->a, newcapacity * sizeof(int*));
		if (tmp == NULL) {
			printf("realloc fail\n");
			exit(-1);	//终止程序，异常退出
		}

		ps->a = tmp;
		ps->capacity = newcapacity;
	 }

	ps->a[ps->size] = x;
	ps->size++; 
}

void SeqListPopBack(SL* ps) {
	//if (ps->size > 0) {
	//	ps->size--;
	//}

	assert(ps->size > 0);
	ps->size--;
}

void SeqListPushFront(SL* ps, int x) {
	SeqListCheckCapacity(ps);

	int end = ps->size - 1;
	while (end >= 0) {
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SL* ps) {
	assert(ps->size > 0);

	int begin = 1;
	while (begin < ps->size) {
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}

	ps->size--;
}

void SeqListFind(SL* ps, int x) {
	for (int i = 0; i < ps->size; i++) {
		if (ps->a[i] == x) {
			printf("已找到，下标为%d\n", i);
			return;
		}
	}

	printf("没找到\n");
}

void SeqListInsert(SL* ps, int pos, int x) {
	//温柔处理
	//if (pos > ps->size || pos < 0) {
	//	printf("pos invalid\n");
	//	return;
	//}

	//暴力处理 直接终止 并报错位置 内容要写真
	assert(pos >= 0 || pos <= ps->size);
	int end = ps->size - 1;
	SeqListCheckCapacity(ps);
	while (end >= pos) {
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;

}

void SeqListErase(SL* ps, int pos) {
	assert(pos >= 0 && pos < ps->size);

	int begin = pos;
	while (begin < ps->size) {
		ps->a[begin] = ps->a[begin + 1];
		begin++;
	}

	ps->size--;
}