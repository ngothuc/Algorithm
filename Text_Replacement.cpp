#include<bits/stdc++.h>

#define N 1000001
#define loop(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

string p1, p2, T;
string tmp;
string Q;
int length;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
	//freopen("ngothuc.txt", "r", stdin);
	
	getline(cin, p1);
	getline(cin, p2);
	while(cin >> T)
	{
		if(T == p1) Q += p2;
		else Q += T;
		if(T != ".") Q += " ";
	}
	cout << Q;
	
	return 0;
}
