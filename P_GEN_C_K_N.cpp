#include<bits/stdc++.h>

#define N 1000001
#define loop(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

int n, k;
int a[N];

void Solution() {
	loop(i, 1, k) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void Try(int m) {
	loop(i, a[m-1] + 1, n) {
		a[m] = i;
		if(m == k) Solution();
		else Try(m+1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> k >> n;
	a[0] = 0;
	Try(1);
	
	return 0;
}
