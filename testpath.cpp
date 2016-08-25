#include <stdio.h>
#include <deque>
#pragma warning(disable:4996)
#define MAX 102
#define KMAX 203
using namespace std;

typedef struct sTable{
	int count;
	int weight;
	char direction;
}sTable;

typedef struct Node{
	int L;
	int D;
	bool isCheak;
	sTable table[KMAX];
}Node;

typedef struct Pos{
	int x;
	int y;
}Pos;

FILE *in, *out;
int testCase, M, N, K;
Node vertex[MAX][MAX];
deque<Pos> path;

void initTable(Node table [][MAX]){
	for (int i = 1; i < N; i++){
		if (K == 0){
			table[0][i].table[0].count = table[0][i - 1].table[0].count;
			table[0][i].table[0].weight = table[0][i - 1].table[0].weight;
			table[0][i].table[0].weight += table[0][i - 1].L;
			table[0][i].table[0].direction = 'L';
			continue;
		}

		if (!table[0][i].isCheak){
			for (int j = 0; j <= K; j++){
				table[0][i].table[j].count = table[0][i - 1].table[j].count;
				if (table[0][i].table[j].count != 0){
					table[0][i].table[j].weight = table[0][i - 1].table[j].weight;
					table[0][i].table[j].weight += table[0][i - 1].L;
					table[0][i].table[j].direction = 'L';
				}
			}
		}
		else{
			for (int j = 0; j <= K - 1; j++){
				table[0][i].table[j + 1].count = table[0][i - 1].table[j].count;
				if (table[0][i].table[j + 1].count != 0){
					table[0][i].table[j + 1].weight = table[0][i - 1].table[j].weight;
					table[0][i].table[j + 1].weight += table[0][i - 1].L;
					table[0][i].table[j + 1].direction = 'L';
				}

			}
		}
	}

	for (int i = 1; i < M; i++){
		if (K == 0){
			table[i][0].table[0].count = table[i - 1][0].table[0].count;
			table[i][0].table[0].weight = table[i - 1][0].table[0].weight;
			table[i][0].table[0].weight += table[i - 1][0].D;
			table[i][0].table[0].direction = 'D';
			continue;
		}

		if (!table[i][0].isCheak){
			for (int j = 0; j <= K; j++){
				table[i][0].table[j].count = table[i - 1][0].table[j].count;
				if (table[i][0].table[j].count != 0){
					table[i][0].table[j].weight = table[i - 1][0].table[j].weight;
					table[i][0].table[j].weight += table[i - 1][0].D;
					table[i][0].table[j].direction = 'D';
				}

			}
		}
		else{
			for (int j = 0; j <= K - 1; j++){
				table[i][0].table[j + 1].count = table[i - 1][0].table[j].count;
				if (table[i][0].table[j + 1].count != 0){
					table[i][0].table[j + 1].weight = table[i - 1][0].table[j].weight;
					table[i][0].table[j + 1].weight += table[i - 1][0].D;
					table[i][0].table[j + 1].direction = 'D';
				}

			}
		}
	}
}

void SearchTable(Node table [][MAX]){
	for (int i = 1; i < M; i++){
		for (int j = 1; j < N; j++){
			if (table[i][j].isCheak){
				for (int k = 0; k <= K; k++){
					table[i][j].table[k + 1].count = (table[i - 1][j].table[k].count) % 100000;
					table[i][j].table[k + 1].count = (table[i][j].table[k + 1].count + table[i][j - 1].table[k].count) % 100000;

					//if (table[i][j].table[k + 1].count != 0){
						int lval = 0xffffff;
						if (table[i][j - 1].table[k].weight != 0){
							lval = table[i][j - 1].table[k].weight + table[i][j - 1].L;
						}
						int dval = 0xffffff;
						if (table[i - 1][j].table[k].weight != 0){
							dval = table[i - 1][j].table[k].weight + table[i - 1][j].D;
						}

						if (lval <= dval){
							table[i][j].table[k + 1].weight = lval;
							table[i][j].table[k + 1].direction = 'L';
						}
						else{
							table[i][j].table[k + 1].weight = dval;
							table[i][j].table[k + 1].direction = 'D';
						}
					//}
				}
			}
			else{
				for (int k = 0; k <= K; k++){
					table[i][j].table[k].count = (table[i - 1][j].table[k].count) % 100000;
					table[i][j].table[k].count = (table[i][j].table[k].count + table[i][j - 1].table[k].count) % 100000;

					//if (table[i][j].table[k].count != 0){
						int lval = 0xffffff;
						if (table[i][j - 1].table[k].weight!= 0){
							lval = table[i][j - 1].table[k].weight + table[i][j - 1].L;
						}
						int dval = 0xffffff;
						if (table[i - 1][j].table[k].weight != 0){
							dval = table[i - 1][j].table[k].weight + table[i - 1][j].D;
						}

						if (lval <= dval){
							table[i][j].table[k].weight = lval;
							table[i][j].table[k].direction = 'L';
						}
						else{
							table[i][j].table[k].weight = dval;
							table[i][j].table[k].direction = 'D';
						}
					//}
				}
			}
		}
	}
}


void FindPath(int k){
	int i = M - 1;
	int j = N - 1;
	int nk = k;
	char prev;
	Pos pos;
	while (i != 0 || j != 0){
		
		prev = vertex[i][j].table[nk].direction;
		pos.y = j;
		pos.x = i;
		path.push_front(pos);

		if (vertex[i][j].isCheak){
			nk--;
		}

		if (prev == 'L'){
			j--;
		}
		else if (prev == 'D'){
			i--;
		}
		else{
			break;
		}
	}
	pos.y = 0;
	pos.x = 0;
	path.push_front(pos);
}

void PrintTable(Node table [][MAX]){
	if (K == 0){
		fprintf(out, "k:%d count:%d cost:%d\n", 0, table[M - 1][N - 1].table[0].count, table[M - 1][N - 1].table[0].weight);
		FindPath(0);
		while (!path.empty()){
			if (path.size() != 1){
				fprintf(out, "(%d,%d)->", path[0].x, path[0].y);
				path.pop_front();
			}
			else{
				fprintf(out, "(%d,%d)\n", path[0].x, path[0].y);
				path.pop_front();
			}
		}
		return;
	}

	for (int i = 0; i <= K; i++){
		if (table[M - 1][N - 1].table[i].count != 0){
			fprintf(out, "k:%d count:%d cost:%d\n", i, table[M - 1][N - 1].table[i].count, table[M - 1][N - 1].table[i].weight);
			FindPath(i);
			while (!path.empty()){
				if (path.size() != 1){
					fprintf(out, "(%d,%d)->", path[0].x, path[0].y);
					path.pop_front();
				}
				else{
					fprintf(out, "(%d,%d)\n", path[0].x, path[0].y);
					path.pop_front();
				}
			}
		}
	}
}

void realezeTable(){
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			vertex[i][j].D = 0;
			vertex[i][j].L = 0;
			vertex[i][j].isCheak = false;
			for (int k = 0; k <= K; k++){
				vertex[i][j].table[k].count = 0;
				vertex[i][j].table[k].weight = 0;
				vertex[i][j].table[k].direction = '\n';
			}
		}
	}
}

int main(){
	int cnt = 0, val;

	in = fopen("testpath.inp", "r");
	out = fopen("testpath.out", "w");

	fscanf(in, "%d\n", &testCase);

	while (cnt < testCase){
		fprintf(out, "Test Case No:%d\n", cnt + 1);
		fscanf(in, "%d %d %d\n", &M, &N, &K);
		//printf("%d %d %d\n", M, N, K);
		if (K != 0){
			int kcnt = 0, x, y;
			while (kcnt < K){
				fscanf(in, "%d %d\n", &x, &y);
				//printf("%d %d\n", x, y);
				vertex[x][y].isCheak = true;
				kcnt++;
			}
		}

		for (int i = 0; i < M; i++){
			for (int j = 0; j < N - 1; j++){
				fscanf(in, "%d ", &val);
				vertex[i][j].L = val;
			}
		}

		for (int i = 0; i < M - 1; i++){
			for (int j = 0; j < N; j++){
				fscanf(in, "%d ", &val);
				vertex[i][j].D = val;
			}
		}
		vertex[0][0].table[0].count = 1;
		vertex[0][0].table[0].weight = 0;

		initTable(vertex);
		SearchTable(vertex);
		PrintTable(vertex);
		cnt++;
		if (cnt != testCase)
			fprintf(out, "\n");
		realezeTable();
	}

	return 0;
}