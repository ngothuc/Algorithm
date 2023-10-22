#include<bits/stdc++.h>
#define loop(i, a, b) for(int i = a; i <= b; i++)
#define M 10001
#define N 10001

using namespace std;

int x[N];
int y[M];
int m, n;
int ans = INT_MIN;
int val[N][M];

void InitAns()
{
	loop(i, 1, n)
		loop(j, 1, m)
			val[i][j] = -1;
}

int LongestCommonS(int i, int j)
{
	if(val[i][j] != -1) return val[i][j];
	if(i == 0 || j == 0) return 0;
	if(x[i] == y[j])
	{
		val[i][j] = LongestCommonS(i-1, j-1) + 1;
	}else{
		val[i][j] = max(LongestCommonS(i-1, j), LongestCommonS(i, j-1));
	}
	return val[i][j];
}

int main()
{
	ios_base::sync_with_stdio();
	cin.tie(0); cout.tie(0);
	freopen("ngothuc.txt", "r", stdin);
	cin >> n >> m;
	loop(i, 1, n) cin >> x[i];
	loop(i, 1, m) cin >> y[i];
	InitAns();
	cout << LongestCommonS(n, m);
	return 0;
}
