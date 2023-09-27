#include<bits/stdc++.h>
using namespace std;
#define N 100001
int main()
{
	//freopen("input.txt", "r", stdin);
	string str;
	set<string> s;
	while(1)
	{
		getline(cin, str);
		if(str=="*") break;
		s.insert(str);
	}
	string cmd;
	while(1)
	{
		cin >> cmd;
		if(cmd == "***") break;
		cin >> str;
		if(cmd=="find") 
		{
			if(s.find(str)!=s.end()) cout << 1 << endl;
			else cout << 0 << endl;
		} else if(cmd=="insert")
		{
			if(s.find(str)==s.end())
			{
				cout << 1 << endl;
				s.insert(str);
			}else cout << 0 << endl;
		}
	}
	return 0;
}
