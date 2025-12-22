template <class T> struct RSQ {
    int n;
    vector<T> seg;
    RSQ(int n) : n(n) { int x = 1; while(n > x) x *= 2; n = x; seg.resize(n * 2, 0); }
    RSQ(int n, T a) : n(n) { int x = 1; while(n > x) x *= 2; n = x; seg.resize(n * 2, a); }
    void add(int ind, T x){
        ind += n; seg[ind] += x;
        while(true){ ind /= 2; if(ind == 0) return; seg[ind] = seg[ind*2] + seg[ind*2+1]; }
        return;
    }
    T sum(int l, int r){
        l += n; r += n;
        T res = 0;
        while(l < r){
            if(l % 2 == 1) res += seg[l], l++; l /= 2;
            if(r % 2 == 1) res += seg[r-1], r--; r /= 2;
        }
        return res;
    }
};