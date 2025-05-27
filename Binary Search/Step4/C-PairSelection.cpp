// kzyzahk

#include <bits/stdc++.h>
using namespace std;
 
bool check(long double t, int k, vector <vector <int>>& a) {
	vector <long double> b(a.size());
	for(int i = 0; i < a.size(); i++) b[i] = a[i][0]-t*a[i][1];
	sort(b.begin(), b.end(), greater <long double> ());
	long double cc = 0;
	for(int i = 0; i < k; i++) cc += b[i];
	return (cc >= 0 ? true : false);
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k; cin >> n >> k;
	vector <vector <int>> a(n, vector <int> (2)); for(int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
	long double t = 0;
	for(long double i = 1e5; i >= 1e-8; i /= 2) {
		while(check(t+i, k, a)) t += i;
	}
	cout << fixed << setprecision(7) << t << '\n';
	return 0;
}
