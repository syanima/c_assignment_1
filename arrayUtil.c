#include <stdio.h>
#include <assert.h>
#include "arrayUtil.h"


void test_for_array_has_element_size_for_int(){
	ArrayUtil marks = create(sizeof(int),5);
	assert(marks.typeSize == 4);
}

void test_for_array_has_element_size_for_char(){
	ArrayUtil marks = create(sizeof(char),5);
	assert(marks.typeSize == 1);
}

void test_for_array_has_element_size_for_double(){
	ArrayUtil marks = create(sizeof(double),5);
	assert(marks.typeSize == 8);
}

void test_for_array_has_element_size_for_float(){
	ArrayUtil marks = create(sizeof(float),5);
	assert(marks.typeSize == 4);
}

void test_for_array_have_8_elements(){
	ArrayUtil marks = create(sizeof(int),8);
	assert(marks.length == 8);
}

void test_for_structure_has_an_array_of_elements(){
	ArrayUtil util = create(sizeof(int),5);
	int *array=(int*)util.base;
	array[0]=0;
	array[1]=9;
	assert(array[0]==0);
	assert(array[1]==9);
}

void test_for_areEqual_should_return_1_if_equal(){
	ArrayUtil weights = create(4,7);
	ArrayUtil heights = create(4,7);
	ArrayUtil scores = create(4,8);
	assert(areEqual(weights,heights)==1);
	assert(areEqual(heights,weights)==1);
	assert(areEqual(weights,weights)==1);
	assert(areEqual(heights,heights)==1);
	assert(areEqual(heights,scores)==0);

}

void test_for_areEqual_should_return_0_if_not_equal(){
	ArrayUtil heights = create(4,7);
	ArrayUtil scores = create(4,8);
	assert(areEqual(heights,scores)==0);
	assert(areEqual(scores,heights)==0);
}

void test_for_checking_resize_of_array(){
	ArrayUtil heights = create(4,7);
	int length = 10;
	ArrayUtil new_one = resize(heights,length);
	assert(new_one.length == length);
}

void test_for_array_elements_should_be_increased(){
	ArrayUtil util = create(sizeof(int),5);
	ArrayUtil marks = resize(util ,10);
	assert(marks.length == 10);
}

void test_for_array_elements_should_be_decreased(){
	ArrayUtil util = create(sizeof(int),5);
	ArrayUtil marks = resize(util ,2);
	assert(marks.length == 2);
}

void test_for_array_elements_should_be_increased_with_float(){
	ArrayUtil util = create(sizeof(float),5);
	ArrayUtil marks = resize(util ,8);
	assert(marks.length==8);
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

void test_for_finds_the_index_of_0_in_array(){
	int element=0;
	ArrayUtil util = create(sizeof(int),5);
	int* number = (int*)util.base;
	number[0] = element;
	int index = findIndex(util,&element);
	assert(index==0);
}

void test_for_finds_the_index_of_1_in_array(){
	int element=1;
	ArrayUtil util = create(sizeof(int),5);
	int* number = (int*)util.base;
	number[4] = element;
	int index = findIndex(util,&element);
	assert(index==4);
}

void test_for_does_not_finds_the_index_of_8_in_array(){
	int element=19;
	ArrayUtil util = create(sizeof(int),5);
	int* number = (int*)util.base;
	number[7] = element;
	int index = findIndex(util,&element);
	assert(index==-1);
}

void test_for_finds_the_index_of_s_in_array(){
	char element='s';
	ArrayUtil util = create(sizeof(char),5);
	char* number = (char*)util.base;
	number[4] = element;
	int index = findIndex(util,&element);
	assert(index==4);
}

void test_for_finds_the_index_of_float_in_array(){
	float element=5.7;
	ArrayUtil util = create(sizeof(float),5);
	float* number = (float*)util.base;
	number[4] = element;
	int index = findIndex(util,&element);
	assert(index==4);
}

void test_for_finds_the_index_of_double_in_array(){
	double element=5.7;
	ArrayUtil util = create(sizeof(double),5);
	double* number = (double*)util.base;
	number[4] = element;
	int index = findIndex(util,&element);
	assert(index==4);
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

void subtract(void* hint, void* item){
	int number = *(int *)item;
	int  minus_value = *(int *)hint;
	int result = number - minus_value;
	*(int *)item = result;
}

void* smaller(void* hint, void* previousItem, void* item){
	int previous_number = *(int *)previousItem;
	int current_number = *(int *)item;
	int result = previous_number < current_number ? previous_number : current_number;
	*(int *)previousItem = result;
	return previousItem;
}

void* larger(void* hint, void* previousItem, void* item){
	int previous_number = *(int *)previousItem;
	int current_number = *(int *)item;
	int result = previous_number > current_number ? previous_number : current_number;
	*(int *)previousItem = result;
	return previousItem;
}


void test_for_find_first_element_that_is_even_should_return_that_number(){
	ArrayUtil scores = create(4,5);
	int element = 0;
	void *hint = &element;
	int *number = (int *)scores.base;
	number[0] = 21;
	number[1] = 23;
	number[2] = 20;
	number[3] = 2;
	number[4] = 69;
	void *ans = findFirst(scores,isEven,hint);
	assert(*(int *)ans==20);
}

void test_for_is_even_should_return_NULL_if_no_even_numbers_in_array(){
	ArrayUtil scores = create(4,5);
	int element = 0;
	void *hint = &element;
	int *number = (int *)scores.base;
	number[0] = 21;
	number[1] = 23;
	number[2] = 25;
	number[3] = 27;
	number[4] = 69;
	void *ans = findFirst(scores,isEven,hint);
	assert(ans==NULL);
}

void test_for_find_first_element_that_is_divisible_by_hint_should_return_that_number(){
	ArrayUtil scores = create(4,5);
	int element = 23;
	void *hint = &element;
	int *number = (int *)scores.base;
	number[0] = 21;
	number[1] = 23;
	number[2] = 20;
	number[3] = 2;
	number[4] = 69;
	void *answer = findFirst(scores,isDivisible,hint);
	assert(*(int *)answer==23);
}

void test_for_is_divisible_by_hint_should_return_NULL_if_all_are_not_divisible_elements(){
	ArrayUtil scores = create(4,5);
	int element = 23;
	void *hint = &element;
	int *number = (int *)scores.base;
	number[0] = 21;
	number[1] = 22;
	number[2] = 20;
	number[3] = 2;
	number[4] = 6;
	void *answer = findFirst(scores,isDivisible,hint);
	assert(answer==NULL);
}

void  test_for_find_last_element_that_is_divisible_by_hint_should_return_that_number(){
	ArrayUtil scores = create(4,5);
	int element = 23;
	void *hint = &element;
	int *number = (int *)scores.base;
	number[0] = 21;
	number[1] = 23;
	number[2] = 20;
	number[3] = 2;
	number[4] = 69;
	void *answer = findLast(scores,isDivisible,hint);
	assert(*(int *)answer == 69);
}

void test_for_find_last_element_that_is_even_should_return_that_number(){
	ArrayUtil scores = create(4,5);
	int element = 0;
	void *hint = &element;
	int *number = (int *)scores.base;
	number[0] = 21;
	number[1] = 23;
	number[2] = 20;
	number[3] = 2;
	number[4] = 69;
	void *ans = findLast(scores,isEven,hint);
	assert(*(int *)ans == 2);
}

void test_for_count_of_element_that_is_divisible_hint(){
	ArrayUtil scores = create(4,5);
	int element = 23;
	void *hint = &element;
	int *number = (int *)scores.base;
	number[0] = 21;
	number[1] = 23;
	number[2] = 46;
	number[3] = 2;
	number[4] = 69;
	int answer = count(scores,isDivisible,hint);
	assert(answer==3);
}

void test_for_count_of_element_that_are_even(){
	ArrayUtil scores = create(4,5);
	int element = 0;
	void *hint = &element;
	int *number = (int *)scores.base;
	number[0] = 21;
	number[1] = 23;
	number[2] = 46;
	number[3] = 2;
	number[4] = 69;
	int ans = count(scores,isEven,hint);
	assert(ans==2);
}

void test_for_returns_0_if_there_no_even_numbers_for_isEven(){
	ArrayUtil scores = create(4,5);
	int element = 0;
	void *hint = &element;
	int *number = (int *)scores.base;
	number[0] = 21;
	number[1] = 23;
	number[2] = 49;
	number[3] = 25;
	number[4] = 69;
	int ans = count(scores,isEven,hint);
	assert(ans==0);
}

void test_for_returns_0_if_there_no_number_divisible_with_hint(){
	ArrayUtil scores = create(4,5);
	int element = 13;
	void *hint = &element;
	int *number = (int *)scores.base;
	number[0] = 21;
	number[1] = 23;
	number[2] = 19;
	number[3] = 25;
	number[4] = 9;
	int ans = count(scores,isDivisible,hint);
	assert(ans==0);
}

void test_for_filter_should_returns_the_total_number_matches_the_criteria_in_isEven(){
	ArrayUtil scores = create(4,5);
	int element = 0;
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
	assert(ans == 3);
}

void test_for_filter_should_returns_the_total_number_matches_the_criteria_in_isDivisible(){
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
	int answer = filter(scores,isDivisible,hint,destination.base,5);
	assert(answer == 3);
}

void test_for_map_returns_array_after_subtraction_of_10_from_each_element(){
	ArrayUtil source = create(4,5);
	ArrayUtil destination2 = create(4,5);

	int *number = (int *)source.base;
	number[0] = 100;
	number[1] = 200;
	number[2] = 300;
	number[3] = 400;
	number[4] = 500;
	int special_value = 10;
	void *hint = &special_value;
	map(source,destination2,subtraction,hint);

	int *ele = (int *) destination2.base;

	assert(ele[0]==90);
	assert(ele[1]==190);
	assert(ele[2]==290);
	assert(ele[3]==390);
	assert(ele[4]==490);
}

void test_for_map_returns_array_after_addition_of_10_to_each_element(){
	ArrayUtil source = create(4,5);
	ArrayUtil destination1 = create(4,5);

	int *number = (int *)source.base;
	number[0] = 100;
	number[1] = 200;
	number[2] = 300;
	number[3] = 400;
	number[4] = 500;
	int special_value = 10;
	void *hint = &special_value;
	map(source,destination1,addition,hint);

	int *element = (int *) destination1.base;

	assert(element[0]==110);
	assert(element[1]==210);
	assert(element[2]==310);
	assert(element[3]==410);
	assert(element[4]==510);
}

void test_for_forEach_must_subtract_2_from_each_element_of_data(){
	ArrayUtil source = create(4,5);

	int *number = (int *)source.base;
	number[0] = 10;
	number[1] = 20;
	number[2] = 30;
	number[3] = 40;
	number[4] = 50;
	int special_value = 2;
	void *hint = &special_value;
	forEach(source,subtract,hint);

	int *element = (int *) source.base;

	assert(element[0]==8);
	assert(element[1]==18);
	assert(element[2]==28);
	assert(element[3]==38);
	assert(element[4]==48);
}

void test_for_forEach_must_multiply_10_to_each_element_of_data(){
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

void test_for_reduce_returning_smaller_number_in_int_array(){
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

void test_for_reduce_returning_larger_number_in_int_array(){
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
	void *answer = reduce(source,larger,hint,initialValue);

	assert(*(int *)answer==500);
}

void test_for_reduce_returning_larger_number_in_float_array(){
	ArrayUtil source = create(sizeof(float),5);

	float *number = (float *)source.base;
	number[0] = 100.3;
	number[1] = 20.9;
	number[2] = 300.0;
	number[3] = 500.2;
	number[4] = 500.1;
	float special_value = 0;
	void *hint = &special_value;
	float initial_number = 10.0;
	void *initialValue = &initial_number;
	void *answer = reduce(source,larger,hint,initialValue);

	assert(*(float *)answer==500.2f);
}