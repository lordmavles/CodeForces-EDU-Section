// kzyzahk

#include <bits/stdc++.h>
using namespace std;
 
bool check(long long t, long long k, long long n) {
	long long cc = 0;
	for(long long i = 1; i <= n; i++) {
		long long f = min(n, t/i);
		if(i*f >= t) f -= 1;
		if(f < i) continue;
		cc += 2*(f-i+1)-1;
	}
	return (cc < k ? true : false);
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long n; cin >> n;
	long long k; cin >> k;
	long long t = 1;
	for(long long j = 1e15; j >= 1; j >>= 1) {
		while(t+j <= n*n && check(t+j, k, n)) t += j;
	}
	cout << t << '\n';
	return 0;
}
