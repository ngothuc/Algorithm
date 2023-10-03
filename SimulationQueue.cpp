#include<bits/stdc++.h>
using namespace std;
queue<int> s;
int main()
{
	string cmd;
	int num;
	while(1)
	{
		cin >> cmd;
		if(cmd == "#") break;
		else if(cmd == "PUSH")
		{
			cin >> num;
			s.push(num);
		}
		else if(cmd == "POP")
		{
			if(!s.empty())
			{
				num = s.front();
				cout << num << endl;
				s.pop();
			}else cout << "NULL" << endl;
		}
	}
	return 0;
}

