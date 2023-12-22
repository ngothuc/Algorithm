#include<bits/stdc++.h>

#define loop(i, a, b) for(int i = a; i <= b; i++)
#define N 1000001
#define M 1000000007

using namespace std;

int n;
int a[N];
int ans = 0;
int Left[N];
int Right[N];

bool Compare(int x, int y) {
	return x > y;
}

void Merge(int L, int Mid, int R) {
	
	//sort(Left+L, Left+Mid+1, Compare);
	//sort(Right+Mid+1, Right+R+1, Compare);
	
	int res = R - Mid;
	int i = L, j = Mid+1;
	loop(k, L, R) {
		if(i > Mid) {
			Left[k] = Right[k] = a[j++];
		}
		else if(j > R) {
			Left[k] = Right[k] = a[i++];	
		}else {
			if(Left[i] > Right[j]) {
				ans += res;
				ans = ans % M;
				i++;
			}else {
				j++;
				res--;
			}
		}
	}
}

void MergeInversion(int L, int R) {
	if(L >= R) return;
	int Mid = (L + R) / 2; 
	MergeInversion(L, Mid);
	MergeInversion(Mid+1, R);
	Merge(L, Mid, R);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("ngothuc.txt", "r", stdin);
	
	cin >> n;
	loop(i, 1, n) {
		cin >> a[i];
		//Left[i] = Right[i] = a[i];
	}
	
	MergeInversion(1, n);
	cout << ans;

	return 0;
}
