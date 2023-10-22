#include<bits/stdc++.h>
#define loop(i, a, b) for(int i = a; i <= b; i++)
#define N 10001

using namespace std;

int n;
int a[N];
int b[N];
int ans;

int LongestS(int k)
{
	if(k == 1)
	{
		b[k] = 1;
	}else{
		int val;
		b[k] = 1;
		loop(i, 1, k-1)
		{
			if(a[i] < a[k])
			{
				val = b[i] + 1;
				if(val > b[k]) b[k] = val;
			}
		}
	}
	if(b[k] > ans) ans = b[k];
	return b[k];
}

int main()
{
	ios_base::sync_with_stdio();
	cin.tie(0); cout.tie(0);
	//freopen("ngothuc.txt", "r", stdin);
	cin >> n;
	loop(i, 1, n) cin >> a[i];
	loop(i, 1, n) LongestS(i);
	cout << ans;
	return 0;
}
