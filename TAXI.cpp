#include<bits/stdc++.h>

#define N 25
#define loop(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

int n;
int a[N][N];
bool visited[N];
int minC = INT_MAX;
bool pass = false;
int dis = 0;
int ans = INT_MAX;
int prep[N];
int now;

void Solution() {
	if(ans > dis + a[now][0]) {
		ans = dis + a[now][0];
//		cout << "Update ans = " << ans << endl;
//		int p = now;
//		while(p != 0) {
//			cout << p << " ";
//			p = prep[p];
//		}
//		cout << endl;
	}
}

bool Check(int v) {
	if(visited[v]) return false;
	return true;
}

void Try(int k) {
	loop(i, 1, n) {
		if(Check(i)) {
			visited[i] = true;
			dis = dis + a[now][i] + a[i][i+n];
			prep[i] = now;
			now = i + n;
			if(k == n) Solution();
			else if(dis + (n-k) * minC < ans) Try(k+1);
			visited[i] = false;
			dis = dis - a[now-n][now] - a[prep[now-n]][now-n];
			now = prep[now-n];
		}
	}
}

int main() {
	//freopen("ngothuc.txt", "r", stdin);
	
	cin >> n;
	loop(i, 0, 2*n) {
		loop(j, 0, 2*n) {
			cin >> a[i][j];
			if(a[i][j] < minC && i != j) minC = a[i][j];
		}
		visited[i] = false;
	}
	now = 0;
	
	Try(1);
	cout << ans;
	
	return 0;
}
