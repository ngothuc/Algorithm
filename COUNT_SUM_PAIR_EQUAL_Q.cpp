#include<bits/stdc++.h>

#define loop(i, a, b) for(int i = a; i <= b; i++)
#define loopdown(i, a, b) for(int i = a; i >= b; i--)
#define N 1000001

using namespace std;
int n, Q;
int a[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("ngothuc.txt", "r", stdin);

	cin >> n >> Q;
	loop(i, 1, n) cin >> a[i];
	sort(a+1, a+n+1);
	int i = 1, j = n;
	int ans = 0;
	while(i < j) {
		if(a[i] + a[j] == Q) {
			if(a[i] == a[j]) {
				ans += (j-i)*(j-i+1)/2;
				break;
			}else{
				int Left = 0, Right = 0;
				loop(x, i, j) {
					if(a[x] == a[i]) Left++;
					else {
						i = x;
						break;
					}
				}
				loopdown(x, j, i) {
					if(a[x] == a[j]) Right++;
					else {
						j = x;
						break;
					}
				}
				ans += Left * Right;
			}
		}else if(a[i] + a[j] > Q) {
			j--;			
		}else if(a[i] + a[j] < Q) {
			i++;
		}
	}
	
	cout << ans;

	return 0;
}
