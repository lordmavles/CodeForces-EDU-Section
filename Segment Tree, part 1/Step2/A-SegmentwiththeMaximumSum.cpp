// kzyzahk

#include <bits/stdc++.h>
using namespace std;


static const long long inf = static_cast<long long>(1e17);


class SegmentTreeNode {
public:
    long long sum;
    long long best;
    long long prefix;
    long long suffix;
    SegmentTreeNode() : sum(0), best(0), prefix(0), suffix(0) {
    }
    SegmentTreeNode(long long sum, long long best, long long prefix, long long suffix) : sum(sum), best(best), prefix(prefix), suffix(suffix) {
    }
    SegmentTreeNode(long long val) : sum(val), best(val), prefix(val), suffix(val) {
    }
};


class SegmentTree {
    
public:

    int size;
    vector <SegmentTreeNode> t;
    SegmentTree(vector <int>& a) : size(a.size()), t(a.size() << 2) {
        _build(a, 1, 0, size - 1);
    }
    
    long long best(int l = 0, int r = - 1) {
        return max(0LL, _best(1, 0, size - 1, l, (r == - 1 ? size - 1 : r)).best);
    }
    
    void update(int pos, int newVal) {
        _update(1, 0, size - 1, pos, newVal);
    }
    
private:
    
    SegmentTreeNode _combine(const SegmentTreeNode& a, const SegmentTreeNode& b) {
        long long sum = a.sum + b.sum, best, prefix, suffix;
        prefix = max(a.prefix, a.sum + b.prefix);
        suffix = max(b.suffix, a.suffix + b.sum);
        best = max(max(a.best, b.best), a.suffix + b.prefix);
        return SegmentTreeNode(sum, best, prefix, suffix);
    }
    
    void _build(vector <int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            long long longVal = static_cast<long long>(a[tl]);
            t[v] = SegmentTreeNode(longVal);
        }
        else {
            int tm = (tl + tr) >> 1;
            _build(a, v << 1, tl, tm);
            _build(a, (v << 1) + 1, tm + 1, tr);
            t[v] = _combine(t[v << 1], t[(v << 1) + 1]);
        }
    }
    
    SegmentTreeNode _best(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return SegmentTreeNode(0, -inf, -inf, -inf);
        }
        if (l == tl and r == tr) {
            return t[v];
        }
        int tm = (tl + tr) >> 1;
        return _combine(_best(v << 1, tl, tm, l, min(r, tm)), _best((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    
    void _update(int v, int tl, int tr, int pos, int newVal) {
        if (tl == tr) {
            long long newValLong = static_cast<long long>(newVal);
            t[v] = SegmentTreeNode(newValLong);
        }
        else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm) {
                _update(v << 1, tl, tm, pos, newVal);
            }
            else {
                _update((v << 1) + 1, tm + 1, tr, pos, newVal);
            }
            t[v] = _combine(t[v << 1], t[(v << 1) + 1]);
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
    
    cout << segTree.best() << '\n';
    for (int i = 0; i < m; i++) {
        int p, v; cin >> p >> v;
        segTree.update(p, v);
        cout << segTree.best() << '\n';
    }
    
    return 0;
    
}
