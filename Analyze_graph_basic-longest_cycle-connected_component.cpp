#include<bits/stdc++.h>

#define loop(i, a, b) for(int i=a; i<=b; i++)
#define N 1000001

using namespace std;

string PointID, SegmentID, PointID1, PointID2, cmd;
int number_points = 0, number_segments = 0;
int x, y, pos;
int id, id1, id2;
map<string, int> pointsMap;
vector<int> E[N];
bool visited[N];
int connected_components = 0;
int longest_cycle;
int prep[N];
int ans[N];

void DFS(int u) {
	stack<int> myStack;
	myStack.push(u);
	//cout << u << " ";
	while(!myStack.empty()) {
		pos = myStack.top();
		myStack.pop();
		visited[pos] = true;
		if(E[pos].size() == 0) {
			//cout << endl;
			return;
		}
		loop(i, 0, E[pos].size() - 1) {
			if(!visited[E[pos][i]]) {
				visited[E[pos][i]] = true;
				myStack.push(E[pos][i]);
				//cout << E[pos][i] << " ";
			}			
		}
	}
	//cout << endl;
}

int connectedComponents() {
	loop(i, 1, number_points) {
		if(!visited[i]) {
			connected_components++;
			DFS(i);
		}
	}
	return connected_components;
}
void resetVisited() {
	loop(i, 1, number_points)
		visited[i] = false;
}

void Solution() {
	int back = id;
	while(prep[back] != id) {
		ans[back] = longest_cycle;
		back = prep[back];
	}
}

void Try(int k) {
	loop(i, 0, E[pos].size() - 1) {

		if(!visited[E[pos][i]]) {
			visited[E[pos][i]] = true;
			prep[E[pos][i]] = pos;
			pos = E[pos][i];
 			if(pos == id) {
 				longest_cycle = max(longest_cycle, k);
 				Solution();
			} else Try(k+1);
			visited[pos] = false;
			pos = prep[pos];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("ngothuc.txt", "r", stdin);

	while(1) {
		cin >> PointID;
		if(PointID == "#") break;
		else {
			pointsMap.insert(make_pair(PointID, ++number_points));
		}
		cin >> x >> y;
	}

	while(1) {
		cin >> SegmentID;
		if(SegmentID == "#") break;
		else {
			cin >> PointID1 >> PointID2;
			id1 = pointsMap.find(PointID1)->second;
			id2 = pointsMap.find(PointID2)->second;
			E[id1].push_back(id2);
			E[id2].push_back(id1);
			number_segments++;
		}
	}
	
	loop(i, 1, number_points) {
		ans[i] = 0;
		sort(E[i].begin(), E[i].end());
	}
	
	while(1) {
		cin >> cmd;
		if(cmd == "###") break;
		else if(cmd == "?number_points") cout << number_points << endl;
		else if(cmd == "?number_segments") cout << number_segments << endl;
		else if(cmd == "?connected_components") {
			resetVisited();
			cout << connectedComponents() << endl;
		}
		else if(cmd == "?longest_cycle_from") {
			resetVisited();
			cin >> PointID;
			longest_cycle = 0;
			id = pointsMap.find(PointID)->second;
			pos = id;
			if(ans[id] == 0) {
				Try(1);
				cout << longest_cycle << endl;
			}else cout << ans[id] << endl;
			//cout << id << endl;
		}
	} 
	
	return 0;
}
