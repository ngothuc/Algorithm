#include<bits/stdc++.h>

#define loop(i, a, b) for(int i = a; i <= b; i++)
#define loopdown(i, a, b) for(int i = a; i >= b; i--)
#define N 1000001

using namespace std;

int n, M, l, r;
int a[N];
int ans = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("ngothuc.txt", "r", stdin);

	cin >> n >> M;
	loop(i, 1, n) cin >> a[i];
	sort(a+1, a+n+1);
	l = 1; r = n;
	
	while(l < r) {
		if(a[l] + a[r] == M) {
			ans++;
			l++; r--;
		}else if(a[l] + a[r] < M) {
			l++;
		}else if(a[l] + a[r] > M) {
			r--;
		}
	}
	
	cout << ans;

	return 0;
}
