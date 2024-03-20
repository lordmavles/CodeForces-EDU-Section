// kzyzahk

#include <bits/stdc++.h>
using namespace std;

int calc(int t, vector <vector <int>>& a) {
	unsigned int cc = 0;
	for(int i = 0; i < a.size(); i++) {
		int cycle = a[i][0]*a[i][1]+a[i][2];
		cc += a[i][1]*(t/cycle);
		if((t%cycle) >= a[i][0]*a[i][1]) cc += a[i][1];
		else cc += ((t%cycle)/a[i][0]);
	}
	unsigned int bound = INT_MAX;
	return (int)min(bound, cc);
}

int main() {
	int m, n; cin >> m >> n;
	vector <vector <int>> a(n, vector <int> (3));
	for(int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	int t = 3e6, b = 3e6;
	for(int i = b/2; i >= 1; i >>= 1) {
		while(t-i >= 0 && calc(t-i, a) >= m) t -= i;
	}
	cout << t << endl;
	for(int i = 0; i < a.size(); i++) {
		int cycle = a[i][0]*a[i][1]+a[i][2];
		unsigned int cc = 0;
		cc += a[i][1]*(t/cycle);
		if((t%cycle) >= a[i][0]*a[i][1]) cc += a[i][1];
		else cc += ((t%cycle)/a[i][0]);
		unsigned int bound = INT_MAX;
		int ccx = (int)min(bound, cc);
		if(m > ccx) cout << ccx << ' ', m -= ccx;
		else cout << m << ' ', m = 0;
	}
	cout << endl;
	return 0;
}
