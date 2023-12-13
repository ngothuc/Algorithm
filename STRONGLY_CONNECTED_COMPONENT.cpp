#include <bits/stdc++.h>
using namespace std;
#define MAX 100005

int n, m;
vector<int> A[MAX];

int num[MAX], low[MAX], timeDFS;
bool is_deleted[MAX];
stack<int> st;
int components;


void input() {
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

//   freopen("ComputeStronglyConnectedComponentsOfDirectedGraphs.txt", "r", stdin);

   cin >> n >> m;
   int u, v;
   for (int i=1; i<=m; i++) {
      cin >> u >> v;
      A[u].push_back(v);
   }
}

void DFS(int u) {
   st.push(u);
   num[u] = ++timeDFS;
   low[u] = num[u];

   for (int& v : A[u]) {
      if (is_deleted[v]) continue;
      if (num[v]) low[u] = min(low[u], num[v]);
      else {
         DFS(v);
         low[u] = min(low[u], low[v]);
      }
   }
   if (low[u] == num[u]) {
      ++components;
      int v;
      do {
         v = st.top(); st.pop();
         is_deleted[v] = true;
//         cout << v << " ";
      }while (v != u);
//      cout << endl;
   }
}

void solve() {
   for (int u=1; u<=n; u++) {
      if (!num[u]) DFS(u);
   }
   cout << components;
}

int main()
{
   input();
   solve();
   return 0;
}

