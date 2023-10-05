#include<bits/stdc++.h>

using namespace std;

int n, M;
int x[21];
int T=0;

bool Check(int v, int k)
{
	return T+v <= M;
}

void Solution()
{
	for(int i=1; i<=n; i++)
		cout << x[i] << ' ';
	cout << endl;
}
void Try(int k)
{
	int v;
	for(v=1; v<=M-n+k; v++)
	{
		if(Check(v, k))
		{
			x[k]=v;
			T+=x[k];
			if(k==n && T==M) Solution();
			else Try(k+1);
			T-=x[k];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> M;
	Try(1);
	return 0;
}

