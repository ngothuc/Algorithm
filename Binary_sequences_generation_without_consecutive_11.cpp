#include<bits/stdc++.h>

#define loop(i, a, b) for(int i=a; i<=b; i++)
#define N 21

using namespace std;

int a[N];
int n;

void Solution()
{
	loop(i, 1, n)
	{
		cout << a[i];
	}
	cout << endl;
}

bool Check(int v, int k)
{
	if(k==1 || v==0) return true;
	if(a[k-1]==1) return false;
	return true;
}

void Try(int k)
{
	loop(v, 0, 1)
	{
		if(Check(v, k))
		{
			a[k]=v;
			if(k==n) Solution();
			else Try(k+1);
		}
	}
}

int main()
{
	cin >> n;
	Try(1);
	return 0;
}
