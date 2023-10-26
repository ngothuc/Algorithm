#include<bits/stdc++.h>
#define N 1000001
#define loop(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

long long int SC[N];
long long int SL[N];
int a[N];
int n;
long long int ans = INT_MIN;

int main()
{
	//freopen("ngothuc.txt", "r", stdin);
	scanf("%d", &n);
	//SC[0] = SL[0] = INT_MIN;
	loop(i, 0, n) SC[i] = SL[i] = INT_MIN;
	loop(i, 1, n) scanf("%d", a + i);
	
	loop(i, 1, n)
	{
		if(a[i] % 2 == 0)
		{
			// Chan
			if(SC[i-1] != INT_MIN && SC[i-1] > 0) SC[i] = SC[i-1] + a[i];
			else SC[i] = a[i];
			
			if(SL[i-1] != INT_MIN) SL[i] = SL[i-1] + a[i];
			else SL[i] = INT_MIN; 
			
		}else{
			// Le
			if(SL[i-1] != INT_MIN) SC[i] = SL[i-1] + a[i];
			else SC[i] = INT_MIN;
			
			if(SC[i-1] != INT_MIN && SC[i-1] > 0) SL[i] = SC[i-1] + a[i];
			else SL[i] = a[i];
		}
	}
	loop(i, 1, n) if(SC[i] > ans) ans = SC[i];
	if(ans != INT_MIN) printf("%lld", ans);
	else printf("NOT_FOUND");
	return 0;
}

