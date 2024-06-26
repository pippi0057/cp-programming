struct UnionFind {
    vector<ll> data;
    UnionFind(ll n): data(n, -1){}
    bool unite(ll a, ll b){
        a = root(a); b = root(b);
        if(a == b) return 0;
        if(data[a] > data[b]) swap(a, b);
        data[a] += data[b];
        data[b] = a;
        return 1;
    }
    bool find(ll a, ll b){ return root(a) == root(b); }
    ll root(ll a){ return data[a] < 0 ? a : data[a] = root(data[a]); }
    ll size(ll a){ return -data[root(a)]; }
    ll operator[](ll a){ return root(a); }
    bool operator[](pair<int, int> a){ return find(a.first, a.second); }
};