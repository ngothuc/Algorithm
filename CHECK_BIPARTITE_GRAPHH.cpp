#include<bits/stdc++.h>

#define loop(i, a, b) for(int i=a; i<=b; i++)
#define N 100001

using namespace std;

int n, m;
int u, v;
vector<int> E[N];
int level[N];
int ans = 1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("ngothuc.txt", "r", stdin);

	cin >> n >> m;
	while(m--) {
		cin >> u >> v;
		E[u].push_back(v); E[v].push_back(u);
	}
	
	loop(i, 1, n) level[i] = -1;
	
	loop(i, 1, n) {
		if(level[i] == -1) {
			if(E[i].size() == 0) {
				continue;
			} else level[i] = level[E[i][0]] + 1;
		}
		loop(j, 0, E[i].size() - 1) {
			if(level[E[i][j]] == -1) level[E[i][j]] = level[i] + 1;
			else if((level[E[i][j]] + level[i]) % 2 == 0) {
				ans = 0;
				break;
			}
		}
	}
	
	cout << ans;
	
	return 0;
}
