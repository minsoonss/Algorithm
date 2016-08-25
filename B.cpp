#include <cstdio>
#include <deque>
using namespace std;
deque <int> d;
int sum;
int num;
void calc();
void input();
int main(){
	int testcase = 0;
	scanf("%d",&testcase);
	for(int i = 0; i < testcase; i++){
		input();
		sum = 0;
		calc();
		printf("%d\n",sum);
		d.clear();
	}
}
void calc(){
	if(d.size() == 1){
		sum += d.front();
		return ;
	}
	while(!d.empty()){
		int front = 1;
		int back = 1;
		if(){ //³»°¡ ¾Õ¿¡²¬ »ÌÀ»°æ¿ì
		
		}
	}
}
void input(){
	int i = 0;
	scanf("%d",&num);
	for(int j = 0; j < num; j++){
		scanf("%d",&i);
		d.push_back(i);
	}
}