#include <stdio.h>
#include <assert.h>
#include "arrayUtil.h"

void test_are_equal(ArrayUtil weights,ArrayUtil heights){
	assert(areEqual(weights,heights)==1);
	assert(areEqual(heights,weights)==1);
	assert(areEqual(weights,weights)==1);
	assert(areEqual(heights,heights)==1);
}

void test_for_checking_resize_of_array(ArrayUtil heights,int length){
	ArrayUtil new_one = resize(heights,length);
	assert(new_one.length == length);
}

//void test_for_find_index_of_element()

int main(void){
	ArrayUtil weights = create(4,8);
	ArrayUtil heights = create(4,8);
	test_are_equal(weights,heights);
	test_for_checking_resize_of_array(heights,10);
	return 0;
}