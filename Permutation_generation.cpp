#include<bits/stdc++.h>

#define N 1001
#define loop(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

int a[N];
int mark[N];
int n;

void Solution()
{
	loop(i, 1, n) cout << a[i] << " ";
	cout << endl;
}

int Check(int v, int k)
{
	if(mark[v]) return 0;
	return 1;
}

void Try(int k)
{
	loop(i, 1, n)
	{
		if(Check(i, k))
		{
			a[k] = i;
			mark[i] = 1;
			if(k == n) Solution();
			else Try(k+1);
			mark[i] = 0;
		}
	}
}

int main()
{
	cin >> n;
	loop(i, 1, n) mark[i] = 0;
	Try(1);
	return 0;
}
