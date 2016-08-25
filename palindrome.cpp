#include <cstdio>
#include <cstring>

FILE *input;
FILE *output;
int calc(char str[1001]);
int arr[1001][1001] = {0,};
int main(){
	int testcase = 0;
	int leng = 0;
	input = fopen("palindrome.inp","r");
	output = fopen("palindrome.out","w");
	fscanf(input,"%d",&testcase);
	for(int i = 0; i < testcase; i++){
		char str[1001] = {NULL,}; //널포인터까지 1001개
		leng = calc(str);
		for(int i = 1; i < leng; i++){
			for(int j = 1; j < leng; j++){
				arr[i][j] = 0;
			}
		}
	}
}
int calc(char str[1001]){
	int check = 0;
	int index = 0;
	int count = 0;
	fscanf(input,"%s",str);
	int leng = strlen(str); //길이
	
	//팰린드롬인지 체크
	for(int i = 0; i <= strlen(str)/2-1; i++){
		if(str[i] == str[strlen(str)-i-1])check++;
	}
	if(check == strlen(str)/2){
		fprintf(output,"0\n");
		return 0;
	}
	for(int i = 1; i <= leng; i++){
		for(int j = 1; j <= leng; j++){
			if(str[i-1] == str[leng-j]){
				arr[i][j] = arr[i-1][j-1]+1;
			}
			else{
				arr[i][j] = arr[i-1][j] > arr[i][j-1]? arr[i-1][j] : arr[i][j-1];
			}
		}
	}
	if(leng - arr[leng][leng] < 3)fprintf(output,"%d\n",leng-arr[leng][leng]);
	else fprintf(output,"-1\n");
	return leng;
}