// kzyzahk

#include <bits/stdc++.h>
using namespace std;

bool check(long long n, int nb, int ns, int nc, int pb, int ps, int pc, long long r, vector <int> a) {
	long long b = 0, s = 0, c = 0;
	b = a[0]*n - nb, b = max(b, 0LL);
	s = a[1]*n - ns, s = max(s, 0LL);
	c = a[2]*n - nc, c = max(c, 0LL);
	long long cost = b*pb + s*ps + c*pc;
	return (cost <= r);
}

int main() {
	string s; cin >> s;
	vector <int> a(3);
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == 'B') a[0] += 1;
		if(s[i] == 'S') a[1] += 1;
		if(s[i] == 'C') a[2] += 1;
	}
	int nb, ns, nc; cin >> nb >> ns >> nc;
	int pb, ps, pc; cin >> pb >> ps >> pc;
	long long r; cin >> r;
	long long n = 0, b = 1e12;
	for(long long i = b; i >= 1; i >>= 1) {
		while(check(n+i, nb, ns, nc, pb, ps, pc, r, a)) n += i;
	}
	cout << n << endl;
	return 0;
}
