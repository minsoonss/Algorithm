#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define Max 2100000000
FILE *in = fopen("color.inp","r");
FILE *out = fopen("color.out","w");
char a[5005], b[5005];
int lengthA, lengthB;
int dp[5005][5005], ta[5005][26], tb[5005][26];
void init();
void calc();
int finish(int posA, int posB, char ch);
int start(int posA, int posB, char ch);
int main() {
	int testcase, i, j;
	fscanf(in,"%d\n",&testcase);
	for(int index = 0; index < testcase; index++) {
		init();
		calc();
	}
	return 0;
}
void init(){
	a[0] = b[0] = ' ';
	fscanf(in,"%s",a+1);
	fscanf(in,"%s",b+1);
	lengthA = strlen(a);
	lengthB = strlen(b);
}
int finish(int posA, int posB, char ch) {
	ch -= 'A';
	if(ta[posA][ch]+tb[posB][ch] == ta[lengthA-1][ch]+tb[lengthB-1][ch])
		return posA+posB;
	return 0;
}
int start(int posA, int posB, char ch) {
	ch -= 'A';
	if(ta[posA][ch] + tb[posB][ch] == 1)
		return posA+posB;
	return 0;
}
void calc(){
	int i,j;
	for(i = 0; i < 26; i++)
		ta[0][i] = tb[0][i] = 0;
	for(i = 1; i < lengthA; i++) {
		for(j = 0; j < 26; j++)
			ta[i][j] = ta[i-1][j];
		ta[i][a[i]-'A']++;
	}
	for(i = 1; i < lengthB; i++) {
		for(j = 0; j < 26; j++)
			tb[i][j] = tb[i-1][j];
		tb[i][b[i]-'A']++;
	}
	for(i = 0; i < lengthA; i++)
		for(j = 0; j < lengthB; j++)
			dp[i][j] = Max;
	dp[0][0] = 0;
	for(i = 0; i < lengthA; i++) {
		for(j = 0; j < lengthB; j++) {
			dp[i+1][j] = min(dp[i+1][j], dp[i][j]+finish(i+1, j, a[i+1])-start(i+1, j, a[i+1]));
			dp[i][j+1] = min(dp[i][j+1], dp[i][j]+finish(i, j+1, b[j+1])-start(i, j+1, b[j+1]));
		}
	}
	fprintf(out,"%d\n", dp[lengthA-1][lengthB-1]);
}