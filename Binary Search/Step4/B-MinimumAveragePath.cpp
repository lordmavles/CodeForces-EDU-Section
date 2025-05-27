// kzyzahk

#include <bits/stdc++.h>
using namespace std;
 
void dfs(int n, vector <vector <vector <int>>>& a, vector <int>& p, vector <int>& v) {
	v[n] = 1;
	for(int i = 0; i < a[n].size(); i++) {
		if(v[a[n][i][0]] == 0) dfs(a[n][i][0], a, p, v);
	}
	p.push_back(n);
}
 
bool check(long double t, vector <vector <vector <int>>>& a, vector <int>& p) {
	vector <long double> d(a.size(), 1e8); d[0] = 0.0;
	for(int i = 0; i < p.size(); i++) {
		for(int j = 0; j < a[p[i]].size(); j++) {
			d[a[p[i]][j][0]] = min(d[a[p[i]][j][0]], a[p[i]][j][1]+d[p[i]]-t);
		}
	}
	return (d[a.size()-1] <= 0 ? true : false);
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;
	vector <vector <vector <int>>> a(n);
	for(int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z;
		a[x-1].push_back({y-1, z});
	}
	vector <int> v(n), p;
	dfs(0, a, p, v);
	reverse(p.begin(), p.end());
	long double t = 1e8;
	for(long double i = 1e8; i >= 1e-7; i /= 2) {
		while(t-i >= 0 && check(t-i, a, p)) t -= i;
	}
	vector <long double> d(n, 1e8); d[0] = 0.0;
	vector <int> q(n, -1);
	for(int i = 0; i < p.size(); i++) {
		for(int j = 0; j < a[p[i]].size(); j++) {
			long double org = d[a[p[i]][j][0]], rec = a[p[i]][j][1]+d[p[i]]-t;
			if(org > rec) d[a[p[i]][j][0]] = rec, q[a[p[i]][j][0]] = p[i];
		}
	}
	vector <int> path = {n-1};
	while(path.back() != 0) {
		path.push_back(q[path.back()]);
	}
	cout << path.size()-1 << '\n';
	for(int i = path.size()-1; i >= 0; i--) cout << path[i]+1 << ' '; cout << '\n';
	return 0;
}
