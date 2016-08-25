#include <cstdio>
#include <cstring>//왜안대지...초기화때문인가...
#include <cstdlib>
#define MIN2(a,b)        ((a)<(b)? (a):(b))
#define MIN3(a,b,c)        ( MIN2( MIN2(a,b), MIN2(b,c)) )
FILE *input = fopen("drive.inp","r");
FILE *output = fopen("drive.out","w");

int garo[101][101] = {0,};
int sero[101][101] = {0,};
int pos[101][101][203][2] = {0,};
int M,N,L,G;
void calc();
void write();
int main(){
	int testcase = 0;
	fscanf(input,"%d",&testcase);
	for(int i = 0; i < testcase; i++){

		write();
		calc();
	}
}
void write(){
	fscanf(input,"%d %d %d %d",&M,&N,&L,&G);
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N-1; j++){
			fscanf(input,"%d",&garo[i][j]);
		}
	}
	for(int i = 0; i < M-1; i++){
		for(int j = 0; j < N; j++){
			fscanf(input,"%d",&sero[i][j]);
		}
	}
}
void calc(){
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < 203; k++){
				pos[i][j][k][0] = G+1;
				pos[i][j][k][1] = G+1;
			}
		}
	}
	pos[0][0][0][0] = pos[0][0][0][1] = 0;
	int result = 1000000000;
	int rotate = M+N;
	for(int i = 1; i < M; i++){
		pos[i][0][0][1] = sero[i-1][0]+pos[i-1][0][0][1];
	}
	for(int i = 1; i < N; i++){
		pos[0][i][0][0] = garo[0][i-1]+pos[0][i-1][0][0];
	}
	for(int i = 1; i < M; i++){
		for(int j = 1; j < N; j++){
			for(int k = 1; k < i+j; k++){
				pos[i][j][k][0] = garo[i][j-1] + MIN2(pos[i][j-1][k][0],pos[i][j-1][k-1][1]);
				pos[i][j][k][1] = sero[i-1][j] + MIN2(pos[i-1][j][k-1][0],pos[i-1][j][k][1]);
			}
		}
	}
	for(int i = 1; i <= M+N; i++){
		result = MIN3(result,pos[M-1][N-1][i][0],pos[M-1][N-1][i][1]);
		if(MIN2(pos[M-1][N-1][i][0], pos[M-1][N-1][i][1]) <= G){
			rotate = i;
			break;
		}
	}
	if(result > G){
		fprintf(output,"-1\n");
	}
	else{
		fprintf(output,"%d\n",rotate+(M-1+N-1)*L);
	}
}