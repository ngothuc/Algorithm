#include<bits/stdc++.h>

#define loop(i, a, b) for(int i = a; i <= b; i++)
#define pii pair<int, int>
#define N 1000001
#define INF 1e6

using namespace std;

int n, m, u, v, w, s, t;
vector<pii> E[N];
int d[N];
int p[N];

int dijkstra() {
	loop(v, 1, n) {
		d[v] = INF;
		p[v] = -1;
	}
	
	priority_queue<pii, vector<pii>, greater<pii>> F;
	d[s] = 0; F.push(make_pair(0, s));
	
	while(!F.empty()) {
		pii e = F.top(); F.pop(); u = e.second;
		if(u == t) return d[t];
		for(auto x : E[u]) {
			v = x.first; w = x.second;
			if(d[v] > d[u] + w) {
				d[v] = d[u] + w;
				p[v] = u;
				F.push(make_pair(d[v], v));
			}
		}
	}
	
	return -1;
}

bool cmp (pii a, pii b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("ngothuc.txt", "r", stdin);
	
	cin >> n >> m;
	while(m--) {
		cin >> u >> v >> w;
		E[u].push_back(make_pair(v, w));
	}
	cin >> s >> t;
	
	cout << dijkstra();
	
	return 0;
}
