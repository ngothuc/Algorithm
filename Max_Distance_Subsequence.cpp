#include<bits/stdc++.h>

#define loop(i, a, b) for(int i=a; i<=b; i++)
#define N 100001

using namespace std;

int t, n , c, ans;
int x[N];
int Left, Right, Mid;

bool Check(int Mid)
{
	int cnt = 1;
	int tmp = x[1];
	loop(i, 2, n)
	{
		if(x[i] - tmp >= Mid)
		{
			cnt++;
			tmp = x[i];
		}
	}
	return cnt >= c;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("ngothuc.txt", "r", stdin);
	
	cin >> t;
	while(t--)
	{
		cin >> n >> c;
		loop(i, 1, n) cin >> x[i];
		sort(x+1, x+n+1);
		Left = 1; Right = x[n] - x[1]; ans = INT_MIN;
		
		while(Left <= Right)
		{
			Mid = (Left + Right) / 2;
			if(Check(Mid))
			{
				ans = Mid;
				Left = Mid + 1;
			}else{
				Right = Mid - 1;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
