#include<bits/stdc++.h>

#define loop(i, a, b) for(int i = a; i <= b; i++)
#define loopdown(i, a, b) for(int i = a; i >= b; i--)
#define N 1001

using namespace std;

int n = 1, k, x, y;
int a[N][N];
int ans[N][N];

void printAns() {
	loop(i, 1, n) {
		loop(j, 1, n) {
			cout << ans[i][j] << "	";
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("ngothuc.txt", "r", stdin);

	cin >> k;
	loop(i, 1, k) {
		cin >> x >> y >> a[x][y];
		n = max(n, x); n = max(n, y);
	}
	

	ans[1][1] = a[1][1];

	loop(i, 2, n) {
		ans[1][i] = ans[1][i-1] + a[1][i];
		ans[i][1] = ans[i-1][1] + a[i][1];
	}
	
	loop(i, 2, n) {
		loop(j, 2, n) {
			int v = max(ans[i-1][j], ans[i][j-1]); v = max(v, ans[i-1][j-1]);
			ans[i][j] = v + a[i][j];
		}
	}
	
	//printAns();
	
	cout << ans[n][n];

	return 0;
}
