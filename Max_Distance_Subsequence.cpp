#include <bits/stdc++.h>
using namespace std;

bool check(int x[], int N, int C, int mid) {
    int cnt = 1, prev = x[0];
    for (int i = 1; i < N; i++) {
        if (x[i] - prev >= mid) {
            cnt++;
            prev = x[i];
        }
    }
    return cnt >= C;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("ngothuc.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int N, C;
        cin >> N >> C;
        int x[N];
        for (int i = 0; i < N; i++) {
            cin >> x[i];
        }
        sort(x, x + N);
        
        int left = 1, right = x[N - 1] - x[0], ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(x, N, C, mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

