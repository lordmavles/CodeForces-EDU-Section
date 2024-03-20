// kzyzahk

#include <bits/stdc++.h>
using namespace std;

bool check(double t, vector <int>& a, int k) {
	int cc = 0;
	for(int i = 0; i < a.size(); i++) {
		cc += int(a[i]/t);
	}
	return (cc >= k);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k; cin >> n >> k;
	vector <int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	double t = 0, m = (1.0)*(*max_element(a.begin(), a.end()));
	for(double i = m; i >= 1e-7; i /= 2) {
		while(t+i <= m && check(t+i, a, k)) t += i;
	}
	cout << fixed << setprecision(6) << t << endl;
	return 0;
}
