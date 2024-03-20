// kzyzahk

#include <bits/stdc++.h>
using namespace std;

bool check(string& a, string& b, vector <int>& c, int n) {
	unordered_set <int> x;
	for(int i = 0; i < n; i++) {
		x.insert(c[i]);
	}
	int l = 0, r = 0;
	while(l < (int)a.length() && r < (int)b.length()) {
		if(x.count(l+1) == 0 && a[l] == b[r]) l += 1, r += 1;
		else l += 1;
	}
	return (r == (int)b.length() ? true : false);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string a, b; cin >> a >> b;
	vector <int> c(a.length());
	for(int i = 0; i < c.size(); i++) {
		cin >> c[i];
	}
	int k = 0, n = (int)a.length();
	for(int i = n; i >= 1; i >>= 1) {
		while(k+i <= n && check(a, b, c, k+i)) k += i;
	}
	cout << k << endl;
	return 0;
}
