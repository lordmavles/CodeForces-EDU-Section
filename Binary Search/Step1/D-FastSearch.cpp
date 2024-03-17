#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector <int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int x; cin >> x;
	for(int i = 0; i < x; i++) {
		int y, z; cin >> y >> z;
		int l = 0;
		for(int j = n/2; j >= 1; j /= 2) {
			while(l+j < n && a[l+j] < y) l += j;
		}
		if(a[l] >= y) l += 1;
		else l += 2;
		int r = n-1;
		for(int j = n/2; j >= 1; j /= 2) {
			while(r-j >= 0 && a[r-j] > z) r -= j;
		}
		if(a[r] <= z) r += 1;
		cout << (r-l+1) << '\n';
	}
	return 0;
}
