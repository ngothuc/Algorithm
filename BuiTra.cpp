#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    freopen("ngothuc.txt", "r", stdin);

    int n;
    cin >> n;
    vector<int> a(n+1);
    int sum = 0;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    vector<vector<bool>> dp(n+1, vector<bool>(sum/2+1, false));
    dp[0][0] = true;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= sum/2; j++) {
            if(j >= a[i]) dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i]];
            else dp[i][j] = dp[i-1][j];
        }
    }

    int ans = INT_MAX;
    for(int j = 0; j <= sum/2; j++) {
        if(dp[n][j]) {
            ans = min(ans, sum - 2*j);
        }
    }

    cout << ans << "\n";
    return 0;
}
