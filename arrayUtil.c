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

void test_for_find_index_of_element(){
	ArrayUtil array1 = create (1,8);
	ArrayUtil array2 = create (4,6);
	int element = 23;
	char elem='s';
	int *number = (int *)array2.base;
	number[5]=23;
	char *num = (char *)array1.base;
	num[3]='s';
	assert(findIndex(array1,&elem)==3);
	assert(findIndex(array2,&element)==5);
}

int isEven(void *hint,void *item){
	int number = *(int *)item;
	return number % 2 == 0;
}

int isDivisible(void *hint,void *item){
	int number = *(int *)item;
	int denominator = *(int *)hint;
	return number % denominator == 0;
}

void test_for_checking_find_first_element_that_match_with_hint(){
	ArrayUtil scores = create(4,5);
	int element = 23;
	void *hint = &element;
	int *number = (int *)scores.base;
	number[0] = 21;
	number[1] = 23;
	number[2] = 20;
	number[3] = 2;
	number[4] = 69;
	void *ans = findFirst(scores,isEven,hint);
	void *answer = findFirst(scores,isDivisible,hint);
	assert(*(int *)ans==20);
	assert(*(int *)answer==23);
}

void test_for_checking_find_last_element_that_match_with_hint(){
	ArrayUtil scores = create(4,5);
	int element = 23;
	void *hint = &element;
	int *number = (int *)scores.base;
	number[0] = 21;
	number[1] = 23;
	number[2] = 20;
	number[3] = 2;
	number[4] = 69;
	void *ans = findLast(scores,isEven,hint);
	void *answer = findLast(scores,isDivisible,hint);
	assert(*(int *)ans == 2);
	assert(*(int *)answer == 69);
}

void test_for_checking_count_of_element_that_match_with_hint(){
	ArrayUtil scores = create(4,5);
	int element = 23;
	void *hint = &element;
	int *number = (int *)scores.base;
	number[0] = 21;
	number[1] = 23;
	number[2] = 46;
	number[3] = 2;
	number[4] = 69;
	int ans = count(scores,isEven,hint);
	int answer = count(scores,isDivisible,hint);
	assert(ans==2);
	assert(answer==3);
}

int main(void){
	ArrayUtil weights = create(4,8);
	ArrayUtil heights = create(4,8);
	test_are_equal(weights,heights);
	test_for_checking_resize_of_array(heights,10);
	test_for_find_index_of_element();
	test_for_checking_find_first_element_that_match_with_hint();
	test_for_checking_find_last_element_that_match_with_hint();
	test_for_checking_count_of_element_that_match_with_hint();
	return 0;
}