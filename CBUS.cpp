#include<bits/stdc++.h>

#define loop(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

int n, k;
int min_d = INT_MAX;

int a[50][50];
int visited[50];
int c;
int l = 0;
int prep[50];
int ans = INT_MAX;
int now = 0;

int Check(int v, int m)
{
	if(visited[v]) return 0;
	if(v > n && visited[v-n] == 0) return 0;
	if(v <= n && l == k) return 0;
		
	return 1;
}

void Try(int m)
{
	int v;
	loop(v, 1, 2*n)
	{
		if(Check(v, m))
		{
			visited[v] = 1;
			prep[v] = now;
			c+=a[now][v];
			if(v <= n) l++;
			else l--;
			now = v;
			if(m == 2*n)
			{
				if(c + a[v][0] < ans) ans = c + a[v][0];
			}else if(c + min_d * (2*n - m + 1) < ans) Try(m + 1);
			visited[v] = 0;
			c-=a[prep[v]][v];
			now = prep[v];
			if(v <= n) l--;
			else l++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio();
	cin.tie(0); cout.tie(0);
	
	//freopen("ngothuc.txt", "r", stdin);
	
	scanf("%d %d", &n, &k);
	loop(i, 0, 2*n)
	{
		loop(j, 0, 2*n)
		{
			scanf("%d", &a[i][j]);
			if(a[i][j] < min_d && a[i][j] > 0) min_d = a[i][j];
		}
		visited[i] = 0;
	}
	
	Try(1);
	printf("%d", ans);
	
	return 0;
}
