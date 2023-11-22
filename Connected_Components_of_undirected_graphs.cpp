#include<bits/stdc++.h>

#define loop(i, a, b) for(int i=a; i<=b; i++)
#define N 100001

using namespace std;

int n, m;
int u, v, pos;
vector<int> E[N];
int res = 0;
bool visited[N];

void DFS(int u) {
	stack<int> myStack;
	myStack.push(u);
	//cout << u << " ";
	while(!myStack.empty()) {
		pos = myStack.top();
		myStack.pop();
		visited[pos] = true;
		if(E[pos].size() == 0) {
			//cout << endl;
			return;
		}
		loop(i, 0, E[pos].size() - 1) {
			if(!visited[E[pos][i]]) {
				visited[E[pos][i]] = true;
				myStack.push(E[pos][i]);
				//cout << E[pos][i] << " ";
			}			
		}
	}
	//cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("ngothuc.txt", "r", stdin);
	
	cin >> n >> m;
	
	loop(i, 1, n)
		visited[i] = false;
	
	while(m--) {
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	
	loop(i, 1, n) {
		if(!visited[i]) {
			res++;
			DFS(i);
		}
	}
	
	cout << res;
	
	return 0;
}
