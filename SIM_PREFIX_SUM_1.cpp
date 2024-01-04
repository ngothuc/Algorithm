#include<bits/stdc++.h>

#define loop(i, a, b) for(int i = a; i <= b; i++)
#define loopdown(i, a, b) for(int i = a; i >= b; i--)
#define N 1000001

using namespace std;

int n, k, l, r;
int a[N];
int s[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("ngothuc.txt", "r", stdin);
	
	s[0] = 0;

	cin >> n;
	loop(i, 1, n) {
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	
	cin >> k;
	while(k--) {
		cin >> l >> r;
		cout << s[r] - s[l] + a[l] << endl; 
	}
	

	return 0;
}
