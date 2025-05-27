// kzyzahk

#include <bits/stdc++.h>
using namespace std;
 
int calc(int t, vector <int>& a) {
	int cc = 1, p = a[0];
	for(int i = 1; i < a.size(); i++) {
		if(a[i]-p >= t) p = a[i], cc += 1;
	}
	return cc;
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k; cin >> n >> k;
	vector <int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int t = 0, b = 1e9;
	for(int i = 1e9; i >= 1; i >>= 1) {
		while(calc(t+i, a) >= k) t += i;
	}
	cout << t << endl;
	return 0;
}
