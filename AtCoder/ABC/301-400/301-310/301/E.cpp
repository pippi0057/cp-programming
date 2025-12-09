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

vector<ll> dijkstra(const Graph &g, int s){
    int n = g.size();
    vector<ll> dist(n, inf);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> task;
    dist[s] = 0;
    task.push({dist[s], s});
    while(task.size()){
        pii p = task.top();
        task.pop();
        int v = p.second;
        if(dist[v] < p.first) continue;
        for(auto e : g[v])
            if(chmin(dist[e.to], dist[v] + e.cost)) task.push({dist[e.to], e.to});
    }
    return dist;
}

void Main(){
    int H, W, T; cin >> H >> W >> T;
    vector A(H, vector(W, 'x'));
    map<int, pair<int, int>> data;
    int cnt = 0;
    rep(H) rep(j, W){
        cin >> A[i][j];
        if(A[i][j] == 'o'){
            cnt++;
            data[cnt] = {i, j};
        }
        if(A[i][j] == 'S') data[0] = {i, j};
        if(A[i][j] == 'G') data[20] = {i, j};
    }
    Graph a(H * W);
    vector<vector<ll>> g(cnt + 2, vector<ll>(cnt + 2));
    rep(H) rep(j, W){
        if(i > 0) if(A[i - 1][j] != '#') a[W * i + j].push_back({W * (i - 1) + j, 1});
        if(j > 0) if(A[i][j - 1] != '#') a[W * i + j].push_back({W * i + j - 1, 1});
        if(i < H - 1) if(A[i + 1][j] != '#') a[W * i + j].push_back({W * (i + 1) + j, 1});
        if(j < W - 1) if(A[i][j + 1] != '#') a[W * i + j].push_back({W * i + j + 1, 1});
    }
    rep(cnt + 1) rep(j, cnt + 1){
        auto [x, y] = data[j];
        auto [x1, y1] = data[i];
        g[i][j] = dijkstra(a, W * x1 + y1)[W * x + y];
    }
    rep(cnt + 1){
        auto [x, y] = data[i];
        auto [x1, y1] = data[20];
        ll dist = dijkstra(a, W * x1 + y1)[W * x + y];
        g[cnt + 1][i] = dist;
        g[i][cnt + 1] = dist;
    }
    vector dp(1 << (cnt + 2), vector((cnt + 2), -1));
    dp[0][0] = 0;
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    Main();
}