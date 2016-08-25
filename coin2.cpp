#include <cstdio>

FILE *input = fopen("coin2.inp","r");
FILE *output = fopen("coin2.out","w");
int coin[101][101][101][3];
int check(int i, int j, int k);
void init();
int main(){
	int testcase = 0;
	int i,j,k;
	init();
	fscanf(input,"%d",&testcase);
	while(testcase--){
		fscanf(input,"%d %d %d",&i,&j,&k);
		fprintf(output,"(%d %d %d) : %d\n",i,j,k,check(i,j,k));
	}
}
void init(){
	coin[0][0][0][0] = 1;
	coin[0][0][0][1] = 1;
	coin[0][0][0][2] = 1;
	coin[0][0][1][0] = -1;
	coin[0][0][1][1] = -1;
	coin[0][0][1][2] = -1;
	coin[0][1][0][0] = -1;
	coin[0][1][0][1] = -1;
	coin[0][1][0][2] = -1;
	coin[1][0][0][0] = -1;
	coin[1][0][0][1] = -1;
	coin[1][0][0][2] = -1;
	for(int i = 0; i < 101; i++){
		for(int j = 0; j < 101; j++){
			for(int k = 0; k < 101; k++){
				for(int l = 0; l < 3; l++){
					if(coin[i][j][k][l] == 0){
						//한개뽑을때
						if(l == 0){
							if(i-1 >= 0){//첫번째에서
								if(coin[i-1][j][k][1] == -1 && coin[i-1][j][k][2] == -1){
									coin[i][j][k][l] = 1;
									continue;
								}
							}
							if(j-1 >= 0){//두번째에서
								if(coin[i][j-1][k][1] == -1 && coin[i][j-1][k][2] == -1){
									coin[i][j][k][l] = 1;
									continue;
								}
							}
							if(k-1 >= 0){//세번째에서
								if(coin[i][j][k-1][1] == -1 && coin[i][j][k-1][2] == -1){
									coin[i][j][k][l] = 1;
									continue;
								}
							}
						}
						//두개뽑을때
						if(l == 1){
							if(i-2 >= 0){//첫번째에서
								if(coin[i-2][j][k][0] == -1 && coin[i-2][j][k][2] == -1){
									coin[i][j][k][l] = 1;
									continue;
								}
							}
							if(j-2 >= 0){//두번째에서
								if(coin[i][j-2][k][0] == -1 && coin[i][j-2][k][2] == -1){
									coin[i][j][k][l] = 1;
									continue;
								}
							}
							if(k-2 >= 0){//세번째에서
								if(coin[i][j][k-2][0] == -1 && coin[i][j][k-2][2] == -1){
									coin[i][j][k][l] = 1;
									continue;
								}
							}
						}
						//세개뽑을때
						if(l == 2){
							if(i-3 >= 0){//첫번째에서
								if(coin[i-3][j][k][0] == -1 && coin[i-3][j][k][1] == -1){
									coin[i][j][k][l] = 1;
									continue;
								}
							}
							if(j-3 >= 0){//두번째에서
								if(coin[i][j-3][k][0] == -1 && coin[i][j-3][k][1] == -1){
									coin[i][j][k][l] = 1;
									continue;
								}
							}
							if(k-3 >= 0){//세번째에서
								if(coin[i][j][k-3][0] == -1 && coin[i][j][k-3][1] == -1){
									coin[i][j][k][l] = 1;
									continue;
								}
							}
						}
						coin[i][j][k][l] = -1;
					}
				}
			}
		}
	}
}
int check(int i, int j, int k){
	bool win = false;
	for(int l = 0; l < 3; l++){
		if(coin[i][j][k][l] == 1)win = true;
	}
	if(win == true)return 1;
	else return -1;
}