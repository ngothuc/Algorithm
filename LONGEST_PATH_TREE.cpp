#include<bits/stdc++.h>

#define loop(i, a, b) for(auto i = a; i <= b; i++)
#define pii pair<int, int>
#define N 1000001

using namespace std;

int n, u, v, w;
vector<pii> E[N];
bool visited[N];
int d[N];

void bfs(int u) {
	queue<int> q;
	q.push(u);
	while(!q.empty()) {
		int now = q.front(); q.pop();
		if(visited[now]) continue;
		else visited[now] = true;
		
		for(auto x : E[now]) {
			if(!visited[x.first]) {
				d[x.first] = d[now] + x.second;
				q.push(x.first);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("ngothuc.txt", "r", stdin);
	
	cin >> n;
	loop(i, 1, n) {
		visited[i] = false;
		d[i] = 0;
	}
	
	loop(i, 1, n-1) {
		cin >> u >> v >> w;
		E[u].push_back(make_pair(v, w));
		E[v].push_back(make_pair(u, w));
	}
	
	u = 1;
	bfs(u);
	loop(i, 2, n) {
		if(d[i] > d[u]) u = i;
	}
	
	loop(i, 1, n) {
		visited[i] = false;
		d[i] = 0;
	}
	bfs(u); u = 1;
	loop(i, 2, n) {
		if(d[i] > d[u]) u = i;
	}
	cout << d[u];
	
	return 0;
}

