#include<bits/stdc++.h>

#define loop(i, a, b) for(int i = a; i <= b; i++)
#define loopdown(i, a, b) for(int i = a; i >= b; i--)
#define N 1000001

using namespace std;

int n, Q;
int a[N];
int l;
int ans = 0;
int sum;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("ngothuc.txt", "r", stdin);

	cin >> n >> Q;
	loop(i, 1, n) cin >> a[i];
	
	l = 1;
	
	loop(r, 1, n) {
		sum += a[r];
		if(sum <= Q) {
			ans = max(ans, r - l + 1);
		}else {
			while(sum > Q) {
				sum -= a[l];
				l++;
			}
		}
	}
	
	cout << ans;

	return 0;
}
