// kzyzahk

#include <bits/stdc++.h>
using namespace std;
 
bool check(long double t, vector <vector <int>>& a) {
	long double l = -2e9, r = 2e9;
	for(int i = 0; i < a.size(); i++) {
		l = max(l, -t*a[i][1]+(1.0)*a[i][0]);
		r = min(r, t*a[i][1]+(1.0)*a[i][0]);
		if(l > r) return false;
	}
	return (l <= r);
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector <vector <int>> a(n, vector <int> (2));
	for(int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	long double t = 2e9, b = 2e9;
	for(long double i = b; i > 1e-7; i /= 2) {
		while(t-i >= 0 && check(t-i, a)) t -= i;
	}
	cout << fixed << setprecision(6) << t << endl;
	return 0;
}
