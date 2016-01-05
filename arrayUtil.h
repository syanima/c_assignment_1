typedef struct{
	int length;
	int typeSize;
	void *base;
}ArrayUtil;

int areEqual(ArrayUtil a, ArrayUtil b);
ArrayUtil create(int typeSize, int length);
ArrayUtil resize(ArrayUtil util, int length);
int findIndex(ArrayUtil util, void* element);
