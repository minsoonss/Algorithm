#include <cstdio>

unsigned long long pole[21][21][21];
FILE *input, *output;
void init();
int main(){
	int testcase;
	int n,l,r;
	input = fopen("pole.inp","r");
	output = fopen("pole.out","w");
	pole[1][1][1] = 1;
	init();
	fscanf(input,"%d",&testcase);
	for(int i = 0; i < testcase; i++){
		fscanf(input,"%d %d %d",&n,&l,&r);
		fprintf(output,"%lld\n",pole[n][l][r]);
	}
}
void init(){
	for(int i = 1; i < 21; i++){
		for(int j = 1; j < 21; j++){
			for(int k = 2; k < 21; k++){
				pole[k][i][j] = pole[k-1][i-1][j]+pole[k-1][i][j-1]+pole[k-1][i][j]*(k-2);
			}
		}
	}
}