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

void Main(){
    int N, H, W; cin >> N >> H >> W;
    vector<pii> v(N);
    multiset<pii> st;
    vector a(H, vector(W, false));
    for(auto& [x, y] : v) cin >> x >> y;
    auto dfs = [H, W, &a](auto& self, multiset<pii> st) -> bool {
        bool ok = true, res = false;
        int si = 0, sj = 0;
        rep(H) rep(j, W) if(!a[i][j]){
            if(!ok) continue;
            ok = false;
            si = i, sj = j;
        }
        // rep(H){
        //     rep(j, W) cout << (a[i][j] ? '#' : '.');
        //     cout << endl;
        // }
        if(ok) return true;
        for(const auto& [x, y] : st){
            auto tmp = st;
            tmp.erase(tmp.find({x, y}));
            if(si + x <= H && sj + y <= W){
                ok = true;
                rep(i, si, si + x) rep(j, sj, sj + y){
                    if(a[i][j]) ok = false;
                    a[i][j] = true;
                }
                if(ok) res = self(self, tmp);
                rep(i, si, si + x) rep(j, sj, sj + y){
                    a[i][j] = false;
                }
                if(res) return true;
            }
        }
        return false;
    };
    rep(bit, 1 << N){
        rep(N) if(bit & (1 << i)) swap(v[i].first, v[i].second);
        for(const auto& [x, y] : v) st.insert({x, y});
        if(dfs(dfs, st)){
            cout << "Yes" << endl;
            return;
        }
        rep(N) if(bit & (1 << i)) swap(v[i].first, v[i].second);
        st.clear();
    }
    cout << "No" << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    Main();
}