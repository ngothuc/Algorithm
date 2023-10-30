#include<bits/stdc++.h>

#define N 1000001
#define loop(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

int n, m;
int a[N];
//int sol[N];
int t;
int ans = 0;

int Check(int v, int k)
{
	int check = m-t-v*a[k];
	if(check >= 0 && check <= m-k) return 1;
	return 0;
}

void Try(int k)
{
	int v;
	for(int v = 1; v <= m/a[k]; v++)
	{
		if(Check(v, k))
		{
			//sol[k] = v;
			t += v*a[k];
			if(k == n){
				if(t == m) ans++;
			} 
			else Try(k+1);
			t -= v*a[k];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio();
	cin.tie(0); cout.tie(0);
	
	//freopen("ngothuc.txt", "r", stdin);
	
	cin >> n >> m;
	loop(i, 1, n) cin >> a[i];
	
	Try(1);
	cout << ans;
	
	return 0;
}
