// kzyzahk

#include <bits/stdc++.h>
using namespace std;
 
bool check(int t, int d, int n, vector <vector <int>>& a) {
	vector <vector <int>> b;
	for(int i = 0; i < a.size(); i++) {
		if(a[i][0] <= t) b.push_back({a[i][1], a[i][2]});
	}
	sort(b.begin(), b.end());
	vector <int> v(n, 1e6); v[n-1] = 0;
	for(int i = b.size()-1; i >= 0; i--) {
		v[b[i][0]-1] = min(v[b[i][0]-1], 1+v[b[i][1]-1]);
	}
	// cout << t << ' ';
	// cout << (v[0] <= d ? "true" : "false") << '\n';
	return (v[0] <= d ? true : false);
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, d; cin >> n >> m >> d;
	vector <vector <int>> a(m, vector <int> (3));
	for(int i = 0; i < m; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][0];
	}
	sort(a.begin(), a.end());
	int t = 1e9+1, b = 1e9;
	for(int i = b; i >= 1; i >>= 1) {
		while(t-i >= 0 && check(t-i, d, n, a)) t -= i;
	}
	if(t == 1e9+1) {
		cout << -1 << endl;
		return 0;
	}
	vector <vector <int>> c;
	for(int i = 0; i < a.size() && a[i][0] <= t; i++) {
		c.push_back({a[i][1], a[i][2]});
	}
	sort(c.begin(), c.end());
	vector <vector <int>> v(n, vector <int> (2));
	for(int i = 0; i < n; i++) v[i] = {int(1e6), i};
	v[n-1][0] = 0;
	for(int i = c.size()-1; i >= 0; i--) {
		if(v[c[i][0]-1][0] >= 1+v[c[i][1]-1][0]) v[c[i][0]-1] = {1+v[c[i][1]-1][0], c[i][1]-1};
	}
	vector <int> path = {1};
	int nex = 0;
	while(nex < n-1) {
		path.push_back(v[nex][1]+1);
		nex = v[nex][1];
	}
	cout << path.size()-1 << endl;
	for(int i = 0; i < path.size(); i++) cout << path[i] << ' '; cout << endl;
	return 0;
}
