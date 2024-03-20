// kzyzahk

#include <bits/stdc++.h>
using namespace std;

bool check(long long n, int k, vector <int>& a) {
	long long cc = 0;
	for(int i = 0; i < a.size(); i++) {
		cc += min(n, 1LL*a[i]);
	}
	if(cc/n >= 1LL*k) return true;
	return false;
}

int main() {
	int k, n; cin >> k >> n;
	vector <int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long t = 0, b = 5e10;
	for(long long i = b; i >= 1; i >>= 1) {
		while(check(t+i, k, a)) t += i;
	}
	cout << t << endl;
	return 0;
}
