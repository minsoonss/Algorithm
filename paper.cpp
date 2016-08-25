#include <cstdio>
#include<algorithm>
using namespace std;
FILE *input, *output;
int xy[5000][5000];
int x[5000];
int y[5000];
int orix[5000];
int oriy[5000];
int x_s[5000];
int y_s[5000];
int comp[2][5000];
int pNum;

int main(){
	int count[3] = {0,};
	int numcount = 1;
	input = fopen("paper.inp","r");
	output = fopen("paper.out","w");
	fscanf(input,"%d",&pNum);
	for(int i = 0; i < pNum*2; i+=2){
		fscanf(input,"%d %d %d %d",&x[i],&y[i],&x[i+1],&y[i+1]);
		orix[i] = x[i];
		oriy[i] = y[i];
		x[i+1] += x[i];
		y[i+1] += y[i];
		orix[i+1] = x[i+1];
		oriy[i+1] = y[i+1];
	}

	sort(x,x+pNum*2);
	sort(y,y+pNum*2);
	int cntx=0,cnty=0;
	for(int i=0;i<pNum*2;i++){
		  if(x[i] != x[i-1]){
			  x_s[cntx] = x[i];
			  cntx++;
		  }
		  if(y[i] != y[i-1]){
			  y_s[cnty] = y[i];
			  cnty++;
		  }
	}
	/////////////////////////////////////

	for(int i = 0;i<pNum*2-1; i+=2){
		int sx,sy,fx,fy;
		for(int j = 0; j < cntx; j++){
			if(x_s[j] == orix[i])sx = j;
			if(x_s[j] == orix[i+1]){
				fx = j;
				break;
			}
		}
		for(int k = 0; k < cnty; k++){
			if(y_s[k] == oriy[i])sy = k;
			if(y_s[k] == oriy[i+1]){
				fy = k;
				break;
			}
		}
		for(int j = sx; j < fx; j++){
			for(int k = sy; k < fy; k++){
				xy[j][k] = numcount;
				comp[0][numcount]++;
			}
		}
		numcount++;
	}

	for(int i = 0; i < cntx; i++){
		for(int j = 0; j < cnty; j++){
			comp[1][xy[i][j]]++;
		}
	}
	for(int i = 1; i < pNum+1; i++){
		if(comp[0][i] == comp[1][i]){
			count[2]++;
		}
		else if(comp[1][i] == 0){
			count[0]++;
		}
		else{
			count[1]++;
		}
	}

	fprintf(output,"%d %d %d",count[0],count[1],count[2]);
	fclose(input);
	fclose(output);
	return 0;
}
