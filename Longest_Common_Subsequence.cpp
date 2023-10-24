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

int LongestCommonS()
{
    loop(i, 0, n)
        loop(j, 0, m)
            val[i][j] = 0;

    loop(i, 1, n)
    {
        loop(j, 1, m)
        {
            if (x[i] == y[j])
                val[i][j] = val[i - 1][j - 1] + 1;
            else
                val[i][j] = max(val[i - 1][j], val[i][j - 1]);
        }
    }

    return val[n][m];
}

int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0);
	freopen("ngothuc.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	loop(i, 1, n) scanf("%d", x + i);
	loop(i, 1, m) scanf("%d", y + i);
	InitAns();
	printf("%d", LongestCommonS());
	return 0;
}

