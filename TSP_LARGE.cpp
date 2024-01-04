#include<bits/stdc++.h>

#define loop(i, a, b) for(int i = a; i <= b; i++)
#define loopdown(i, a, b) for(int i = a; i >= b; i--)
#define N 1001

using namespace std;

int n, m;
int a[N][N];
int tmp;
int start, now, cont;
queue<int> Q;
bool visited[N];
int ans[N];
int res, minRes = INT_MAX;

void Solution() {
	loop(i, 1, n) {
		ans[i] = Q.front();
		Q.pop();
	}
}

void TSPGreedy() {
	loop(i, 1, n) visited[i] = false;
	res = 0;
	Q.push(start); visited[start] = true; now = start;
	loop(k, 1, n-1) {
		tmp = INT_MAX;
		loop(i, 1, n) {
			if(!visited[i]) {
				if(a[now][i] <= tmp) {
					tmp = a[now][i];
					cont = i;
				}
			}
		}
		Q.push(cont); visited[cont] = true;
		res += a[now][cont];
		now = cont;
	}
	res += a[now][start];
	if(res < minRes) {
		minRes = res;
		Solution();
	}
	while(!Q.empty()) Q.pop();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("ngothuc.txt", "r", stdin);
	
	cin >> n;
	loop(i, 1, n) {
		loop(j, 1, n) {
			cin >> a[i][j];
		}
	}
	
	loop(i, 1, n) {
		start = i;
		TSPGreedy();
	}
	
	cout << n << endl;
	loop(i, 1, n) cout << ans[i] << " ";
	
	return 0;
}
