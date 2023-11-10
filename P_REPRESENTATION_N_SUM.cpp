#include<bits/stdc++.h>

#define N 1001
#define M 1000000007
#define loop(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

int a[N];
int n, t = 0;
int cnt = 0;

void Try(int k)
{
	loop(i, a[k-1], n - t)
	{
		if(t + i <= n)
		{
			a[k] = i;
			t += a[k];
			if(t == n)
			{
				cnt++;
				if(cnt > M) cnt = 1;
			}
			else if(t < n) Try(k+1);
			t -= a[k];
		}
	}
}

int main()
{
	cin >> n;1
	a[0] = 1;
	Try(1);
	cout << cnt;
	return 0;
}

