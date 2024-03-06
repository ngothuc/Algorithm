#include<bits/stdc++.h>

#define loop(i, a, b) for(int i = a; i <= b; i++)
#define loopdown(i, a, b) for(int i = a; i >= b; i--)
#define N 1000001

using namespace std;
int n, x = 0;
string str;
int cntPlus, cntSubtract;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("ngothuc.txt", "r", stdin);

	cin >> n;
	while(n--) {
		cntPlus = cntSubtract = 0;
		cin >> str;
		for(auto t : str) {
			if(t == '+') cntPlus++;
			else if(t == '-') cntSubtract++;
		}
		if(cntPlus == 2) x++;
		if(cntSubtract == 2) x--;
	}
	
	cout << x;

	return 0;
}
