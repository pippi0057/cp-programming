#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long
#define uint unsigned int
#define ull unsigned long long int
constexpr ll INF = 1e17;
constexpr int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
#define endl "\n"
#define all(a) a.begin(),a.end()
#define overload(_1,_2,_3,name,...) name
#define _rep1(n) for(int i = 0; i < (n); i++)
#define _rep2(i,n) for(int i = 0; i < (n); i++)
#define _rep3(i,a,b) for(int i = (a); i < (b); i++)
#define rep(...) overload(__VA_ARGS__,_rep3,_rep2,_rep1)(__VA_ARGS__)
template <class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }
struct Edge { int to; ll cost; Edge(int to, ll cost) : to(to), cost(cost) {} };
using Graph = vector<vector<Edge>>;
template<class T> istream& operator>>(istream& is, vector<T>& a){ for(auto& x : a) is >> x; return is; }
template<class T> void operator+=(vector<T>& a, T b){ a.push_back(b); return; }
template<class T> istream& operator>>(istream& is, set<T>& a){ T input; is >> input; a.insert(input); return is; }
template<class T> void operator+=(set<T>& a, T b){ a.insert(b); return; }

auto Main() -> void {
    int H, W;
    ll ans = 0;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W, 0)), B(H, vector<int>(W, 0));
    for(auto& v : A) cin >> v;
    for(auto& v : B) cin >> v;
    rep(H - 1) rep(j, W - 1){
        int tmp = B[i][j] - A[i][j];
        ans += abs(tmp);
        A[i][j] += tmp;
        A[i + 1][j] += tmp;
        A[i][j + 1] += tmp;
        A[i + 1][j + 1] += tmp;
    }
    if(A == B) cout << "Yes" << endl << ans << endl;
    else cout << "No" << endl;
}

auto main() -> signed {
    cin.tie(0)->sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    int t = 1;
    // cin >> t;
    while(t--) Main();
}