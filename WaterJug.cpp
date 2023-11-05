#include<bits/stdc++.h>

using namespace std;

int w[901][901];
int a,b,c;
int cnt,Min=999;
int Count=1;


void Solution()
{
	for(int k=1; k<=cnt; k++)
		for(int i=0; i<=a; i++)
			for(int j=0; j<=b; j++)
				if(w[i][j]==k) printf("(%d,%d) ",i,j);
	printf("\n");
}


int Check(int x, int y)
{
	if(w[x][y]==0) return 1;
	return 0;
}


void Input()
{
	/*printf("The tich binh 1: ");*/ scanf("%d",&a);
	/*printf("The tich binh 2: ");*/ scanf("%d",&b);
	/*printf("The tich can lay: ");*/ scanf("%d",&c);
	for(int i=0; i<901; i++)
		for(int j=0; j<901; j++)
			w[i][j]=0;
}


void Try(int k, int x, int y)
{
	if(Check(x,y))
	{
		w[x][y]=k;
		if((x==c || y==c || x+y==c) && k<Min)
		{
			Min=k;
			cnt=k;
			//printf("Step %d: \n",count);
			Count++;
			//Solution();
			w[x][y]=0;
		}
		else{
			Try(k+1,a,y);
			Try(k+1,x,b);
			Try(k+1,0,y);
			Try(k+1,x,0);
			if(x+y<=a) Try(k+1,x+y,0);
			else Try(k+1,a,x+y-a);
			if(x+y<=b) Try(k+1,0,x+y);
			else Try(k+1,x+y-b,b);
			w[x][y]=0;
		}
	}else return;
}


int main()
{
	Input();
	Try(1,0,0);
	printf("%d",Min-1);
	return 0;
}
