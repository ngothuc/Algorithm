#include<bits/stdc++.h>

#define N 1000001
#define loop(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

int n, l;
string str;

int main()
{
	cin >> n >> l;
	loop(i, 1, n)
	{
		cin >> str;
		loop(i, str.length(), l-1) cout << 0;
		cout << str << endl;
	}
	return 0;
}
