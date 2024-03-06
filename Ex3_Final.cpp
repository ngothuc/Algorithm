#include<bits/stdc++.h>

#define loop(i, a, b) for(int i = a; i <= b; i++)
#define loopdown(i, a, b) for(int i = a; i >= b; i--)
#define N 1000001

using namespace std;

int n;
int a[N];
int mark[N];
int sum = 0, ans = INT_MAX;

int Solution() {
	int res = 0;
	loop(i, 1, n) {
		if(mark[i]) res += a[i];
	}
	return res;
}

void Try(int k) {
	loop(v, 0, 1) {
		mark[k] = v;
		if(k == n) {
			int res = Solution();
			if(2 * abs(res - sum/2) < ans) ans = 2 * abs(res - sum/2);
		}else Try(k+1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("ngothuc.txt", "r", stdin);

	cin >> n;
	loop(i, 1, n) {
		cin >> a[i];
		sum += a[i];
	}
	
	Try(1);
	cout << ans;

	return 0;
}
