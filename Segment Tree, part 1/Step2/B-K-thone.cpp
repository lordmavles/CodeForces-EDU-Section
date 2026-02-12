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
    
    int find(int k) {
        return _find(1, 0, size - 1, k);
    }
    
    void update(int pos) {
        _update(1, 0, size - 1, pos);
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
            t[v] = t[v << 1] + t[(v << 1) + 1];
        }
    }
    
    int _find(int v, int tl, int tr, int k) {
        if (tl == tr) {
            return tl;
        }
        else {
            int tm = (tl + tr) >> 1;
            if (t[v << 1] >= k) {
                return _find(v << 1, tl, tm, k);
            }
            else {
                return _find((v << 1) + 1, tm + 1, tr, k - t[v << 1]);
            }
        }
    }
    
    void _update(int v, int tl, int tr, int pos) {
        if (tl == tr) {
            t[v] = (t[v] == 1 ? 0 : 1);
        }
        else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm) {
                _update(v << 1, tl, tm, pos);
            }
            else {
                _update((v << 1) + 1, tm + 1, tr, pos);
            }
            t[v] = t[v << 1] + t[(v << 1) + 1];
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
        int t, v; cin >> t >> v;
        if (t == 1) {
            segTree.update(v);
        }
        else {
            cout << segTree.find(v + 1) << '\n';
        }
    }


    return 0;
    
}
