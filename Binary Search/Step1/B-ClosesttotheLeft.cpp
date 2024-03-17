// kzyzahk

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k; cin >> n >> k;
	vector <int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < k; i++) {
		int x; cin >> x;
		int k = 0;
		for(int j = n/2; j >= 1; j /= 2) {
			while(k+j < n && a[k+j] <= x) k += j;
		}
		cout << (a[k] <= x ? k+1 : k) << endl;
	}
	return 0;
}
