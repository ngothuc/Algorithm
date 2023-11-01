#include<bits/stdc++.h>

#define loop(i, a, b) for(int i=a; i<=b; i++)
#define N 1000001

using namespace std;

stack<char> myStack;
char c;
char x;

char a[4] = "([{";
char b[4] = ")]}";

int ans = 1;
int v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
	//freopen("ngothuc.txt", "r", stdin);	
	
	while(1)
	{
		c = getchar();
		if(c == '\n') break;
		loop(i, 0, 2)
		{
			if(c == a[i])
			{
				myStack.push(c);
				//cout << "Push " << c << endl;
			}
			else if(c == b[i])
			{
				if(myStack.empty())
				{
					ans = 0;
					//cout << "Stack is empty!!" << endl;
					break;
				}
				x = myStack.top();
				myStack.pop();
				if(x != a[i])
				{
					ans = 0;
					//cout << x << " != " << c << endl;
					break;
				}
			}
		}
	}
	
	if(!myStack.empty()) ans = 0;
	
	cout << ans;
	
	return 0;
}
