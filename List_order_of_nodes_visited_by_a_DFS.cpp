#include<bits/stdc++.h>

#define N 101
#define loop(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

int n, m;
vector<int> E[N];
int u, v;
int level[N];
int now;

void DFS(int u) {
	stack<int> myStack;
	myStack.push(u);
	cout << u << " ";
	while(!myStack.empty()) {
		now = myStack.top();
		myStack.pop();
		loop(i, 0, E[now].size() - 1) {
			if(level[E[now][i]] == 0) {
				level[E[now][i]] = level[now] + 1;
				myStack.push(E[now][i]);
				cout << E[now][i] << " ";
				break;
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
	
//	loop(i, 1, n) {
//		cout << i << ": ";
//		loop(j, 0, E[i].size() - 1) cout << E[i][j] << " ";
//		cout << endl;
//	}
	
	loop(i, 1, n) {
		if(level[i] == 0) {
			level[i] = 1;
			DFS(i);
		}
	}
	
	return 0;
}
