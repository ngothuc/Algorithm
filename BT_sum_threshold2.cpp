#include<bits/stdc++.h>

#define loop(i, a, b) for(int i = a; i <= b; i++)
#define loopdown(i, a, b) for(int i = a; i >= b; i--)
#define N 1000001

using namespace std;

int n, year;
int a[N];
int mark[N];
int ans;

void Solution() {
	int sum =0;
	loop(i, 1, n) {
		if(mark[i]) sum += a[i];
	}
	if(sum >= year && sum % 5 == 0) ans++;
}

void Try(int k) {
	loop(v, 0, 1) {
		mark[k] = v;
		if(k == n) {
			Solution();
		}
		else Try(k+1);
	}
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("ngothuc.txt", "r", stdin);

	cin >> n;
	loop(i, 1, n) {
		cin >> a[i];
		mark[i] = 0;
	}
	cin >> year;
	
	Try(1);
	cout << ans;

	return 0;
}
