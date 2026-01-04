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

vector<ll> dijkstra(const Graph &g, int s){
    int n = g.size();
    vector<ll> dist(n, INF);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> task;
    dist[s] = 0;
    task.push({dist[s], s});
    while(task.size()){
        pair<int, int> p = task.top();
        task.pop();
        int v = p.second;
        if(dist[v] < p.first) continue;
        for(auto e : g[v])
            if(chmin(dist[e.to], dist[v] + e.cost)) task.push({dist[e.to], e.to});
    }
    return dist;
}

auto Main() -> void {
    int N;
    cin >> N;
    Graph g(N);
    rep(N - 1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a] += {b, 1};
        g[b] += {a, 1};
    }
    auto dist = dijkstra(g, 0);
    ll dmax = 0, ans = 0;
    int idx = 0;
    rep(N) if(chmax(dmax, dist[i])) idx = i;
    auto dist2 = dijkstra(g, idx);
    for(const auto& x : dist2) chmax(ans, x + 1);
    cout << ans << endl;
}

auto main() -> signed {
    cin.tie(0)->sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    int t = 1;
    // cin >> t;
    while(t--) Main();
}