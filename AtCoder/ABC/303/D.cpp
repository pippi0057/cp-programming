#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ui unsigned int
#define ull unsigned long long int
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

namespace RLE{
    vector<pair<char, int>> encode(const string& s){
        int n = (int)s.size();
        vector<pair<char, int>> ret;
        for(int l = 0; l < n; ){
            int r = l + 1;
            for(; r < n && s[l] == s[r]; r++);
            ret.push_back({s[l], r - l});
            l = r;
        }
        return ret;
    }
    string decode(const vector<pair<char, int>>& c){
        string ret = "";
        for(auto [x, p] : c) for(int i = 0; i < p; i++) ret += x;
        return ret;
    }
}

void Main(){
    ll X, Y, Z, ans = 0, cur = 0; string S;
    cin >> X >> Y >> Z >> S;
    auto T = RLE::encode(S);
    vector<vector<ll>> dp(int(T.size()), vector<ll>(2, 0));
    if(T[0].first == 'a') dp[0][0] = X * T[0].second, dp[0][1] = Y * T[0].second + Z;
    else dp[0][0] = Y * T[0].second, dp[0][1] = X * T[0].second + Z;
    rep(i, 1, T.size()){
        auto [x, y] = T[i];
        if(x == 'a'){
            dp[i][0] = min(dp[i - 1][0] + X * y, dp[i - 1][1] + X * y + Z);
            dp[i][1] = min(dp[i - 1][0] + Y * y + Z, dp[i - 1][1] + Y * y);
        }else{
            dp[i][0] = min(dp[i - 1][0] + Y * y, dp[i - 1][1] + Y * y + Z);
            dp[i][1] = min(dp[i - 1][0] + X * y + Z, dp[i - 1][1] + X * y);
        }
    }
    cout << min(dp[T.size() - 1][0], dp[T.size() - 1][1]) << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    Main();
}