#include<iostream>
#include<vector>

#define MAX_SIZE 100
using namespace std;

#define CMP_N_LOOP(EXPR) \
		for(; iter!=nums.end() ;iter++){ \
			if(prev EXPR *iter) return false; \
			prev=*iter; \
		}

bool isMonotonic(vector<int>& nums) {
	if(nums.size()<3) return true;
	vector<int>::iterator iter=nums.begin();
	int prev=*iter;
	iter++;
	if(nums.front() > nums.back()) CMP_N_LOOP(<)
	else CMP_N_LOOP(>)
	return true;
}
int main(){
	vector<int> nums;
	for(int i=0;i<MAX_SIZE;++i){
		int tmp;
		cin >> tmp;
		if(!cin.eof()) nums.push_back(tmp);
	}
	if(isMonotonic(nums)) cout<<"true";
	else cout<<"false";
}
