#include <cstdio>

FILE *input, *output;
char bitmap[200][200];
int initM,initN;
int inputcount;
int outputcount;
void B(int x, int y, int m, int n, int preM, int preN);
void D(int x, int y, int m, int n, int preM, int preN);
int main(){
	int m,n; //좌표
	input = fopen("bitmap.inp","r");
	output = fopen("bitmap.out","w");
	char check;
	while(true){
		fscanf(input,"%c %d %d\n",&check,&m,&n);
		inputcount = 0;
		initM = m;
		initN = n;
		if(check == 'B'){
			outputcount = 0;
			fprintf(output,"D%4d%4d\n",m,n);
			for(int i = 0; i < m; i++){
				for(int j = 0; j < n; j++){
					if(inputcount == 50){
						fscanf(input,"\n");
						inputcount = 0;
					}
					fscanf(input,"%c",&bitmap[i][j]);
					inputcount++;
				}
			}
			B(0,0,m,n,m,n);
			fscanf(input,"\n");
			if(outputcount !=0)fprintf(output,"\n");
		}
		else if(check == 'D'){
			inputcount = 0;
			outputcount = 0;
			fprintf(output,"B%4d%4d\n",m,n);
			D(0,0,m,n,m,n);
			fscanf(input,"\n");
			for(int i = 0; i < m; i++){
				for(int j = 0; j < n; j++){
					fprintf(output,"%c",bitmap[i][j]);
					outputcount++;
					if(outputcount == 50){
						outputcount = 0;
						fprintf(output,"\n");
					}
				}
			}
			if(outputcount !=0)fprintf(output,"\n");
		}
		else{
			break;
		}
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				bitmap[i][j] = NULL;
			}
		}
	}

	return 0;
}
void B(int x, int y, int m, int n, int preM, int preN){ //x , y시작좌표 m n 길이
	char compare = bitmap[x][y];
	bool control = false;
	bool breakcheck = false;
	int tempM;
	int tempN;
	if(x == initM || y == initN)return;
	if(x >= preM || y >= preN)return;
	for(int i = x; i < x+m ; i++){
		for(int j = y; j < y+n; j++){
			if(compare != bitmap[i][j]){
				fprintf(output,"D");
				printf("D");
				control = true;
				breakcheck = true;
				outputcount++;
				if(outputcount == 50){
					fprintf(output,"\n");
					outputcount = 0;
				}
				break;
			}
		}
		if(breakcheck == true)break;
	}
	if(control == false){
		fprintf(output,"%c",compare);
		printf("%c",compare);
		outputcount++;
		if(outputcount == 50){
			fprintf(output,"\n");
			outputcount = 0;
		}
	}
	else{ //재귀돌리는부분
		if(m > 1){
			tempM = m % 2 == 1 ? m+1 : m;
		}
		else tempM = 2;
		if(n > 1){
			tempN = n % 2 == 1 ? n+1 : n;
		}
		else tempN = 2;
		B(x,			y,			tempM/2,	tempN/2,	x+m,y+n);
		B(x,			y+tempN/2,	tempM/2,	n-tempN/2,	x+m,y+n);
		B(x+tempM/2,	y,			m-tempM/2,	tempN/2,	x+m,y+n); //한줄만남았을때 문제(널값참조)
		B(x+tempM/2,	y+tempN/2,	m-tempM/2, 	n-tempN/2,	x+m,y+n);
	}
}
void D(int x, int y, int m, int n, int preM, int preN){
	char in;
	int tempM;
	int tempN;
	if(bitmap[initM-1][initN-1] == '0' || bitmap[initM-1][initN-1] == '1')return;
	if(x >= preM || y >= preN)return;
	fscanf(input,"%c",&in);
	inputcount++;
	if(inputcount == 50){
		inputcount = 0;
		fscanf(input,"\n");
	}

	if(in == 'D'){
		if(m > 1){
			tempM = m % 2 == 1 ? m+1 : m;
		}
		else if(m == 1)tempM = 2;
		if(n > 1){
			tempN = n % 2 == 1 ? n+1 : n;
		}
		else if(n == 1)tempN = 2;
		D(x,			y,			tempM/2,	tempN/2,	x+m,y+n);
		D(x,			y+tempN/2,	tempM/2,	n-tempN/2,	x+m,y+n);
		D(x+tempM/2,	y,			m-tempM/2,	tempN/2,	x+m,y+n);
		D(x+tempM/2,	y+tempN/2,	m-tempM/2,	n-tempN/2,	x+m,y+n);
	}
	else if(in == '1' || in == '0'){
		for(int i = x; i < x+m; i++){
			for(int j = y; j < y+n; j++){
				bitmap[i][j] = in;
			}
		}
	}
}