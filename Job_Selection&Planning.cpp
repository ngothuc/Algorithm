#include<bits/stdc++.h>

#define N 10001
#define loop(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

int n;
int ans;
int max_dl = INT_MIN;

pair<int, int> a[N];
int mark[N];
int dl;

bool comp(pair<int, int> x, pair<int, int> y)
{
	return x.second > y.second;
}

int main()
{
	ios_base::sync_with_stdio();
	cin.tie(0); cout.tie(0);
	
	//freopen("ngothuc.txt", "r", stdin);
	
	cin >> n;
	loop(i, 1, n)
	{
		cin >> a[i].first >> a[i].second;
		if(a[i].first > max_dl) max_dl = a[i].first;
		mark[i] = 0;
	}
	
	sort(a+1, a+n+1, comp);
	
	//loop(i, 1, n) cout << a[i].first << " " << a[i].second << endl;
	//cout << max_dl;
	
	loop(i, 1, n)
	{
		dl = a[i].first;
		while(dl)
		{
			if(!mark[dl])
			{
				mark[dl] = 1;
				ans += a[i].second;
				break;
			}else dl--;
		}
	}
	
	cout << ans;
	
	return 0;
}
