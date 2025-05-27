// kzyzahk

#include <bits/stdc++.h>
using namespace std;
 
long long calc(long long t, vector <int>& a, vector <int>& b) {
	long long cc = 0;
	int l = 0, r = a.size()-1;
	while(l < a.size()) {
		while(r >= 0 && a[l]+b[r] >= t) r -= 1;
		if(a[l]+b[r] < t) cc += (r+1);
		l += 1;
	}
	return cc;
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	long long k; cin >> k;
	vector <int> a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	sort(a.begin(), a.end()); sort(b.begin(), b.end());
	long long t = 0;
	for(long long i = 1e12; i >= 1; i >>= 1) {
		while(calc(t+i, a, b) < k) t += i;
	}
	cout << t << '\n';
	return 0;
}
