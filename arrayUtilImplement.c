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

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems ){
 	int count=0;
 	int till=util.length*util.typeSize;
	void *item;	
	for(int i=0;(i< till && count < maxItems);i=i+util.typeSize){
		item=util.base+i;			
		if(match(hint,item)==1){			
			destination[count]=item;
			count=count+1;
		}
	}	
	return count;
}

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
	for(int i = 0 ; i < source.length ; i ++){
		convert(hint,source.base+(i * source.typeSize),destination.base+(i * destination.typeSize));
	}
}

void forEach(ArrayUtil util, OperationFunc* operation, void* hint){
	int i;
	for(i=0;i < util.length; i++){
		operation(hint,util.base+(i * util.typeSize));
	}
}

void* reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* initialValue){
	for (int i = 0; i < util.length; i++){
		void * answer= reducer( hint, initialValue, util.base);
		initialValue = answer;
		util.base+=util.typeSize;
	}
	return initialValue;
}
