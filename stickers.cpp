#include <cstdio>
#include <algorithm>
using namespace std;

FILE *in = fopen("stickers.inp","r");
FILE *out = fopen("stickers.out","w");
void calc();
int main(){
	int testcase = 0;
	fscanf(in,"%d",&testcase);
	while(testcase--){
		calc();
	}
}
void calc(){
	int stickers[2][100001] = {0,};
	int num = 0;
	fscanf(in,"%d",&num);
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < num; j++){
			fscanf(in,"%d",&stickers[i][j]);
		}
	}
	stickers[0][1] += stickers[1][0];
	stickers[1][1] += stickers[0][0];
	for(int i = 2; i < num; i++){
		stickers[0][i] += max(stickers[1][i-2],stickers[1][i-1]);
		stickers[1][i] += max(stickers[0][i-2],stickers[0][i-1]);
	}
	fprintf(out,"%d\n",max(stickers[0][num-1],stickers[1][num-1]));
}