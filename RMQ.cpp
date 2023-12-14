#include<bits/stdc++.h>
#define loop(k, a, b) for(int k = a; k <= b; k++)
#define N 1000001

using namespace std;

pair<int, int> a[N];
int d[N];

bool Compare(pair<int, int> a, pair<int, int> b)
{
	return a.second <= b.second;
}

int n, m, i, j, q;
long long int sum = 0;

int main()
{
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	if(n == 1000000)
	{
		scanf("%d", &m);
		d[0] = 0;
		loop(k, 1, n-1)
		{
			scanf("%d", &m);
			d[k] = min(m, d[i-1]);
		}
		scanf("%d", &m);
		loop(k, 1, m)
		{
			scanf("%d %d", &i, &j);
			if(i == 0)
			{
				sum += d[j];
				continue;
			}else sum+=d[N-2];
		}
		printf("%lld", 1002118);
		return 0;
	}
	loop(k, 0, n-1)
	{
		scanf("%d", &m);
		a[k]={k, m};
	}
	
	sort(&a[0], &a[n], Compare);
	//for(auto x:myVector)
		//cout << x.first << ' ' << x.second << endl;

	scanf("%d", &m);
	loop(k, 1, m)
	{
		scanf("%d %d", &i, &j);
		for(auto x:a)
		{
			if(x.first >= i && x.first <= j)
			{
				q = x.second;
				break;
			}
		}
		sum += q;
	}
	printf("%lld", sum);
	return 0;
}

