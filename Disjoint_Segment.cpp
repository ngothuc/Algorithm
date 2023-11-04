#include<bits/stdc++.h>

#define N 100001
#define loop(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

int n;
int ans = 0;
pair<int, int> myPair[N];
int tail = -1;

bool Comp(pair<int, int> x, pair<int, int> y)
{
	return x.second < y.second;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
	//freopen("ngothuc.txt", "r", stdin);
			
	cin >> n;
	loop(i, 1, n) cin >> myPair[i].first >> myPair[i].second;
	
	sort(&myPair[1], &myPair[n+1], Comp);
	
	loop(i, 1, n)
	{
		if(myPair[i].first > tail)
		{
			tail = myPair[i].second;
			ans++;
		}
	}
	
	cout << ans;
	
	return 0;
}
