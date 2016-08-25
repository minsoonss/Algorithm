//#include <cstdio>
//#include <algorithm>
//#include <queue>
//#include <queue>
//#include <functional>
//using namespace std;
//
//typedef struct info{
//	int w,num,x,y;
//}info;
//typedef struct xy{
//	int num;
//	int w;
//}xy;
//
//priority_queue<xy, vector<xy>, greater<xy> > minHeap;
//
//bool operator>(const xy& A, const xy& B){
//	if (A.w == B.w)
//		return A.num > B.num;
//	else
//		return A.w > B.w;
//}
//FILE *input = fopen("mst.inp","r");
//FILE *output = fopen("mst.out","w");
//xy ver[10000][10000];
//info kruskal[100000];
//void init();
//void mstp(int num);
//void mstk();
//bool compare(info a, info b){
//	if(a.w < b.w) return true;
//	else if(a.w == b.w){
//		if(a.num < b.num){
//			return true;
//		}
//		else return false;
//	}
//	else return false;
//}
//int n; int m; //n 정점 m 간선 수
//int main(){
//	fscanf(input,"%d %d",&n,&m);
//	init();
//	//mstk();
//	mstp(0);
//	//mstp(n/2);
//	//mstp(n-1);
//}
//void init(){
//	int x,y,weight;
//	for(int i = 0; i < m; i++){
//		fscanf(input,"%d %d %d",&x,&y,&weight);
//		kruskal[i].x = x;
//		kruskal[i].y = y;
//		kruskal[i].w = weight;
//		kruskal[i].num = i;
//		ver[x][y].w = ver[y][x].w = weight;
//		ver[x][y].num = ver[y][x].num = i;
//	}
//	sort(kruskal,kruskal+m,compare);
//}
//void mstk(){ //크루스칼
//	int find[10000] = {0,}; //헤드표시
//	int result = 0;
//	int tempx,tempy;
//	int count = 0;
//	int procedure[10000] = {0,};
//	int index = 0;
//	for(int i = 0; i < n; i++){
//		find[i] = i;
//	}
//	for(int i = 0; i < m; i++){
//		tempx = find[kruskal[i].x];
//		tempy = find[kruskal[i].y];
//		if(index == n)break;
//		if(tempx != tempy){
//			result += kruskal[i].w;
//			procedure[index] = kruskal[i].num;
//			index++;
//			for(int j = 0; j < n; j++){
//				if(find[j] == tempx){
//					find[j] = tempx;
//				}
//				else if(find[j] == tempy){
//					find[j] = tempx;
//				}
//			}
//		}
//	}
//	fprintf(output,"Tree edges by Kruskal algorithm: %d\n",result);
//	for(int i = 0; i < n-1; i++){
//		fprintf(output,"%d\n",procedure[i]);
//	}
//}
//void mstp(int num){ //프림
//	int flag[10000] = {0,};
//	int procedure[10000] = {0,};
//	int printnum = num;
//	int result = 0;
//	int number = 0;
//	int index = 0;
//	int temp = 0;
//	int min = 10001;
//	xy weight[10000] = {0,};
//	flag[num] = 1;
//	for(int i = 0; i < n; i++){ //max이상으로 초기화
//		weight[i].w = 10001;
//	}
//	for(;;){
//		min = 10001;
//		for(int i = 0; i < n; i++){
//			if(ver[num][i].w != 0 && ver[num][i].w <= weight[i].w && flag[i] == 0){
//				if(ver[num][i].w == weight[i].w){
//					if(ver[num][i].num < weight[i].num){
//						weight[i].w = ver[num][i].w;
//						weight[i].num = ver[num][i].num;
//					}
//				}
//				else{
//					weight[i].w = ver[num][i].w;
//					weight[i].num = ver[num][i].num;
//				}
//			}
//		}
//		for(int i = 0; i < n; i++){
//			if(min >= weight[i].w && flag[i] == 0){
//				if(min == weight[i].w){
//					if(weight[i].num < number){
//						min = weight[i].w;
//						number = weight[i].num;
//						temp = i;
//					}
//				}
//				else{
//					min = weight[i].w;
//					number = weight[i].num;
//					temp = i;
//				}
//			}
//		}
//		flag[temp] = 1;
//		result += min;
//		procedure[index] = number;
//		index++;
//		num = temp;
//		if(index == n-1)break;
//	}
//	fprintf(output,"Tree edges by Prim algorithm with starting vertex %d: %d\n",printnum,result);
//	for(int i = 0; i < n-1; i++){
//		fprintf(output,"%d\n",procedure[i]);
//	}
//}