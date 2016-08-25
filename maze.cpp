#include <stdio.h>

FILE * input;
FILE * output;

int root[50000];
bool check[50000];
int realrow,realcol;
int count;
int success;

struct MAP{
	bool north;
	bool east;
	bool south;
	bool west;

}Map;

struct MAP map[500][500];

int maze(int row,int col)
{
	int a;

	if( (row==realrow-1) && col == realcol-1)
	{
		root[count++] = (realcol*realrow)-1;
		success =1;
		return 1;
	}


	if(map[row][col].east==true && check[(row*realcol)+col+1]!=true)
	{

		check[(row*realcol)+(col+1)] = true;
		a=maze(row,col+1);
		if(a==1)
		{
			root[count++] = (row*realcol)+col;
			return 1;
		}

	}
	if(map[row][col].south==true && check[((row+1)*realcol)+col]!=true)
	{

		check[((row+1)*realcol)+col] = true;
		a=maze(row+1,col);
		if(a==1)
		{
			root[count++] = (row*realcol)+col;
			return 1;
		}
	}

	if(map[row][col].west==true && check[(row*realcol)+(col-1)]!=true)
	{

		check[(row*realcol)+(col-1)] = true;
		a=maze(row,col-1);
		if(a==1)
		{
			root[count++] = (row*realcol)+col;
			return 1;
		}
	}

	if(map[row][col].north==true && check[((row-1)*realcol)+col]!=true)
	{

		check[((row-1)*realcol)+col] = true;
		a=maze(row-1,col);
		if(a==1)
		{
			root[count++] = (row*realcol)+col;
			return 1;
		}
	}

	return 0;
}

int main()
{
	int i,j,k;

	int a,b;


	input = fopen("maze.inp","r");
	output = fopen("maze.out","w");

	a=0; 
	b=0;


	fscanf(input,"%d",&realrow);
	fscanf(input,"%d",&realcol);

	while(a!=-1 && b!=-1)
	{
		fscanf(input,"%d",&a);
		fscanf(input,"%d",&b);

		if(b==1){
			map[a/realcol][a%realcol].east = true;
			map[a/realcol][(a%realcol)+1].west = true;
		}
		else if(b==2){
			map[a/realcol][a%realcol].south = true;
			map[(a/realcol)+1][a%realcol].north = true;
		}
		else if(b==3){
			map[a/realcol][a%realcol].east = true;
			map[a/realcol][a%realcol].south = true;
			map[(a/realcol)+1][a%realcol].north = true;
			map[a/realcol][(a%realcol)+1].west = true;
		}

	}

	check[0]=true;
	i=maze(0,0);
	count--;
	if(i==1){
		while(count!=-1 )
		{

			fprintf(output,"%d\n",root[count]);
			printf("%d\n",root[count]);
			count--;
		}
	}
	else
	{
		fprintf(output,"No Solution!\n");
		// printf("%d\n",root[count]);


	}

}