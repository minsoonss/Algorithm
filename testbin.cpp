#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

FILE *in = fopen("bin.inp","r");
FILE *out = fopen("bin.out","w");
int arr[500];
int brr[500];
int dp[500][500];
int houseNum, binNum;
int result = 2100000000;
int minimum = 2100000000;
int cost = 0;
int nextdis = 0;
int postdis = 0;
int predis = 0;
bool input();
int calc(int houseNum, int binNum);
int main(){
	int t;
	bool c = true;
	fscanf(in,"%d",&t);
	for(int i = 0; i < t; i++){
		c = input();
		if(c == true)return 0;
		else printf("%d\n",calc(houseNum,binNum));
		memset(dp,0,sizeof(dp));
		memset(arr,0,sizeof(arr));
		memset(brr,0,sizeof(brr));
		result = 2100000000;
		minimum = 2100000000;
		c = true;
		cost = 0;
		nextdis = 0;
		postdis = 0;
		predis = 0;
	}
}
bool input(){
	fscanf(in,"%d %d",&houseNum,&binNum);
	if(houseNum == binNum){
		fprintf(out,"%d\n",0);
		return true;
	}
	else{
		for(int i = 0; i < houseNum; i++){
			fscanf(in,"%d",&arr[i]);
		}
		sort(arr,arr+houseNum);
		return false;
	}
}
int calc(int houseNum, int binNum){
	for (int i = 0; i < houseNum; i++){
		int dis=0;
		for (int j = i+1; j < houseNum; j++){
			dis += (arr[j] - arr[i]);
		}
		nextdis = dis;
		dis = 0;
		for (int j = 0; j < i; j++){
			dis += (arr[i] - arr[j]);
		}
		dp[1][i] = dis + nextdis;
		brr[i] = nextdis;

		if (result > dp[1][i]){
			result = dp[1][i];
		}
	}
	if (binNum == 1){
		return result;
	}
	for (int bin = 2; bin <= binNum; bin++){
		for (int pos = 0; pos < houseNum; pos++){
			minimum = 2100000000;
			if (pos < bin - 1){
				dp[bin][pos] = dp[bin-1][pos];
			}
			for (int tPos = 0; tPos < pos; tPos++){
				postdis = brr[pos];
				predis = dp[bin-1][tPos] - brr[tPos];
				cost = predis + postdis;
				for (int j = tPos+1; j < pos; j++){
					if (arr[j] > arr[tPos] && arr[j] < arr[pos]){
						cost += min((arr[j] - arr[tPos]), (arr[pos] - arr[j]));
					}
				}
				if (cost < minimum){
					minimum = cost;
				}
			}
			dp[bin][pos] = minimum;
			if (minimum < result && bin == binNum){
				result = minimum;
			}
		}
	}
	return result;
}