#include<bits/stdc++.h>
#define N 10001
using namespace std;
int n, L, m;
set<int> s;
set<int> loan;
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &n, &L, &m);
	int max = n+m;
	char str[50];
	int num;
	for(int i=1; i<=n; i++)
	{
		scanf("%s", str);
		num = atoi(str);
		s.insert(num);		
	}
	for (auto it = s.rbegin(); it != s.rend(); ++it) 
	{
        if(*it > max)
        {
        	loan.insert(*it);
        	max--;
		}
    }
	for(int i=1; i<=max; i++)
	{
		printf("%0*d\n", L, i);
	}
	for(int value : loan)
	{
		printf("%0*d\n", L, value);
	}
	return 0;
}

