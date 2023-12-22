#include<bits/stdc++.h>

#define loop(i, a, b) for(int i = a; i <= b; i++)
#define N 901
#define pii pair<int, int>

using namespace std;
int n;
int a, b, c;
int level[N][N];
queue<pii> q;

void bfs() {
	while(!q.empty()) {
		pii now = q.front(); q.pop();
		int x = now.first; int y = now.second;
		if(x == c || y == c || x + y == c) {
			cout << level[x][y];
			return;
		}
		if(level[a][y] == 0) {
			q.push(make_pair(a, y));
			level[a][y] = level[x][y] + 1;
		}
		if(level[x][b] == 0) {
			q.push(make_pair(x, b));
			level[x][b] = level[x][y] + 1;
		}
		if(level[0][y] == 0) {
			q.push(make_pair(0, y));
			level[0][y] = level[x][y] + 1;
		}
		if(level[x][0] == 0) {
			q.push(make_pair(x, 0));
			level[x][0] = level[x][y] + 1;
		}
		if(x+y >= b) {
			if(level[x+y-b][b] == 0) {
				q.push(make_pair(x+y-b, b));
				level[x+y-b][b] = level[x][y] + 1;
			}
		}else if(level[0][x+y] == 0) {
			q.push(make_pair(0, x+y));
			level[0][x+y] = level[x][y] + 1;
		}
		if(x+y >= a) {
			if(level[a][x+y-a] == 0) {
				q.push(make_pair(a, x+y-a));
				level[a][x+y-a] = level[x][y] + 1;
			}
		}else if(level[x+y][0] == 0) {
			q.push(make_pair(x+y, 0));
			level[x+y][0] = level[x][y] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("ngothuc.txt", "r", stdin);
	
	cin >> a >> b >> c;
	loop(i, 0, a) loop(j, 0, b) level[i][j] = 0;
	q.push(make_pair(0, 0)); level[0][0] = 0;
	bfs();


	return 0;
}
