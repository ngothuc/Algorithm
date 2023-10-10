#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<=b; i++)
#define N 17
#define M 6

using namespace std;

int n,m;
int load[M];
int loadMin = INT_MAX;
int c[N], x[N];
int a[N][N];

bool Check(int v, int k)
{
	loop(i, 1, k-1)
	{
		if(a[i][k])
		{
			if(x[i]>=v) return false;
		}else if(a[k][i])
		{
			if(v>=x[i]) return false;
		}
	}
	return true;
}

int MAX(int* a, int* b)
{
	int j=0;
	for(int* i=a; i<=b; i++)
		if(*i>j) j=*i;
	return j;
}

void Solution()
{
	int maxLoad = MAX(&load[1], &load[m]);
	if(maxLoad < loadMin) loadMin = maxLoad;
}

void Try(int k)
{
	loop(v, 1, m)
	{
		if(Check(v, k))
		{
			x[k]=v;
			load[v]+=c[k];
			if(k==n) Solution();
			else{
				if(load[v]<loadMin) Try(k+1);
			}
			load[v]-=c[k];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	loop(i, 1, n)
		scanf("%d", c+i);
	loop(i, 1, n)
	{
		loop(j, 1, n)
		{
			scanf("%d", &a[i][j]);
		}
	}
	Try(1);
	printf("%d",loadMin);
	return 0;
}
