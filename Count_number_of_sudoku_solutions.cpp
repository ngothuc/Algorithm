#include<bits/stdc++.h>

#define loop(i, a, b) for(int i=a; i<=b; i++)
#define N 9

using namespace std;

int a[N][N];
int ans=0;

int Check(int v, int k) {
    int row = k / 9;
    int col = k % 9;
    for (int i = 0; i < 9; i++) {
        if (a[row][i] == v || a[i][col] == v) return 0;
    }
 
    int square_row = row / 3;
    int square_col = col / 3;
 
    for (int i = square_row * 3; i <= square_row * 3 + 2; i++) {
        for (int j = square_col * 3; j <= square_col * 3 + 2; j++) {
            if (a[i][j] == v) return 0;
        }
    }
 
    return 1;
}

void Try(int k) {
    if (k == 81) {
        ans++;
        return;
    }
 
    int v;
    int row = k / 9;
    int col = k % 9;
    if (a[row][col] != 0) {
        Try(k + 1); 
    } else {
        for (v = 1; v <= 9; v++) {
            if (Check(v, k)) {
                a[row][col] = v;
                Try(k + 1);
                a[row][col] = 0; 
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
	//freopen("ngothuc.txt", "r", stdin);
	
	loop(i, 0, 8)
	{
		loop(j, 0, 8)
		{
			cin >> a[i][j];
		}
	}
	
	Try(0);
	
	cout << ans;
	
	return 0;
}
