#include<bits/stdc++.h>

#define loop(i, a, b) for(int i = a; i <= b; i++)
#define loopdown(i, a, b) for(int i = a; i >= b; i--)
#define N 1000001
#define M 1000000007

using namespace std;

int n;
int a[N];
int ans = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("ngothuc.txt", "r", stdin);

	cin >> n;
	loop(i, 1, n) cin >> a[i];
	sort(a+1, a+n+1);
	
	loop(i, 2, n) {
		if(a[i] == a[i-1] + 1) {
			int cnt1 = 0, cnt2 = 0;
			loopdown(j, i-1, 1) {
				if(a[j] == a[i-1]) cnt1++;
				else break;
			}
			loop(j, i, n) {
				if(a[j] == a[i]) cnt2++;
				else{
					i = j - 1;
					break;
				}
			}
			ans += cnt1 * cnt2;
			ans = ans % M;
		}
	}
	
	cout << ans;

	return 0;
}
