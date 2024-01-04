#include<bits/stdc++.h>

#define loop(i, a, b) for(int i = a; i <= b; i++)
#define loopdown(i, a, b) for(int i = a; i >= b; i--)
#define N 1001

using namespace std;

int n, m, k;
int a[N][N];
int s[N][N];
int r1, c1, r2, c2;

void print() {
	loop(i, 1, n) {
		loop(j, 1, m) {
			cout << s[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("ngothuc.txt", "r", stdin);

	cin >> n >> m;
	loop(i, 1, n) {
		loop(j, 1, m) {
			cin >> a[i][j];
		}
	}
	
	loop(i, 0, n) s[i][0] = 0;
	loop(j, 0, m) s[0][j] = 0;
	
	loop(i, 1, n) {
		loop(j, 1, m) {
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
		}
	}
	
	//print();	
	
	cin >> k;
	
	while(k--) {
		cin >> r1 >> c1 >> r2 >> c2;
		cout << s[r2][c2] - s[r1-1][c2] - s[r2][c1-1] + s[r1-1][c1-1] << endl;
	}
	

	return 0;
}
