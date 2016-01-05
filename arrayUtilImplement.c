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

// int findIndex(ArrayUtil util, void* element){


// }


