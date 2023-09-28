#include<bits/stdc++.h>
using namespace std;
map<string, int> word;
int main()
{
	string str;
	while(cin >> str)
	{
		if(word.find(str)!=word.end())
		{
			word[str]++;
		}else word[str]=1;
	}
	map<string, int>::iterator it;
    for (it = word.begin(); it != word.end(); ++it) {
        cout << it->first<< ' ' << it->second << endl;
    }
	return 0;
}
