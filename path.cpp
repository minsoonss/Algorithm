#include <cstdio>

FILE *input;
FILE *output;
int grid[1001][1001];
void calc();
int main(){
	input = fopen("path.inp","r");
	output = fopen("path.out","w");
	int testcase = 0;
	fscanf(input,"%d",&testcase);
	for(int i = 0; i < 1001; i++){ //dpÅ×ÀÌºí
		for(int j = 0; j < 1001; j++){
			if(i == 0 || j == 0)grid[i][j] = 1;
			else{
				if(grid[i][j-1]+grid[i-1][j] > 10007){
					grid[i][j] = (grid[i][j-1]%10007+grid[i-1][j]%10007)%10007;
				}
				else{
					grid[i][j] = grid[i][j-1]+grid[i-1][j];
				}
			}
		}
	}
	for(int i = 0; i < testcase; i++){
		calc();
	}
	return 0;
}
void calc(){
	int start1,start2;
	int end1, end2;
	int path1, path2;
	fscanf(input,"%d %d %d %d",&start1,&start2,&end1,&end2);
	path1 = start1 > end1 ? start1-end1 : end1-start1;
	path2 = start2 > end2 ? start2-end2 : end2-start2;
	fprintf(output,"%d\n",grid[path1][path2]);
}