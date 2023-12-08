#include<bits/stdc++.h>

#define loop(i, a, b) for(int i = a; i <= b; i++)
#define pii pair<int, int>
#define N 100001

using namespace std;

int n, m;
int u, v, w;
int p[N];
vector<int> A[N];
vector<pair<pii, int>> E;

bool comp(pair<pii, int> x, pair<pii, int> y) {
	return x.second < y.second;
}

int findP(int u) {
	if(p[u] == u) return p[u];
	else p[u] = findP(p[u]);
	return p[u];
}

void unify(int u, int v) {
	p[v] = u;
}

int main() {
	//freopen("ngothuc.txt", "r", stdin);
	
	cin >> n >> m;
	while(m--) {
		cin >> u >> v >> w;
		A[u].push_back(v);
		E.push_back(make_pair(make_pair(u, v), w));
	}
	
	loop(i, 1, n) {
		p[i] = i;
	}
	
	sort(E.begin(), E.end(), comp);
	
	int cnt = 0;
	int d = 0;
	
	for(auto z : E) {
		u = z.first.first;
		v = z.first.second;
		int x = findP(u);
		int y = findP(v);
		if(x == y) continue;
		else {
			unify(x, y);
			cnt++;
			d+=z.second;
			if(cnt == n-1) break;
		}
	}
	
	cout << d;
	
	return 0;
}
