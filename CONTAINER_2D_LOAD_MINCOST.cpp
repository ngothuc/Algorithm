#include<bits/stdc++.h>

#define loop(i, a, b) for(int i = a; i <= b; i++)
#define loopdown(i, a, b) for(int i = a; i >= b; i--)
#define N 1001
#define pii pair<int, int>

using namespace std;

int n, k;
int W[N], L[N], w[N], l[N];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("ngothuc.txt", "r", stdin);

	cin >> n >> k;
	loop(i, 1, n) {
		cin >> w[i] >> l[i];
	}
	loop(i, 1, k) {
		cin >> W[i] >> L[i];
	}

	return 0;
}
