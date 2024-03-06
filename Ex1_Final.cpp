#include<bits/stdc++.h>

#define loop(i, a, b) for(int i = a; i <= b; i++)
#define loopdown(i, a, b) for(int i = a; i >= b; i--)
#define N 1000001

using namespace std;

int n;
int a[N];
int ans = 0;
int id;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("ngothuc.txt", "r", stdin);

	cin >> n;
	loop(i, 1, n) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	
	//loop(i, 1, n) cout << a[i] << " ";
	
	id = n;
	while(id >= 3) {
		int l = 1, r = id - 1;
		while(r > l) {
			int sum = a[l] + a[r];
			if(sum == a[id]) {
				ans++;
				l++; r--;
			}
			else if(sum < a[id]) l++;
			else if(sum > a[id]) r--;
		}
		id--;
	}
	
	cout << ans;

	return 0;
}
