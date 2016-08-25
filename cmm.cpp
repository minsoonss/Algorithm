//#include <cstdio>
//#include <cstring>
//typedef struct dir{
//	int left;
//	int right;
//}dir;
//FILE *input = fopen("cmm.inp","r");
//FILE *output = fopen("cmm.out","w");
//int num;
//dir redp[51];
//int P[51][51] = {0,};
//void init(int d[51]);
//void g1(int d[51]);
//void g2(int d[51]);
//void dp(int d[51]);
//void recursion(int l, int c, int r); //dp괄호출력
//int main(){
//	int testcase = 0;
//	fscanf(input,"%d",&testcase);
//	int T = testcase;
//	while(testcase--){
//		int d[51] = {0,};
//		fprintf(output,"Test Case Number : %d\n",T-testcase);
//		init(d);
//		g2(d); //끝
//		g1(d); //끝
//		dp(d);
//	}
//}
//void init(int d[51]){
//	int count = 0;
//	char newline;
//	fscanf(input,"%d",&num);
//	for(int i = 0; i <= num; i++){
//		fscanf(input,"%d",&d[i]);
//	}
//}
//void g1(int d[51]){//p가큰값 num은 d의수
//	int flag[51] = {0,};
//	int min = -1;
//	int index;
//	dir oc[51] = {0,};
//	int flagcount = 0;
//	long long int result = 0;
//	int resultp = 0;
//	//감싸는반복필요
//	while(flagcount < num-2){
//		int n = 0;
//		int m = 0;
//		int p = 0;
//		min = -1;
//		for(int i = 1; i < num; i++){
//			if(flag[i] == 0 && d[i] > min){
//				min = d[i];
//				index = i;
//			}
//		}
//		flag[index] = 1;
//		p = d[index];
//		flagcount++;
//		int left = index-1;
//		int right = index+1;
//		while(1){
//			if(flag[left] == 0){
//				oc[left+1].left++;
//				n = d[left];
//				break;
//			}
//			else{
//				left--;
//			}
//		}
//		while(1){
//			if(flag[right] == 0){
//				oc[right].right++;
//				m = d[right];
//				break;
//			}
//			else{
//				right++;
//			}
//		}
//		//여기까지 감싸는반복 필요
//		result += n*m*p;
//	}
//	for(int i = 1; i < num; i++){
//		if(flag[i] == 0){
//			resultp = d[i];
//			break;
//		}
//	}
//	result += d[0]*resultp*d[num];
//	fprintf(output,"%lld ",result);
//	for(int i = 1; i <= num; i++){
//		for(int j = 0; j < oc[i].left; j++){
//			fprintf(output,"(");
//		}
//		fprintf(output,"A%d",i);
//		for(int j = 0; j < oc[i].right; j++){
//			fprintf(output,")");
//		}
//	}
//	fprintf(output,"\n");
//}
//void g2(int d[51]){//m*n이큰값
//	int flag[51] = {0,};
//	int max = 987654321;
//	int index;
//	dir oc[51] = {0,};
//	int flagcount = 0;
//	long long int result = 0;
//	int resultp = 0;
//	while(flagcount < num-2){
//		max = 987654321;
//		int n = 0;
//		int m = 0;
//		int p = 0;
//		for(int i = 0; i < num-1; i++){
//			int j = 0;
//			int k = 0;
//			if(flag[i] == 0){ //i가 n이라 가정
//				for(j = i+1; j < num; j++){
//					if(flag[j] == 0){
//						break;
//					}
//				}
//				for(k = j+1; k <= num; k++){
//					if(flag[k] == 0){
//						break;
//					}
//				}
//			}
//			if(d[i]*d[k] < max && flag[i] == 0 && i <= num && j < num && k <= num){
//				max = d[i]*d[k];
//				n = i;
//				m = k;
//				p = j;
//			}
//		}
//		flag[p] = 1;
//		flagcount++;
//		oc[n+1].left++;
//		oc[m].right++;
//		result += d[n]*d[m]*d[p];
//	}
//	for(int i = 1; i < num; i++){
//		if(flag[i] == 0){
//			resultp = d[i];
//			break;
//		}
//	}
//	result += d[0]*d[num]*resultp;
//	fprintf(output,"%lld ",result);
//	for(int i = 1; i <= num; i++){
//		for(int j = 0; j < oc[i].left; j++){
//			fprintf(output,"(");
//		}
//		fprintf(output,"A%d",i);
//		for(int j = 0; j < oc[i].right; j++){
//			fprintf(output,")");
//		}
//	}
//	fprintf(output,"\n");
//}
//void dp(int d[51]){
//	memset(redp,0,sizeof(redp));
//	long long int M[51][51] = {0,};
//	memset(P,0,sizeof(P));
//	int k = 1;
//	long long int max = 98765432100000;
//	int index = 0;
//	//초기화
//	for(int i = 1; i < num; i++){
//		for(int j = i+1; j < i+2; j++){
//			M[i][j] = d[i-1]*d[i]*d[j];
//			P[i][j] = i;
//		}
//	}
//	//여기까지
//	for (int i = 1; i <num; i++){
//		for (int j = i+k+1; j <= i+k+1; j++){
//			max = 98765432100000;
//			for(int l = i; l < j; l++){
//				if(max > M[i][l]+M[l+1][j]+d[i-1]*d[l]*d[j]){
//					max = M[i][l]+M[l+1][j]+d[i-1]*d[l]*d[j];
//					M[i][j] = M[i][l]+M[l+1][j]+d[i-1]*d[l]*d[j];
//					index = l;
//				}
//
//			}
//			P[i][j] = index;
//			if(j == num){
//				k++;
//				i=0;
//				break;
//			}
//		}
//		if(M[1][num] != 0)break;
//	}
//	fprintf(output,"%lld ",M[1][num]);
//	recursion(1,P[1][num],num);//처음 갈라지는곳 끝
//	for(int i = 1; i <= num; i++){
//		for(int j = 0; j < redp[i].left; j++){
//			fprintf(output,"(");
//		}
//		fprintf(output,"A%d",i);
//		for(int j = 0; j < redp[i].right; j++){
//			fprintf(output,")");
//		}
//	}
//	fprintf(output,"\n");
//}
//void recursion(int l, int c, int r){
//	if(c-l >= 1){
//		redp[c].right++;
//		redp[l].left++;
//		recursion(l,P[l][c],c);
//	}
//	if(r-c > 1){
//		redp[c+1].left++;
//		redp[r].right++;
//		recursion(c+1,P[c+1][r],r);
//	}
//}