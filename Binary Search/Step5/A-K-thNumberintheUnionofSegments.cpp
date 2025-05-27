// kzyzahk

#include <bits/stdc++.h>
using namespace std;
 
bool check(int t, int k, vector <vector <int>>& a) {
	long long cc = 0;
	for(int i = 0; i < a.size(); i++) {
		if(a[i][0] >= t) continue;
		cc += min(t-1, a[i][1])-a[i][0]+1;
	}
	return (cc <= k*1LL ? true : false);
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k; cin >> n >> k;
	vector <vector <int>> a(n, vector <int> (2));
	for(int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
	int t = -2e9;
	for(int i = 2e9; i >= 1; i >>= 1) {
		while(check(t+i, k, a)) t += i;
	}
	cout << t << '\n';
	return 0;
}
