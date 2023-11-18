#include<bits/stdc++.h>

#define N 101
#define loop(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

int n, m;
vector<int> E[N];
int u, v;
int level[N];
int now;

void BFS(int u) {
	queue<int> myQueue;
	myQueue.push(u);
	cout << u << " ";
	while(!myQueue.empty()) {
		now = myQueue.front();
		myQueue.pop();
		loop(i, 0, E[now].size() - 1) {
			if(level[E[now][i]] == 0) {
				level[E[now][i]] = level[now] + 1;
				myQueue.push(E[now][i]);
				cout << E[now][i] << " ";
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
	//freopen("ngothuc.txt", "r", stdin);
	
	cin >> n >> m;
	
	while(m--) {
		cin >> u >> v;
		E[u].push_back(v); E[v].push_back(u);
	}
	
	loop(i, 1, n) {
		level[i] = 0;
		sort(E[i].begin(), E[i].end());
	}
	
	loop(i, 1, n) {
		if(level[i] == 0) {
			level[i] = 1;
			BFS(i);
		}
	}
	
	return 0;
}
