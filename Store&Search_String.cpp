#include<bits/stdc++.h>

#define loop(i, a, b) for(int i=a; i<=b; i++)
#define N 1000001

using namespace std;

set<string> mySet;
string cmd;
string key;
set<string> :: iterator it;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
	//freopen("ngothuc.txt", "r", stdin);
	
	while(1)
	{
		cin >> key;
		if(key == "*") break;
		else mySet.insert(key);
	}
	
//	for(auto i = mySet.begin(); i != mySet.end(); i++)
//	{
//		cout << *i << endl;
//	}
	
	while(1)
	{
		cin >> cmd;
		if(cmd == "***") break;
		else{
			if(cmd == "find")
			{
				cin >> key;
				it = mySet.find(key);
				if(it == mySet.end()) cout << 0 << endl;
				else cout << 1 << endl;
			}else if(cmd == "insert")
			{
				cin >> key;
				it = mySet.find(key);
				if(it == mySet.end())
				{
					mySet.insert(key);
					cout << 1 << endl;
				}
				else cout << 0 << endl;
			}
		}
	}

	return 0;
}
