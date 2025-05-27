// kzyzahk

#include <bits/stdc++.h>
using namespace std;
 
long long calc(long long t, vector <int>& a) {
	long long sum = 0, cc = 1;
	for(int i = 0; i < a.size(); i++) {
		if(a[i] > t) return 1e13;
		else if(sum + a[i] > t) cc += 1, sum = a[i];
		else sum += a[i];
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
	long long t = 1e14, b = 1e14;
	for(long long i = b; i >= 1; i /= 2) {
		while(t-i >= 0 && calc(t-i, a) <= 1LL*k) t -= i;
	}
	cout << t << endl;
	return 0;
}
