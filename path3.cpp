#include <cstdio>
#include <cstdlib>
#define abs(x)        ( ((x)<0)?-(x):(x) )
struct info{
	bool e,s,w,n;//동,남,서,북 우선순위고려
	int prex,prey,min;//이전경로,최소값
	int v;//값
};
struct pf{
	int x,y,v;
};
FILE *in = fopen("path3.inp","r");
FILE *out = fopen("path3.out","w");
info path[101][101];
pf result[1000000];
bool flag[101][101];
int d,n,m;
bool check;
int count;
void input();
void calc(int a, int b);
void calc2(int a, int b, int x, int y);
void print();
int main(){
	input();
	flag[0][0] = true;
	calc(0,0);
	if(check == false)fprintf(out,"Impossible!");
	else{
		fprintf(out,"(0 0) [%d]\n",path[0][0].v);
		print();
	}
}
void input(){//입력받고 동 남 서 북을 갈 수 있는지
	char a;
	fscanf(in,"%d %d %d",&d,&n,&m);
	for(int i = 0; i < n; i++){
		fscanf(in,"\n");
		for(int j = 0; j < m; j++){
			fscanf(in,"%c",&a);
			path[i][j].v = a-48;
			if(i == 0 && j == 0);
  		else path[i][j].min = 99999999;
		}
	}//입력끝
	for(int i = 0; i < n; i++){	//동남서북
		for(int j = 0; j < m; j++){
			if(j < m-1){//동쪽체크
				int a = abs(path[i][j].v-path[i][j+1].v);
				if(a > 5)a = 10-a;
				if(a <= d){
					path[i][j].e = true;
					path[i][j+1].w = true;
				}
			}
			if(i < n-1){//남쪽체크
				int a = abs(path[i][j].v-path[i+1][j].v);
				if(a > 5)a = 10-a;
				if(a <= d){
					path[i][j].s = true;
					path[i+1][j].n = true;
				}
			}
		}
	}//체크끝
}
void calc(int a, int b){
	if(a == n-1 && b == m-1){
		check = true;
		return;
	}
	if(path[a][b].e == true && flag[a][b+1] == false && path[a][b+1].min > path[a][b].min+1 && m > b+1){//동
		calc2(a,b,0,1);
		calc(a,b+1);
		flag[a][b+1] = false;
	}
	if(path[a][b].s == true && flag[a+1][b] == false && path[a+1][b].min > path[a][b].min+1 && n > a+1){//남
		calc2(a,b,1,0);
		calc(a+1,b);
		flag[a+1][b] = false;
	}
	if(path[a][b].w == true && flag[a][b-1] == false && path[a][b-1].min > path[a][b].min+1 && 0 <= b-1){//서
		calc2(a,b,0,-1);
		calc(a,b-1);
		flag[a][b-1] = false;
	}
	if(path[a][b].n == true && flag[a-1][b] == false && path[a-1][b].min > path[a][b].min+1 && 0 <= a-1){//북
		calc2(a,b,-1,0);
		calc(a-1,b);
		flag[a-1][b] = false;
	}
}
void calc2(int a, int b, int x, int y){
	flag[a+x][b+y] = true;
	path[a+x][b+y].min = path[a][b].min+1;
	path[a+x][b+y].prex = a;
	path[a+x][b+y].prey = b;
}
void print(){
	int x = n-1;
	int y = m-1;
	while(true){
		result[count].x = x;
		result[count].y = y;
		result[count].v = path[x][y].v;
		x = path[result[count].x][result[count].y].prex;
		y = path[result[count].x][result[count].y].prey;
		if(x == 0 && y == 0)break;
		count++;
	}
	for(int i = count; i >= 0; i--){
		fprintf(out,"(%d %d) [%d]\n",result[i].x,result[i].y,result[i].v);
	}
}
