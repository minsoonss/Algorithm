#include <cstdio>

char B[64];
void init();
void calc();
int main(){
	int testcase = 0;
	scanf("%d",&testcase);
	init();
	for(int i = 0; i < testcase; i++){
		calc();	
	}
}
void calc(){
	int num;
	char jin[1000000] = NULL;
	scanf("%d",&num);
	for(){
		
	}

}
void init(){
	char a = '0';
	for(char i = '0'; i < a+64; i++){
		B[i] = i;
	}

}