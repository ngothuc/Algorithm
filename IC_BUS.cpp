#include<bits/stdc++.h>

#define loop(i, a, b) for(int i = a; i <= b; i++)
#define loopdown(i, a, b) for(int i = a; i >= b; i--)
#define N 5001

using namespace std;

int n, m, u, v;
int c[N], d[N];
vector<int> E[N];
int ans[N];
int V[N];
int mark[N];

bool comp(int x, int y) {
	return c[x] < c[y];
}

void printAns() {
	loop(i, 1, n) {
		cout << ans[i] << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("ngothuc.txt", "r", stdin);

	cin >> n >> m;
	loop(i, 1, n) {
		cin >> c[i] >> d[i];
		V[i] = i;
		ans[i] = 0;
	}
	sort(V+1, V+n+1, comp);
//	loop(i, 1, n) {
//		cout << V[i] << " ";
//	}
//	cout << endl;
	while(m--) {
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	
	for(auto x : E[1]) {
		ans[x] = c[1];
//		printAns();
	}
	
	loop(i, 1, n) {
		int v = V[i];
		for(auto x : E[v]) {
			if(ans[x] == 0 || ans[x] > ans[v] + c[v]) {
				ans[x] = ans[v] + c[v];
			}
		}
//		cout << v << ": ";
//		printAns();
	}
	
	cout << ans[n];
	


	return 0;
}
