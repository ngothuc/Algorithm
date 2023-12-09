#include<bits/stdc++.h>

#define loop(i, a, b) for(int i = a; i <= b; i++)
#define N 1000001

using namespace std;

int n;
int a[N];
int sc[N], sl[N];
int ans = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("ngothuc.txt", "r", stdin);
	
	cin >> n;
	loop(i, 1, n) cin >> a[i];

	sc[0] = sl[0] = 0;
	
	loop(i, 1, n) {
		if(a[i] % 2 == 0) {
			sc[i] = sc[i-1] + 1;
			sl[i] = sl[i-1];
		} else {
			sc[i] = sl[i-1];
			sl[i] = sc[i-1] + 1;
		}
	}
	
	loop(i, 1, n) ans += sc[i];	
	cout << ans;
	
	return 0;
}
