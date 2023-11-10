#include<bits/stdc++.h>

#define loop(i, a, b) for(int i=a; i<=b; i++)
#define N 100001

using namespace std;

int n, m;
string str;
int ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("ngothuc.txt", "r", stdin);
	
	cin >> n >> m;
	
	loop(i, 1, n)
	{
		cin >> str;
		ans = 0;
		loop(j, 0, str.length()-1)
		{
			ans =  (ans * 256 + str[j]) % m;
		}
		cout << ans << endl;
	}
	
	return 0;
}
