#include <cstdio>

FILE * input;
FILE * output;
void calc();
int main(){
	input = fopen("bowling.inp","r");
	output = fopen("bowling.out","w");
	int testcase = 0;
	fscanf(input,"%d",&testcase);
	for(int i = 0; i < testcase; i++){
		
		calc();
	}
	return 0;
}
void calc(){
	int sum = 0;
	int arr[10][3] = {0,};
	for(int i = 0; i < 10; i++){
		fscanf(input,"%d",&arr[i][0]);
		if(arr[i][0] != 10){
			fscanf(input,"%d",&arr[i][1]);
		}
		if(i == 9 && arr[i][0]+arr[i][1] == 10){
			if(arr[i][0] == 10)fscanf(input,"%d",&arr[i][1]);
			fscanf(input,"%d",&arr[i][2]);
		}
	}
	for(int i = 0; i < 9; i++){
		if(arr[i][0]+arr[i][1] == 10){ //���������
			if(arr[i][0] == 10){ //��Ʈ����ũ
				if(i == 8)arr[i][0] += arr[i+1][0] + arr[i+1][1];
				else if(arr[i+1][0] == 10){ //���ӽ�Ʈ����ũ�� ���
					arr[i][0] += arr[i+1][0] + arr[i+2][0];
				}
				else{
					arr[i][0] += arr[i+1][0] + arr[i+1][1];
				}
			}
			else{ //������ϰ��
				arr[i][0] += arr[i+1][0];
			}
		}
	}
	for(int i = 0; i< 10; i++){
		for(int j = 0; j < 3; j++){
			sum += arr[i][j];
		}
	}
	fprintf(output,"%d\n",sum);
}