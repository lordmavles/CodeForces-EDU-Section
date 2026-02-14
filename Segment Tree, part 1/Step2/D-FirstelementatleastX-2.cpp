// kzyzahk

#include <bits/stdc++.h>
using namespace std;


class SegmentTree {
    
public:
    
    int size;
    vector <int> t;
    SegmentTree(vector <int>& a) : size(a.size()), t(a.size() << 2) {
        _build(a, 1, 0, size - 1);
    }
    
    int find(int x, int l) {
        int i = _find(1, 0, size - 1, x, l);
        return (i == size + 1 ? - 1 : i);
    }
    
    void update(int pos, int newVal) {
        _update(1, 0, size - 1, pos, newVal);
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
            t[v] = max(t[v << 1], t[(v << 1) + 1]);
        }
    }
    
    int _find(int v, int tl, int tr, int x, int l) {
        if (tr < l or t[v] < x) {
            return size + 1;
        }
        if (tl == tr) {
            return tl;
        }
        int tm = (tl + tr) >> 1;
        int searchVal = _find(v << 1, tl, tm, x, l);
        if (searchVal != size + 1) {
            return searchVal;
        }
        return _find((v << 1) + 1, tm + 1, tr, x, l);
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
            t[v] = max(t[v << 1], t[(v << 1) + 1]);
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
            cout << segTree.find(f, s) << '\n';
        }
    }
    
    return 0;
    
}
