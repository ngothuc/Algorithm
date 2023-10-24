#include<bits/stdc++.h>
#define N 10001
#define M 10001
#define L 10001
#define loop(i, a, b) for(int i = a; i <= b; i++)
#define loopdown(i, a, b) for(int i = a; i >= b; i--)

using namespace std;

int x[N];
int y[M];
int n, m;
vector <int> id[L];
int ans[L];
int l = 0;
int tmp;

int main()
{
	ios_base::sync_with_stdio();
	cin.tie(0); cout.tie(0);
	//freopen("ngothuc.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	loop(i, 0, n-1) scanf("%d", x + i);
	loop(i, 0, m-1)
	{
		scanf("%d", y + i);
		id[y[i]].push_back(i);
	}
	ans[l++] = -1;
	loop(i, 0, n-1)
	{
		loopdown(j, id[x[i]].size() - 1, 0)
		{
			tmp = id[x[i]][j];
			if(tmp > ans[l-1]) ans[l++] = tmp;
			else ans[lower_bound(ans, ans + l, tmp) - ans] = tmp;
		}
	}
	printf("%d", l - 1);
	return 0;
}
