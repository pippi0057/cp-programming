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
    ll N, ans = 0; cin >> N;
    vector<vector<ll>> G(N, vector<ll>(N, 0));
    vector<ll> dp(1 << N, inf);
    rep(N - 1) rep(j, i + 1, N){
        ll x; cin >> x;
        G[i][j] = G[j][i] = x;
    }
    set<ll> seen;
    auto dfs = [N, G, &seen, &dp](auto& self, ll i = 0, ll p = 0, ll cnt = 0) -> ll {
        if(seen.size() == N || ((seen.size() == N - 1) && N % 2)) return 0;
        ll t = 0, tmp = 0;
        cout << p << " " << i << endl;
        seen.insert(i);
        rep(j, N) if(seen.find(j) == seen.end()) t += (1 << j);
        cout << t << endl;
        if(dp[t] != inf) return dp[t];
        rep(j, N) if(seen.find(j) == seen.end()) chmax(tmp, self(self, j, i, cnt + 1));
        seen.erase(i);
        dp[t] = tmp;
        if(cnt % 2) tmp += G[p][i];
        cout << "tmp: " << tmp << endl;
        return tmp;
    };
    cout << dfs(dfs, 0)<< endl;
    // rep(bit, 1 << (N - 1)){
    //     int t = 0;
    //     vector<int> tmp = {0};
    //     vector<vector<int>> g;
    //     rep(N - 1) if(bit >> i & 1) tmp.emplace_back(i + 1);
    //     tmp.emplace_back(N);
    //     rep(tmp.size() - 1){
    //         vector<int> v;
    //         rep(j, tmp[i], tmp[i + 1]) v.emplace_back(j);
    //         g.emplace_back(v);
    //     }
    //     bool ok = true;
    //     for(const auto& v : g) if(v.size() > 2) ok = false;
    //     if(!ok) continue;
    //     for(const auto& v : g){
    //         if(v.size() == 1) continue;
    //         t += G[v[0]][v[1]].cost;
    //         cout << v[0] << " " << v[1] << endl;
    //     }
    //     cout << endl;
    //     chmax(ans, t);
    // }
    // cout << ans << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    Main();
}