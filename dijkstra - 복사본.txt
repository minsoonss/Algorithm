#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

typedef struct info{
	int s;
	int t;
	int w; //가중치
	int num; //들어온 순서
}info;
FILE *input = fopen("dijkstra.inp","r");
FILE *output = fopen("dijkstra.out","w");
priority_queue<info, vector<info>, greater<info> > minHeap;
int n,m;
info ver[10001][10001];
int flag[10001];
int weight[10001];
int	route[10001];
void init();
void dijkstra(int num);
void print(int num);
bool operator>(const info& a,const info& b){
	if (a.w == b.w)
		return a.num < b.num;
	else
		return a.w > b.w;
}
int main(){
	init();
	dijkstra(0);
	for(int i = 1; i < n; i++){
		print(i);
		if(weight[i] == 0){
			fprintf(output,"V%d (%d)\n",i,-1);
		}
		else{
			fprintf(output,"(%d)\n",weight[i]);
		}
	}
}
void init(){
	fscanf(input,"%d %d",&n,&m);
	for(int i = 0; i < m; i++){
		int a = 0;
		int b = 0;
		fscanf(input,"%d %d",&a,&b);
		fscanf(input,"%d",&ver[a][b].w);
		ver[a][b].num = i;
	}
	for(int i = 0; i < n; i++){
		route[i] = -1;
	}
}
void dijkstra(int num){
	info a;
	info b;
	int base = 0;
	for(int index = 0; index < n-1; index++){
		flag[num] = 1;
		for(int i = 0; i < n; i++){
			if(ver[num][i].w != 0 && flag[i] == 0){
				if(route[num] == -1)base = 0;
				else base = weight[num];
				a.num = ver[num][i].num;
				a.s = num;
				a.t = i;
				a.w = ver[num][i].w+base;
				minHeap.push(a);
			}
		}
		for(;;){
			if(minHeap.empty())break;
			b = minHeap.top();
			if(flag[b.t] == 0){
				flag[b.t] = 1;
				route[b.t] = b.s;
				num = b.t;
				weight[b.t] = b.w;
				break;
			}
			else{
				minHeap.pop();
			}
			
		}
	}
}
void print(int num){
	if(route[num] == -1){
		fprintf(output,"V0 ");
		return;
	}
	else{
		print(route[num]);
		fprintf(output,"V%d ",num);
	}
}