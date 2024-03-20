// kzyzahk

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long w, h, n; cin >> w >> h >> n;
	double t = 1;
	t *= w, t *= h, t *= n;
	int exp;
	double mant = frexp(t, &exp);
	long long a = pow(10, ceil(ceil(exp*log10(2))/(2.0))+1);
	long long m = a;
	for(long long i = m; i >= 1; i >>= 1) {
		while(a-i > 0 && ((a-i)/w)*((a-i)/h) >= n) a -= i;
	}
	cout << a << endl;
	return 0;
}
