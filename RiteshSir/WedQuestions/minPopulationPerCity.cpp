#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	priority_queue<pair<int, int>> pq;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		pq.push({temp, 1});
	}
	int m;
	cin >> m;
	m -= n;
	int clinics = 1;
	while(clinics <= m){
		clinics++;
		int popu = pq.top().first;
		int clin = pq.top().second;
		pq.pop();
		popu *= clin++;
		popu /= clin;
		pq.push({popu, clin});
	}
	cout << pq.top().first;
}