#include<bits/stdc++.h>

#define loop(i, a, b) for(int i = a; i <= b; i++)
#define loopdown(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int, int>
#define N 100001

using namespace std;

int n, u, v, w;
int f[N];
vector<pii> E[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("ngothuc.txt", "r", stdin);

	cin >> n;
	loop(i, 1, n-1) {
		cin >> u >> v >> w;
		E[u].push_back(make_pair(v, w));
		E[v].push_back(make_pair(u, w));
	}
	
//	loop(i, 1, n) {
//		cout << i << ": ";
//		for(auto x : E[i]) cout << x.first << " ";
//		cout << endl;
//	}

	

	return 0;
}
