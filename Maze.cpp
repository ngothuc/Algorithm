#include<bits/stdc++.h>
#define N 1000
#define loop(i, a, b) for(int i=a; i<=b; i++)

using namespace std;

int a[N][N];
int d[N][N];
int n, m, r, c;
int x,y;
int v1[4] = {1, 0, -1, 0};
int v2[4] = {0, 1, 0, -1};

queue<pair<int, int>> Q;

void Input()
{
	cin >> n >> m >> r >> c;
	loop(i, 1, n)
	{
		loop(j, 1, m)
		{
			cin >> a[i][j];
			if(a[i][j] == 1) d[i][j] = 1e9;
			else d[i][j] = -1;
		}
	}
	d[r][c] = 0;
	Q.push({r, c});
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    Input();
    while(!Q.empty())
    {
    	pair<int, int> now = Q.front();
    	Q.pop();
    	//cout << now.first << endl; cout << now.second << endl;
    	x = now.first; y = now.second;
    	if(x == n || y == m || x == 1 || y == 1)
    	{
    		cout << d[x][y]+1;
    		return 0;
		}
    	loop(i, 0, 3)
    	{
    		if(d[x+v1[i]][y+v2[i]] < 0)
    		{
    			Q.push({x+v1[i], y+v2[i]});
    			d[x+v1[i]][y+v2[i]] = d[x][y]+1;
			}
		}
	}
	cout << -1;
	return 0;
}
