#include <cstdio>

int x, y;
FILE *input, *output;
void calc();
bool check(int cx, int cy, int x, int y);
int main(){
	input = fopen("fraction.inp","r");
	output = fopen("fraction.out","w");
	while(true){
		fscanf(input,"%d %d",&x,&y);
		if(x == 1 && y == 1)break;
		calc();
	}
}
void calc(){
	int cx = 1;
	int cy = 1;
	int lx = 0;
	int ly = 1;
	int rx = 1;
	int ry = 0;
	while(true){
		if(cx == x && cy == y)break;
		if(check(cx,cy,x,y)){ //좌측으로내려감
			fprintf(output,"L");
			rx = cx;
			ry = cy;
			cx += lx;
			cy += ly;
		}
		else{
			fprintf(output,"R");
			lx = cx;
			ly = cy;
			cx += rx;
			cy += ry;
		}
	}
	fprintf(output,"\n");
}
bool check(int cx, int cy, int x, int y){
	double c;
	double normal;
	c = (double)cx/cy;
	normal = (double)x/y;
	if(c > normal)return true;
	else return false;
}