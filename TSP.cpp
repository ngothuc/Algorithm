#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<=b; i++)
#define N 21

using namespace std;

int n;
int x[N];
int Min = INT_MAX;
int a[N][N];
int d = 0;
int ans = INT_MAX;
bool visited[N] = {false};
bool Check(int v, int k)
{
	if(visited[v]) return false;
	return true;
}

void Try(int k)
{
	loop(i, 2, n)
	{
		if(Check(i, k))
		{
			x[k]=i;
			visited[i]=true;
			d+=a[x[k-1]][x[k]];
			if(k==n)
			{
				if(d+a[x[k]][1]<ans) ans=d+a[x[k]][1];
			}else{
				if(d+(n-k+1)*Min<ans) Try(k+1);
			}
			d-=a[x[k-1]][x[k]];
			visited[i]=false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	loop(i, 1, n)
	{
		loop(j, 1, n)
		{
			scanf("%d", &a[i][j]);
			if(a[i][j]<Min) Min=a[i][j];
		}
	}
	x[1]=1;
	Try(2);
	printf("%d",ans);
	//cout << Min;
	return 0;
}

