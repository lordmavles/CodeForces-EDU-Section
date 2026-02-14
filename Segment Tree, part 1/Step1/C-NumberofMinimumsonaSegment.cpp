// kzyzahk

#include <bits/stdc++.h>
using namespace std;


const int inf = 1e9 + 1;


class SegmentTreeNode {
  
public:
    
    int minEle;
    int minCount;
    SegmentTreeNode() : minEle(0), minCount(0) {
        
    }
    SegmentTreeNode(int minEle, int minCount) : minEle(minEle), minCount(minCount) {
    }
    
};


class SegmentTree {
    
public:
    
    int size;
    vector <SegmentTreeNode> t;
    SegmentTree(vector <int>& a) : size(a.size()), t(a.size() << 2) {
        _build(a, 1, 0, size - 1);
    }
    
    void update(int pos, int newVal) {
        _update(1, 0, size - 1, pos, newVal);
    }
    
    SegmentTreeNode getMin(int l, int r) {
        return _min(1, 0, size - 1, l, r);
    }
    
private:
    
    SegmentTreeNode _combine(const SegmentTreeNode& first, const SegmentTreeNode& second) {
        if (first.minEle < second.minEle) {
            return first;
        }
        if (first.minEle > second.minEle) {
            return second;
        }
        return SegmentTreeNode(first.minEle, first.minCount + second.minCount);
    }
    
    void _build(vector <int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = SegmentTreeNode(a[tl], 1);
        }
        else {
            int tm = (tl + tr) >> 1;
            _build(a, v << 1, tl, tm);
            _build(a, (v << 1) + 1, tm + 1, tr);
            t[v] = _combine(t[v << 1], t[(v << 1) + 1]);
        }
    }
    
    void _update(int v, int tl, int tr, int pos, int newVal) {
        if (tl == tr) {
            t[v].minEle = newVal;
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
    
    SegmentTreeNode _min(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return SegmentTreeNode(inf, 0);
        }
        if (l == tl and r == tr) {
            return t[v];
        }
        else {
            int tm = (tl + tr) >> 1;
            return _combine(_min(v << 1, tl, tm, l, min(r, tm)), _min((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r));
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
            SegmentTreeNode segTreeNode = segTree.getMin(f, s - 1);
            cout << segTreeNode.minEle << ' ' << segTreeNode.minCount << '\n';
        }
    }
    
    return 0;
    
}
