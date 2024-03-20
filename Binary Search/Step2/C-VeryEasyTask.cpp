// kzyzahk

#include <bits/stdc++.h>
using namespace std;
 
int calc(int t, int x, int y) {
	return (t/x)+(t/y);
}
 
int time(int n, int x, int y) {
	if(n == 1) return min(x, y);
	n -= 1;
	int k = 2e9, m = 2e9;
	for(int i = m; i >= 1; i /= 2) {
		while(k-i >= 0 && calc(k-i, x, y) >= n) k -= i;
	}
	return k+min(x, y);
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, x, y; cin >> n >> x >> y;
	cout << time(n, x, y) << endl;
	return 0;
}
