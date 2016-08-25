//#include <cstdio>
//
//struct maze{
//	int n,s,w,e;
//};
//FILE *in = fopen("maze.inp","r");
//FILE *out = fopen("maze.out","w");
//maze mirotic[500][500];
//bool flag[500][500];
//int x,y;
//bool check;
//int count;
//int path[500];
//void input();
//void recur(int a, int b, int num);
//int main(){
//	input();
//	flag[0][0] = true;
//	recur(0,0,0);
//	if(check == false)fprintf(out,"No Solution!");
//	else{
//		for(int i = count-1; i >= 0; i--){
//			fprintf(out,"%d\n",path[i]);
//		}
//	}
//}
//void input(){
//	fscanf(in,"%d %d",&x,&y);
//	int a,b;
//	while(1){
//		fscanf(in,"%d %d",&a,&b);
//		if(a == -1)break;
//		if(b == 1){
//			mirotic[a/y][a%y].e = 1;
//			mirotic[a/y][a%y+1].w = 1;
//		}
//		else if(b == 2){
//			mirotic[a/y][a%y].s = 1;
//			mirotic[a/y+1][a%y].n = 1;
//		}
//		else if(b == 3){
//			mirotic[a/y][a%y].e = 1;
//			mirotic[a/y][a%y].s = 1;
//			mirotic[a/y][a%y+1].w = 1;
//			mirotic[a/y+1][a%y].n = 1;
//		}
//	}
//}
//void recur(int a, int b, int num){
//	if(num == x*y-1 || check == true){
//		check = true;
//		path[count++] = num;
//		return;
//	}
//	//悼率
//	if(mirotic[a][b].e == 1 && flag[a][b+1] == false){
//		flag[a][b] = true;
//		recur(a,b+1,num+1);
//		if(check == true){
//			path[count++] = num;
//			return;
//		}
//		flag[a][b] = false;
//	}
//	//巢率
//	if(mirotic[a][b].s == 1 && flag[a+1][b] == false){
//		flag[a][b] = true;
//		recur(a+1,b,num+y);
//		if(check == true){
//			path[count++] = num;
//			return;
//		}
//		flag[a][b] = false;
//	}
//	//合率
//	if(mirotic[a][b].n == 1 && flag[a-1][b] == false){
//		flag[a][b] = true;
//		recur(a-1,b,num-y);
//		if(check == true){
//			path[count++] = num;
//			return;
//		}
//		flag[a][b] = false;
//	}
//	//辑率
//	if(mirotic[a][b].w == 1 && flag[a][b-1] == false){
//		flag[a][b] = true;
//		recur(a,b-1,num-1);
//		if(check == true){
//			path[count++] = num;
//			return;
//		}
//		flag[a][b] = false;
//	}
//}