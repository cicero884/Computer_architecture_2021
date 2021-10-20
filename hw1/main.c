#include<stdio.h>
#define MAX_ARRAY 100
#define true 1
#define false 0
int input_data[MAX_ARRAY];
int input_size;
_Bool isMonotonic(int* nums, int numsSize){
	if(numsSize<3) return true;
	int i=1,prev=nums[0],now;
	_Bool type=prev>nums[numsSize-1];
	if(type){
		while(i<numsSize){
			now=nums[i];
			if(prev < now) return false;
			prev=now;
			++i;
		}
	}
	else{
		while(i<numsSize){
			now=nums[i];
			if(prev > now) return false;
			prev=now;
			++i;
		}
	}
	return true;
}

int main(){
	//for(input_size=0;input_size<MAX_ARRAY && scanf("%d",&input_data[input_size])!=EOF; ++input_size);
	//for(int i=0;i<input_size;++i) printf("%d ",input_data[i]);
	input[0]=1;
	input[2]=2;
	input[3]=2;
	input[4]=1;

	if(isMonotonic(input_data,input_size)) printf("true");
	else printf("false");
}

