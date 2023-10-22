#include<bits/stdc++.h>
#define loop(i, a, b) for(int i = a; i <= b; i++)
#define N 1000001
using namespace std;

int a[N];
int n;
int val;
int ans = INT_MIN;

int MaxS(int k)
{
	if(k == 1)
	{
		val = a[k];
	}else{
		val = val < 0 ? a[k] : val + a[k];
	}
	if(val > ans) ans = val;
}

int main()
{
	ios_base::sync_with_stdio();
	cin.tie(0); cout.tie(0);
	//freopen("ngothuc.txt", "r", stdin);
	cin >> n;
	loop(i, 1, n) cin >> a[i];
	loop(i, 1, n) MaxS(i);
	cout << ans;
	return 0;
}
