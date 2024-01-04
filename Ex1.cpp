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
	
	int cnt = 1;
	
	loop(i, 1 , n-1) {
		if(a[i+1] == a[i]) cnt++;
		else{
			int sum = cnt * (cnt - 1) / 2;
			sum = sum % M;
			ans += sum;
			ans = ans % M;
			cnt = 1;
		}
	}
	if(cnt != 1) {
		int sum = cnt * (cnt - 1) / 2;
		sum = sum % M;
		ans += sum;
		ans = ans % M;
	}
	
	cout << ans;
	
	return 0;
}
