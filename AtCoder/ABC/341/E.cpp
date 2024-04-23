#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll int64_t
#define u32 uint32_t
#define u64 uint64_t
constexpr ll inf = 1e17;
constexpr int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl "\n"
#define Auto const auto
#define all(a) a.begin(),a.end()
#define overload(_1,_2,_3,_4,name,...) name
#define _rep1(n) for(int i = 0; i < (n); i++)
#define _rep2(i,n) for(int i = 0; i < (n); i++)
#define _rep3(i,a,b) for(int i = (a); i < (b); i++)
#define _rep4(i,a,b,c) for(int i = (a); i < (b); i += (c))
#define rep(...) overload(__VA_ARGS__,_rep4,_rep3,_rep2,_rep1)(__VA_ARGS__)
#define _rrep1(n) for(int i = (n) - 1; i >= 0; i--)
#define _rrep2(i,n) for(int i = (n) - 1; i >= 0; i--)
#define _rrep3(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define _rrep4(i,a,b,c) for(int i = (b) - 1; i >= (a); i -= (c))
#define rrep(...) overload(__VA_ARGS__,_rrep4,_rrep3,_rrep2,_rrep1)(__VA_ARGS__)
#define F function
template <class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }
struct Edge { int to; ll cost; Edge(int to, ll cost) : to(to), cost(cost) {} };
using Graph = vector<vector<Edge>>;
template<class T> istream& operator>>(istream& is, vector<T>& a){ for(auto& x : a) is >> x; return is; }
template<class T> void operator+=(vector<T>& a, T b){ a.push_back(b); return; }
template<class T> istream& operator>>(istream& is, set<T>& a){ T input; is >> input; a.insert(input); return is; }
template<class T> void operator+=(set<T>& a, T b){ a.insert(b); return; }
struct sorted_impl{
    template<class T> friend vector<T> operator|(vector<T> a, sorted_impl){ sort(all(a)); return a; }
    template<class T> friend void operator|=(vector<T>& a, sorted_impl){ sort(all(a)); }
} sorted;
struct reversed_impl{
    template<class T> friend vector<T> operator|(vector<T> a, reversed_impl){ reverse(all(a)); return a; }
    template<class T> friend void operator|=(vector<T>& a, reversed_impl){ reverse(all(a)); }
} reversed;

template <class T> struct RSQ{
    int n;
    vector<T> seg;
    RSQ(int n) : n(n) { int x = 1; while(n > x) x *= 2; n = x; seg.resize(n * 2, 0); }
    RSQ(int n, int a) : n(n) { int x = 1; while(n > x) x *= 2; n = x; seg.resize(n * 2, a); }
    void add(int ind, int x){
        ind += n; seg[ind] += x;
        while(true){ ind /= 2; if(ind == 0) return; seg[ind] = seg[ind*2] + seg[ind*2+1]; }
        return;
    }
    int sum(int l, int r){
        l += n; r += n;
        int res = 0;
        while(l < r){
            if(l % 2 == 1) res += seg[l], l++; l /= 2;
            if(r % 2 == 1) res += seg[r-1], r--; r /= 2;
        }
        return res;
    }
};

void Main(){
    int N, Q; cin >> N >> Q;
    string S; cin >> S;
    vector s(N - 1, true);
    RSQ<int> seg(N - 1);
    rep(N - 1) if(S[i] == S[i + 1]) s[i] = false;
    rep(N - 1) if(s[i]) seg.add(i, 1);
    auto change = [N, &s, &seg](int l, int r) -> void {
        if(l > 1){
            s[l - 2] = !s[l - 2];
            if(seg.sum(l - 2, l - 1) == 1) seg.add(l - 2, -1);
            else seg.add(l - 2, 1);
        }
        if(r < N){
            s[r - 1] = !s[r - 1];
            if(seg.sum(r - 1, r) == 1) seg.add(r - 1, -1);
            else seg.add(r - 1, 1);
        }
        
    };
    auto check = [&seg](int l, int r) -> void {
        if(seg.sum(l - 1, r - 1) == r - l) cout << "Yes" << endl;
        else cout << "No" << endl;
    };
    while(Q--){
        int t, l, r; cin >> t >> l >> r;
        if(t == 1) change(l, r);
        if(t == 2) check(l, r);
        // rep(N - 1) cout << seg.sum(i, i + 1) << " ";
        // cout << endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    Main();
}