#include<bits/stdc++.h>
#define M 1000000007

using namespace std;

unsigned long long int a,b;
unsigned long long int ExpMod(unsigned long long int x)
{
	if(x == 0) return 1;
	else if(x == 1) return a % M;
	else if(x % 2 == 0)
	{
		unsigned long long int half = ExpMod(x / 2);
		return (half % M * half % M) % M;
	}
	else if(x % 2 == 1)
	{
		unsigned long long int half = ExpMod(x / 2);
		return (((half % M * half % M) % M) * (a % M)) % M;
	}
}
int main()
{
	//freopen("ngothuc.txt", "r", stdin);
	scanf("%llu %llu", &a, &b);
	//mod=Mod(); doublemod=DoubleMod();
	printf("%llu", ExpMod(b));
	return 0;
}
