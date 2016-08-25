#include <cstdio>

FILE *input = fopen("coin.inp","r");
FILE *output = fopen("coin.out","w");

int game[101][101][101];
void init();
void calc();
int main(){
	int testcase = 0;
	game[0][0][0] = -1;
	game[1][0][0] = -1;
	game[0][1][0] = -1;
	game[0][0][1] = -1;
	game[1][1][0] = 1;
	game[0][1][1] = 1;
	game[1][0][1] = 1;
	init();
	fscanf(input,"%d",&testcase);
	while(testcase--){
		calc();
	}
}
void init(){
	for(int i = 0; i < 101; i++){
		for(int j = 0; j < 101; j++){
			for(int k = 0; k < 101; k++){
				//�ʱ�ȭ�Ѻκ� �پ�ѱ�
				if(game[i][j][k] != 0){
					
				}
				else{
					//�Ѱ��̴°��
					if(i-1 >= 0 && game[i-1][j][k] == -1){ //ù��°�ſ���
						game[i][j][k] = 1;
						continue;
					}
					if(j-1 >= 0 && game[i][j-1][k] == -1){ //�ι�°�ſ���
						game[i][j][k] = 1;
						continue;
					}
					if(k-1 >= 0 && game[i][j][k-1] == -1){ //����°�ſ���
						game[i][j][k] = 1;
						continue;
					}
					//�ΰ��̴°��
					if(i-2 >= 0 && game[i-2][j][k] == -1){ //ù��°�ſ���
						game[i][j][k] = 1;
						continue;
					}
					if(j-2 >= 0 && game[i][j-2][k] == -1){ //�ι�°�ſ���
						game[i][j][k] = 1;
						continue;
					}
					if(k-2 >= 0 && game[i][j][k-2] == -1){ //����°�ſ���
						game[i][j][k] = 1;
						continue;
					}
					//�����̴°��
					if(i-3 >= 0 && game[i-3][j][k] == -1){ //ù��°�ſ���
						game[i][j][k] = 1;
						continue;
					}
					if(j-3 >= 0 && game[i][j-3][k] == -1){ //�ι�°�ſ���
						game[i][j][k] = 1;
						continue;
					}
					if(k-3 >= 0 && game[i][j][k-3] == -1){ //����°�ſ���
						game[i][j][k] = 1;
						continue;
					}
					game[i][j][k] = -1;
				}
			}
		}
	}
}
void calc(){
	int a, b, c;
	fscanf(input,"%d %d %d",&a,&b,&c);
	fprintf(output,"(%d %d %d) : %d\n",a,b,c,game[a][b][c]);
}