#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayUtil.h"

ArrayUtil create(int typeSize, int length){
	ArrayUtil ptr;
	ptr.base = calloc(length,typeSize);
	ptr.length = length;
	ptr.typeSize = typeSize;
	return ptr;
}

ArrayUtil resize(ArrayUtil util, int length){
	int needed_size = util.typeSize * length;
	ArrayUtil *ptr = realloc(util.base,needed_size);
	ptr->length = length;
	return *ptr;
}

int areEqual(ArrayUtil heights, ArrayUtil weights){
	int length = heights.length > weights.length ? heights.length : weights.length;
	int compare = memcmp (heights.base,weights.base,length);
	if(heights.length == weights.length && heights.typeSize == weights.typeSize && compare == 0)
		return 1;
	return 0;
}

int findIndex(ArrayUtil util, void* element){
	void *base = util.base;
	for (int i = 0; i < util.length; i++){
		if(memcmp(base,element,util.typeSize) == 0){
			return i;
		}
		base+=util.typeSize;
	}
	return -1;
}

void dispose(ArrayUtil util){
	free(util.base);
}

void* findFirst(ArrayUtil util, MatchFunc* match, void* hint){
	void *item=util.base;
	for(int i = 0;i<util.length;i++){
		if(match(hint,item) == 1){
			return item;
		}
		item+=util.typeSize;
	}

	return NULL;
}

void* findLast(ArrayUtil util, MatchFunc* match, void* hint){
	void *item = util.base+((util.length-1)*util.typeSize);
	for(int i = 0;i<util.length;i++){
		if(match(hint,item) == 1){
			return item;
		}
		item-=util.typeSize;
	}
	return 	NULL;
}

int count(ArrayUtil util, MatchFunc* match, void* hint){
	void *item=util.base;
	int count = 0;
	for(int i = 0;i<util.length;i++){
		if(match(hint,item) == 1){
			count++;
		}
		item+=util.typeSize;
	}
	return count;
}

