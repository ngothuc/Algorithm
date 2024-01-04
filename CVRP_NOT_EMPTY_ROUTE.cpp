#include <bits/stdc++.h>
using namespace std;
#define N 100
int n, K, Q;
int d[N];// d[i] is the amount of packages requested by customer i
int c[N][N];// c[i][j] is the distance from i to j
// solution model
int Y[N];// Y[k] is the next point of 0 on route k
int X[N];// X[i] is the next point of i
int load[N]; // load[k] is the amount of packages on route k
int nbSegments;
int f;// distance accumulated
int Fmin;// min-distance found
bool visited[N];// visited[v] = true means that v is visited
int sum = 0;
void input(){
	cin >> n >> K >> Q;
	for(int i = 1; i <= n; i++)
	{
		cin >> d[i];
		sum += d[i];
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			cin >> c[i][j];
		}
	}
}
void printSolution(){
	for(int k = 1; k <= K; k++) cout << Y[k] << " "; cout << endl;
	for(int i =1; i <= n; i++) cout << X[i] << " "; cout << endl;
	for(int k = 1; k <= K; k++){
		cout << "route[" << k << "]: 0 ";
		for(int i = Y[k]; i != 0; i = X[i])
			cout << i << " ";
		cout << "0, load = " << load[k] << endl;
	}
}
void solution(){

	if(f < Fmin){
		Fmin = f;
		//printSolution();
		//cout << "update best " << Fmin << endl;
	}
}
bool checkX(int v, int i, int k){
	if(v == 0) return true;
	if(visited[v]) return false;
	if(load[k] + d[v] > Q) return false;
	return true;
}
void TryX(int i, int k){// find next point X[i] of i on route k
	for(int v = 0; v <= n; v++){
		if(checkX(v,i,k)){
			X[i] = v; visited[v] = true;
			f = f + c[i][v]; load[k] += d[v];
			nbSegments += 1;
			if(v == 0){// return to the depot
				if(k < K) TryX(Y[k+1],k+1);
				else{
					if(nbSegments == n+K) solution();
				}
			}else{
				TryX(v,k);
			}
			visited[v] = false; f = f - c[i][v];
			load[k] -= d[v]; nbSegments -= 1;
		}
	}
}
bool checkY(int v, int k){
	if(visited[v]) return false;
	if(load[k] + d[v] > Q) return false;
	return true;
}
void TryY(int k){// try values for Y[k]
	for(int v = Y[k-1]+1; v <= n-K+k; v++){
		if(checkY(v,k)){
			Y[k] = v; visited[v] = true;
			f = f + c[0][v]; load[k] += d[v];
			nbSegments += 1;
			if(k == K){
				TryX(Y[1],1);
			}else{
				TryY(k+1);
			}
			visited[v] = false; f = f - c[0][v];
			load[k] -= d[v]; nbSegments -= 1;
		}
	}
}
int main(){
	ios_base::sync_with_stdio();
	cin.tie(0); cout.tie(0);
	//freopen("ngothuc.txt", "r", stdin);
	input();
	for(int v = 1; v <= n; v++) visited[v] = false;
	for(int k = 1; k <= K; k++) load[k] = 0;
	f = 0; Fmin = 1e9; nbSegments = 0;
	Y[0] = 0;
	TryY(1);
	cout << Fmin;
	return 0;
}

