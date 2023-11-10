#include<bits/stdc++.h>

#define N 1000001
#define loop(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

int n, m, sum;
int a[N];
int Left, Right;
int cnt = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
	//freopen("ngothuc.txt", "r", stdin);
	
	cin >> n >> m;
	loop(i, 1, n) cin >> a[i];
	
	sort(a+1, a+n+1);
	Left  = 1; Right = n;
	
	while(Left < Right)
	{
		sum = a[Left] + a[Right];
		if(sum == m)
		{
			cnt++;
			Left++; Right--;
		}
		else if(sum > m)
		{
			Right--;
		}else if(sum < m)
		{
			Left++;
		}
	}
	
	cout << cnt;
	
	return 0;
}
