#include<stdio.h>
#define MAX_ARRAY 100
#define true 1
#define false 0
int input_data[MAX_ARRAY];
int input_size;
_Bool isMonotonic(int* nums, int numsSize){
	if(numsSize<3) return true;
	int i=1,prev=nums[0],now=nums[1];
	_Bool result=false;
	if(prev>nums[numsSize-1]){
		while(i<numsSize){
			result|=(prev < now);
			prev=now;
			++i;
			now=nums[i];
		}
	}
	else{
		while(i<numsSize){
			result|=(prev > now);
			prev=now;
			++i;
			now=nums[i];
		}
	}
	return !result;
}

int main(){
	//for(input_size=0;input_size<MAX_ARRAY && scanf("%d",&input_data[input_size])!=EOF; ++input_size);
	//for(int i=0;i<input_size;++i) printf("%d ",input_data[i]);
	input_data[0]=1;
	input_data[1]=2;
	input_data[2]=2;
	input_data[3]=1;
	input_size=4;

	if(isMonotonic(input_data,input_size)) printf("true");
	else printf("false");
}

