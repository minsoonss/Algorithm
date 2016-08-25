#include <cstdio>

long long grid[1001][1001];
FILE *input,*output;
void calc();
void init();
int main(){
	input = fopen("path2.inp","r");
	output = fopen("path2.out","w");
	int testcase = 0;
	fscanf(input,"%d",&testcase);
	init();
	for(int i = 0; i < testcase; i++){
		calc();
	}
}
void calc(){
	int vertical = 0;
	int horizen = 0;
	int onecheck = 0;
	int twocheck = 0;
	int start1,start2,end1,end2;
	int firstgas1,firstgas2,secondgas1,secondgas2;
	int path1,path2;
	int gas1,gas2;
	int compare1,compare2;

	fscanf(input,"%d %d %d %d %d %d %d %d",
		&start1,&start2,&end1,&end2,&firstgas1,&firstgas2,&secondgas1,&secondgas2);
	//주유소위치파악
	if(start1 >= firstgas1 && firstgas1 >= end1){
		if(start2 <= firstgas2 && firstgas2 <= end2){
			onecheck++;
		}
	}
	if(start1 <= firstgas1 && firstgas1 <= end1){
		if(start2 <= firstgas2 && firstgas2 <= end2){
			onecheck++;
		}
	}
	if(start1 >= firstgas1 && firstgas1 >= end1){
		if(start2 >= firstgas2 && firstgas2 >= end2){
			onecheck++;
		}
	}
	if(start1 <= firstgas1 && firstgas1 <= end1){
		if(start2 >= firstgas2 && firstgas2 >= end2){
			onecheck++;
		}

	}
	if(start1 <= secondgas1 && secondgas1 <= end1){
		if(start2 <= secondgas2 && secondgas2 <= end2){
			twocheck++;
		}
	}
	if(start1 >= secondgas1 && secondgas1 >= end1){
		if(start2 >= secondgas2 && secondgas2 >= end2){
			twocheck++;
		}
	}
	if(start1 <= secondgas1 && secondgas1 <= end1){
		if(start2 >= secondgas2 && secondgas2 >= end2){
			twocheck++;
		}
	}
	if(start1 >= secondgas1 && secondgas1 >= end1){
		if(start2 <= secondgas2 && secondgas2 <= end2){
			twocheck++;
		}
	
	}
	//출발점에서 firstgas까지 혹은 firstgas에서 도착점까지안에 secondgas가있는지 확인
	gas1 = firstgas1 > start1 ? firstgas1-start1 : start1-firstgas1;
	gas2 = firstgas2 > start2 ? firstgas2-start2 : start2-firstgas2;
	path1 = secondgas1 > start1 ? secondgas1-start1 : start1-secondgas1;
	path2 = secondgas2 > start2 ? secondgas2-start2 : start2-secondgas2;
	if(gas1 >= path1 && gas2 >= path2){
		vertical = 1;
	}
	gas1 = firstgas1 > end1 ? firstgas1-end1 : end1-firstgas1;
	gas2 = firstgas2 > end2 ? firstgas2-end2 : end2-firstgas2;
	path1 = secondgas1 > end1 ? secondgas1-end1 : end1-secondgas1;
	path2 = secondgas2 > end2 ? secondgas2-end2 : end2-secondgas2;
	if(gas1 >= path1 && gas2 >= path2){
		vertical = 1;
	}
	//
	if(onecheck >= 1 && twocheck >= 1){//주유소두개가 범위안에있음
		long long result = 0;
		if(/*(firstgas1 <= secondgas1 && firstgas2 <= secondgas2)||
			(firstgas1 >= secondgas1 && firstgas2 >= secondgas2)||
			(firstgas1 <= secondgas1 && firstgas2 >= secondgas2)&&*/ vertical ==	1)
		{ //두개를 공통으로 거쳐갈수 있는경우 
			gas1 = start1 > firstgas1 ? start1-firstgas1 : firstgas1-start1;
			gas2 = start2 > firstgas2 ? start2-firstgas2 : firstgas2-start2;
			path1 = firstgas1 > end1 ? firstgas1-end1 : end1-firstgas1;
			path2 = firstgas2 > end2 ? firstgas2-end2 : end2-firstgas2;
			result = ((grid[gas1][gas2]%1000007) * (grid[path1][path2]%1000007))%1000007;

			gas1 = start1 > secondgas1 ? start1-secondgas1 : secondgas1-start1;
			gas2 = start2 > secondgas2 ? start2-secondgas2 : secondgas2-start2;
			path1 = secondgas1 > end1 ? secondgas1-end1 : end1-secondgas1;
			path2 = secondgas2 > end2 ? secondgas2-end2 : end2-secondgas2;
			result = (result+((grid[gas1][gas2]%1000007) * (grid[path1][path2]%1000007))%1000007)%1000007;
			//result = result%1000007;
			compare1 = start1 > firstgas1 ? start1 - firstgas1 : firstgas1 - start1;
			compare1 += start2 > firstgas2 ? start2 - firstgas2 : firstgas2 - start2;
			compare2 = start1 > secondgas1 ? start1 - secondgas1 : secondgas1 - start1;
			compare2 += start2 > secondgas2 ? start2 - secondgas2 : secondgas2 - start2; //글쿤
			if(compare1 < compare2){ //firstgas가 더 가까운경우 시작-firstgas-secondgas-end
				gas1 = start1 > firstgas1 ? start1-firstgas1 : firstgas1-start1;
				gas2 = start2 > firstgas2 ? start2-firstgas2 : firstgas2-start2;
				path1 = firstgas1 > secondgas1 ? firstgas1-secondgas1 : secondgas1-firstgas1;
				path2 = firstgas2 > secondgas2 ? firstgas2-secondgas2 : secondgas2-firstgas2;
				end1 = secondgas1 > end1 ? secondgas1-end1 : end1-secondgas1;
				end2 = secondgas2 > end2 ? secondgas2-end2 : end2-secondgas2;
				result = ((result%1000007)-((((grid[gas1][gas2]%1000007)*(grid[path1][path2]%1000007))%1000007)*(grid[end1][end2]%1000007))%1000007)%1000007;
				result = (result+1000007)%1000007;
				fprintf(output,"%d\n",result);
			} // 얼추맞는거같긴한디 그럼 출력한번해볼게
			else{ //secondgas가 더 가까운 경우 시작 secondgas-firstgas-end
				gas1 = start1 > secondgas1 ? start1-secondgas1 : secondgas1-start1;
				gas2 = start2 > secondgas2 ? start2-secondgas2 : secondgas2-start2;
				path1 = firstgas1 > secondgas1 ? firstgas1-secondgas1 : secondgas1-firstgas1;
				path2 = firstgas2 > secondgas2 ? firstgas2-secondgas2 : secondgas2-firstgas2;
				end1 = firstgas1 > end1 ? firstgas1-end1 : end1-firstgas1;
				end2 = firstgas2 > end2 ? firstgas2-end2 : end2-firstgas2;
				result = ((result%1000007)-((((grid[gas1][gas2]%1000007)*(grid[path1][path2]%1000007))%1000007)*(grid[end1][end2]%1000007))%1000007)%1000007;
				result = (result+1000007)%1000007;
				fprintf(output,"%d\n",result);
			}
		
		}

		else{ //두개를 따로지나가야하는경우
			gas1 = start1 > firstgas1 ? start1-firstgas1 : firstgas1-start1;
			gas2 = start2 > firstgas2 ? start2-firstgas2 : firstgas2-start2;
			path1 = end1 > firstgas1 ? end1-firstgas1 : firstgas1-end1;
			path2 = end2 > firstgas2 ? end2-firstgas2 : firstgas2-end2;
			result = ((grid[gas1][gas2]%1000007)*(grid[path1][path2]%1000007))%1000007;
			gas1 = start1 > secondgas1 ? start1-secondgas1 : secondgas1-start1;
			gas2 = start2 > secondgas2 ? start2-secondgas2 : secondgas2-start2;
			path1 = end1 > secondgas1 ? end1-secondgas1 : secondgas1-end1;
			path2 = end2 > secondgas2 ? end2-secondgas2 : secondgas2-end2;
			result += ((grid[gas1][gas2]%1000007)*(grid[path1][path2]%1000007))%1000007;
			fprintf(output,"%d\n",result%1000007);
		}
	}
	else if(onecheck == 1){ //첫번째 주유소만 범위안에있음
		int result = 0;
		gas1 = start1 > firstgas1 ? start1-firstgas1 : firstgas1-start1;
		gas2 = start2 > firstgas2 ? start2-firstgas2 : firstgas2-start2;
		end1 = firstgas1 > end1 ? firstgas1-end1 : end1-firstgas1;
		end2 = firstgas2 > end2 ? firstgas2-end2 : end2-firstgas2;
		result = ((grid[gas1][gas2]%1000007) * (grid[end1][end2]%1000007))%1000007;
		fprintf(output,"%d\n",result);
	}
	else if(twocheck == 1){ //두번째 주유소만 범위안에있음
		int result = 0;
		gas1 = start1 > secondgas1 ? start1-secondgas1 : secondgas1-start1;
		gas2 = start2 > secondgas2 ? start2-secondgas2 : secondgas2-start2;
		end1 = secondgas1 > end1 ? secondgas1-end1 : end1-secondgas1;
		end2 = secondgas2 > end2 ? secondgas2-end2 : end2-secondgas2;
		result = ((grid[gas1][gas2]%1000007) * (grid[end1][end2]%1000007))%1000007;
		fprintf(output,"%d\n",result);
	}
	else{ //어느주유소도 범위안에 없음
		fprintf(output,"0\n"); 
	}
}
void init(){
	for(int i = 0; i < 1001; i++){ //dp테이블
		for(int j = 0; j < 1001; j++){
			if(i == 0 || j == 0)grid[i][j] = 1;
			else{
				if(grid[i][j-1]+grid[i-1][j] >= 1000007){
					grid[i][j] = ((grid[i][j-1]%1000007)+(grid[i-1][j]%1000007))%1000007;
				}
				else{
					grid[i][j] = grid[i][j-1]+grid[i-1][j];
				}
			}
		}
	}
}