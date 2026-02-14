// kzyzahk

#include <bits/stdc++.h>
using namespace std;


static int inf = 1e9 + 1;


class SegmentTree {
    
public:
    
    int size;
    vector <int> t;
    SegmentTree(vector <int>& a) : size(a.size()), t(a.size() << 2) {
        _build(a, 1, 0, size - 1);
    }
    
    void update(int pos, int newVal) {
        _update(1, 0, size - 1, pos, newVal);
    }
    
    int getMin(int l, int r) {
        return _min(1, 0, size - 1, l, r);
    }

private:
    
    void _build(vector <int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        }
        else {
            int tm = (tl + tr) >> 1;
            _build(a, v << 1, tl, tm);
            _build(a, (v << 1) + 1, tm + 1, tr);
            t[v] = min(t[v << 1], t[(v << 1) + 1]);
        }
    }
    
    void _update(int v, int tl, int tr, int pos, int newVal) {
        if (tl == tr) {
            t[v] = newVal;
        }
        else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm) {
                _update(v << 1, tl, tm, pos, newVal);
            }
            else {
                _update((v << 1) + 1, tm + 1, tr, pos, newVal);
            }
            t[v] = min(t[v << 1], t[(v << 1) + 1]);
        }
    }
    
    int _min(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return inf;
        }
        if (l == tl and r == tr) {
            return t[v];
        }
        else {
            int tm = (tl + tr) >> 1;
            return min(_min(v << 1, tl, tm, l, min(r, tm)), _min((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r));
        }
    }
    
};


int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector <int> a(n);
    for (int& num: a) {
        cin >> num;
    }
    
    SegmentTree segTree(a);
    
    for (int i = 0; i < m; i++) {
        int o, f, s; cin >> o >> f >> s;
        if (o == 1) {
            segTree.update(f, s);
        }
        else {
            cout << segTree.getMin(f, s - 1) << '\n';
        }
    }
    
    return 0;
    
}
