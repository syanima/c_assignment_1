typedef struct{
	int length;
	int typeSize;
	void *base;
}ArrayUtil;

typedef int(MatchFunc)(void *,void *);

int areEqual(ArrayUtil a, ArrayUtil b);
ArrayUtil create(int typeSize, int length);
ArrayUtil resize(ArrayUtil util, int length);
int findIndex(ArrayUtil util, void* element);
void dispose(ArrayUtil util);
void* findFirst(ArrayUtil util, MatchFunc* match, void* hint);
void* findLast(ArrayUtil util, MatchFunc* match, void* hint);
int count(ArrayUtil util, MatchFunc* match, void* hint);
