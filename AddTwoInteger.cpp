#include <bits/stdc++.h>

using namespace std;

int m = 0;
int Max;
int r1, r2;
string a,b;
int u, v, c[20];

int main()
{
	cin >> a >> b;
	r1 = a.length() - 1;
	r2 = b.length() - 1;
	if(r1 > r2) Max = r1;
	else Max = r2;
	for (int i = 0; i <= Max; i++)
	{
		if (r1 >= 0) u = a[r1] - 48;
		else u = 0;
		if (r2 >= 0) v = b[r2] - 48;
		else v = 0;
		c[i] = (u + v + m) % 10;
		m = (u + v) / 10;
		r1--; r2--; 
	}
	if (m == 1) cout << 1;
	for (int i = Max; i>=0; i--)
		cout << c[i];	
	return 0;
}
