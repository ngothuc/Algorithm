#include<bits/stdc++.h>

#define loop(i, a, b) for(int i = a; i <= b; i++)
#define loopdown(i, a, b) for(int i = a; i >= b; i--)
#define N 1000001

using namespace std;

string a, b;
char u, v;

string addBigNumber(string a, string b) {
	string sum;
	int l1 = a.length(), l2 = b.length();
	int length = max(l1, l2);
	int remember = 0;
	
	loopdown(i, length, 1) {
		if(l1 > 0) u = a[l1-1]; else u = '0';
		if(l2 > 0) v = b[l2-1]; else v = '0';
		//cout << u << " " << v << endl;
		l1--; l2--;
		int tmp = u + v + remember - 96;
		remember = tmp / 10;
		tmp = tmp  % 10;
		char sumtmp = char(tmp + 48);
		sum = sumtmp + sum;
	}
	
	if(remember > 0) sum = "1" + sum;
	
	return sum;
}

string multiNumber(string x, char y) {
	string res;
	int b = y - 48;
	int remember = 0;
	loopdown(i, x.length()-1, 0) {
		int a = x[i] - 48;
		int mul = a * b + remember;
		remember = mul / 10;
		mul = mul % 10;
		char tmp = mul + 48;
		res = tmp + res;
	}
	if(remember > 0) {
		res = (char)(remember + 48) + res;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("ngothuc.txt", "r", stdin);

	cin >> a >> b;
	//cout << addBigNumber(a, b) << endl;
	//cout << multiNumber("100", '9');
	
	loop(i, b.length() - 1, 0) {
		string tmp = multiNumber(a)
	}

	return 0;
}
