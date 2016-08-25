#include <cstdio>
#include <algorithm>
using namespace std;

FILE *input = fopen("air.inp","r");
FILE *output = fopen("air.out","w");
long long xyz[300][300][300];
long long x[200];
long long y[200];
long long z[200];//입력 소팅
long long x_s[200];
long long y_s[200];
long long z_s[200]; //중복제거 - 좌표
long long orix[200];
long long oriy[200];
long long oriz[200]; //기본 입력
long long num;//입체도형수
long long cntx;
long long cnty;
long long cntz;
long long counting;
unsigned long long sum;
void init();
void count();
void calc();
int main(){
	init();
	count();
	calc();
	return 0;
}
void init(){
	fscanf(input,"%lld",&num);
	for(long long i = 0; i < num*2; i+=2){
		fscanf(input,"%lld %lld %lld %lld %lld %lld",&x[i],&y[i],&z[i],&x[i+1],&y[i+1],&z[i+1]);
		orix[i] = x[i];
		orix[i+1] = x[i+1];
		oriy[i] = y[i];
		oriy[i+1] = y[i+1];
		oriz[i] = z[i];
		oriz[i+1] = z[i+1];
	}
	sort(x,x+num*2);
	sort(y,y+num*2);
	sort(z,z+num*2);
	for(long long i=0;i<num*2;i++){
		  if(x[i] != x[i-1]){
			  x_s[cntx] = x[i];
			  cntx++;
		  }
		  if(y[i] != y[i-1]){
			  y_s[cnty] = y[i];
			  cnty++;
		  }
		  if(z[i] != z[i-1]){
			  z_s[cntz] = z[i];
			  cntz++;
		  }
	}
}
void count(){
	long long sx=0,sy=0,sz=0,fx=0,fy=0,fz=0;
	for(long long i = 0; i < num*2-1; i+=2){
		for(long long j = 0; j < cntx; j++){
			if(x_s[j] == orix[i])sx=j;
			if(x_s[j] == orix[i+1]){
				fx=j;
				break;
			}
		}
		for(long long j = 0; j < cnty; j++){
			if(y_s[j] == oriy[i])sy=j;
			if(y_s[j] == oriy[i+1]){
				fy=j;
				break;
			}
		}
		for(long long j = 0; j < cntz; j++){
			if(z_s[j] == oriz[i])sz=j;
			if(z_s[j] == oriz[i+1]){
				fz=j;
				break;
			}
		}
		for(long long j = sx+1; j < fx+1; j++){
			for(long long k = sy+1; k < fy+1; k++){
				for(long long l = sz+1; l < fz+1; l++){
					xyz[j][k][l]++;
					counting++;
				}
			}
		}
	}
}
void calc(){
	for(long long i = 0; i < cntx; i++){
		for(long long j = 0; j < cnty; j++){
			for(long long k = 0; k < cntz; k++){
				if(xyz[i][j][k] > 1){
					sum += (x_s[i]-x_s[i-1])*(y_s[j]-y_s[j-1])*(z_s[k]-z_s[k-1]);
				}
			}
		}
	}
	fprintf(output,"%lld",sum);
}