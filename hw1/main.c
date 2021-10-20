#include<cstdio>
#define MAX_ARRAY 100
int input_data[MAX_ARRAY];
int input_size;

bool isMonotonic(int* nums, int numsSize){
	bool type=nums[0]>nums[numsSize-1];
	
}

int main(){

	for(input_size=0;i<MAX_ARRAY && scanf("%d",&input_data[i])!=EOF; ++input_size);

	if(isMonotonic(input_data,input_size)) printf("true");
	else printf("false");
}

