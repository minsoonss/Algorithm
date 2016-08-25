#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

FILE *in = fopen("jump.inp","r");
FILE *out = fopen("jump.out","w");
void calc();
int main(){
	int testcase = 0;
	fscanf(in,"%d",&testcase);
	while(testcase--){
		calc();
	}
}
void calc(){
	int max = 0;
	int left = 0;
	int right = 0;
	int jump[10000] = {0,};
	int num = 0;
	int result = 0;
	fscanf(in,"%d",&num);
	for(int i = 0; i < num; i++){
		fscanf(in,"%d",&jump[i]);
	}
	sort(jump,jump+num,greater<int>());
	max = jump[0]-jump[2];
	left = jump[1];
	right = jump[2];
	if(num%2 == 1){
		for(int i = 3; i < num; i+=2){
			if(left-jump[i] > max){
				max = left-jump[i];
			}
			if(right-jump[i+1] > max){
				max = right-jump[i+1];
			}
			left = jump[i];
			right = jump[i+1];
		}
		result = max > left-right ? max : left-right;
	}
	else{
		for(int i = 3; i < num-1; i+=2){
			if(left-jump[i] > max){
				max = left-jump[i];
			}
			if(right-jump[i+1] > max){
				max = right-jump[i+1];
			}
			left = jump[i];
			right = jump[i+1];
		}
		if(left-jump[num-1] > max){
			max = left-jump[num-1];
		}
		left = jump[num-1];
		result = max > left-right ? max : left-right;
	}
	fprintf(out,"%d\n",result);
}