// kzyzahk

#include <bits/stdc++.h>
using namespace std;
 
bool check(long double t, int d, vector <int>& a) {
	vector <long double> b(a.size()); b[0] = a[0]-t;
	for(int i = 1; i < a.size(); i++) b[i] = b[i-1]+a[i]-t;
	long double cc = 0;
	for(int i = d-1; i < b.size(); i++) {
		if(b[i] >= cc) return true;
		cc = min(cc, b[i-d+1]);
	}
	return false;
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, d; cin >> n >> d;
	vector <int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	long double t = 0;
	for(long double i = 100.0; i >= 1e-6; i /= 2) {
		while(check(t+i, d, a)) t += i;
	}
	vector <long double> b(n); b[0] = a[0]-t;
	for(int i = 1; i < n; i++) b[i] = b[i-1]+a[i]-t;
	int l = -1;
	for(int i = d-1; i < n; i++) {
		if(l == -1) {
			if(b[i] >= 0) {
			    cout << 1 << ' ' << i+1;
			    return 0;
			}
		}
		else if(b[i] >= b[l]) {
			cout << l+2 << ' ' << i+1;
			return 0;
		}
		if(l == -1 && b[i-d+1] <= 0) l = i-d+1;
		else if(b[l] >= b[i-d+1]) l = i-d+1;
	}
	return 0;
}
