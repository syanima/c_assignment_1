#include <stdio.h>
#include <assert.h>
#include "arrayUtil.h"

void test_for_equal(){
	ArrayUtil weights = create(4,7);
	ArrayUtil heights = create(4,7);
	assert(areEqual(weights,heights)==1);
	assert(areEqual(heights,weights)==1);
	assert(areEqual(weights,weights)==1);
	assert(areEqual(heights,heights)==1);
}

void test_for_checking_resize_of_array(){
	ArrayUtil heights = create(4,7);
	int length = 10;
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

void subtraction(void *hint,void *sourceItem,void *destinationItem){
	int minus_value = *(int *)hint;
	int source_number = *(int *)sourceItem;
	int result = source_number - minus_value;
	*(int *)destinationItem = result;
}

void addition(void *hint,void *sourceItem,void *destinationItem){
	int add_value = *(int *)hint;
	int source_number = *(int *)sourceItem;
	int result = add_value + source_number;
	*(int *)destinationItem = result;
}

void multiplication(void* hint, void* item){
	int number = *(int *)item;
	int  mul_value = *(int *)hint;
	int result = mul_value * number;
	*(int *)item = result;
}

void* smaller(void* hint, void* previousItem, void* item){
	int previous_number = *(int *)previousItem;
	int current_number = *(int *)item;
	int result = previous_number < current_number ? previous_number : current_number;
	*(int *)previousItem = result;
	return previousItem;
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

void test_for_filter(){
	ArrayUtil scores = create(4,5);
	int element = 23;
	void *hint = &element;
	int *number = (int *)scores.base;
	number[0] = 18;
	number[1] = 23;
	number[2] = 46;
	number[3] = 2;
	number[4] = 69;
	ArrayUtil destination = create(8,3);
	void * dest = destination.base;
	int ans = filter(scores,isEven,hint,destination.base,5);
	int answer = filter(scores,isDivisible,hint,destination.base,5);
	assert(ans == 3);
	assert(answer == 3);
}

void test_for_map(){
	ArrayUtil source = create(4,5);
	ArrayUtil destination1 = create(4,5);
	ArrayUtil destination2 = create(4,5);

	int *number = (int *)source.base;
	number[0] = 100;
	number[1] = 200;
	number[2] = 300;
	number[3] = 400;
	number[4] = 500;
	int special_value = 10;
	void *hint = &special_value;
	map(source,destination1,addition,hint);
	map(source,destination2,subtraction,hint);

	int *element = (int *) destination1.base;
	int *ele = (int *) destination2.base;

	assert(element[0]==110);
	assert(element[1]==210);
	assert(element[2]==310);
	assert(element[3]==410);
	assert(element[4]==510);

	assert(ele[0]==90);
	assert(ele[1]==190);
	assert(ele[2]==290);
	assert(ele[3]==390);
	assert(ele[4]==490);

}

void test_for_forEach(){
	ArrayUtil source = create(4,5);

	int *number = (int *)source.base;
	number[0] = 10;
	number[1] = 20;
	number[2] = 30;
	number[3] = 40;
	number[4] = 50;
	int special_value = 10;
	void *hint = &special_value;
	forEach(source,multiplication,hint);

	int *element = (int *) source.base;

	assert(element[0]==100);
	assert(element[1]==200);
	assert(element[2]==300);
	assert(element[3]==400);
	assert(element[4]==500);
}

void test_for_reduce(){
	ArrayUtil source = create(4,5);

	int *number = (int *)source.base;
	number[0] = 100;
	number[1] = 200;
	number[2] = 300;
	number[3] = 400;
	number[4] = 500;
	int special_value = 0;
	void *hint = &special_value;
	int initial_number = 10;
	void *initialValue = &initial_number;
	void *answer = reduce(source,smaller,hint,initialValue);

	assert(*(int *)answer==10);
	
}
