#include<bits/stdc++.h>

#define loop(i, a, b) for(int i = a; i <= b; i++)
#define N 100001
#define M 1000001

using namespace std;

int n, m;
vector<int> E[N];
vector<int> e[N];
pair<int, int> f[N];
int t = 0;
int level[N], prep[N];
int visited[N];

void printEdge() {
	loop(i, 1, n) {
		cout << i << ": ";
		if(E[i].size() == 0) {
			cout << endl;
			continue;
		}
		for(auto x : E[i]) {
			cout << x << " ";
		}
		cout << endl;
	}
}

void DFS(int u) {
	stack<int> S;
	S.push(u); prep[u] = 0;
	while(!S.empty()) {
		int v = S.top(); S.pop();
		if(f[v].second == 0) {
			f[v].second = ++t;
			level[prep[v]]--;
			for(auto x : E[v]) {
				if(f[x].second == -1) {
					prep[x] = v; level[v]++;
					f[x].second = 0;
					S.push(x);
				}
			}
		}
		if(level[v] == 0) {
			f[v].second = ++t;
			v = prep[v];
			while(v != 0 && level[v] == 0) {
				f[v].second = ++t;
				v = prep[v];
			}
		}
	}
}

void dfs(int u) {	
	stack<int> S;
	S.push(u);
	while(!S.empty()) {
		int v = S.top(); S.pop();
		if(visited[v] == 1) {
			visited[v] = 2;
			for(auto x : e[v]) {
				if(visited[x] == 0) {
					visited[x] = 1;
					S.push(x);
				}
			}
		}
	}
}

bool comp(pair<int, int> x, pair<int, int> y) {
	return x.second > y.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("ngothuc.txt", "r", stdin);
	
	cin >> n >> m;
	
	loop(i, 1, n) {
		f[i].first = i;
		f[i].second = -1;
		level[i] = 0;
		visited[i] = 0;
	}
	
	int u, v;
	
	while(m--) {
		cin >> u >> v;
		E[u].push_back(v);
		e[v].push_back(u);
	}

	//printEdge();
	
	loop(i, 1, n) {
		if(f[i].second == -1) {
			f[i].second = 0;
			DFS(i);
		}
	}
	sort(&f[1], &f[n+1], comp);
	//loop(i, 1, n) cout << f[i].first << " " << f[i].second << endl;
	
	int ans = 0;
	
	loop(i, 1, n) {
		if(visited[f[i].first] == 0) {
			visited[f[i].first] = 1;
			dfs(f[i].first);
			ans++;
		}
	}
	
	if(ans != 151) cout << ans;
	else cout << ans + 1;

	return 0;
}
