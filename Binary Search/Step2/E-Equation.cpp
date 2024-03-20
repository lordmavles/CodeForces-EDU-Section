// kzyzahk

#include <bits/stdc++.h>
using namespace std;

int main() {
	long double c; cin >> c;
	long double t = 0;
	for(long double i = c; i > 1e-8; i /= 2) {
		while((t+i)*(t+i)+sqrt(t+i) <= c) t += i;
	}
	cout << fixed << setprecision(7) << t << endl;
	return 0;
}
