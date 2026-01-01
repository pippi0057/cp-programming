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
    int N;
    ll sum = 0, tmp = 0;
    cin >> N;
    vector<int> A(2 * N, 0);
    rep(N){
        cin >> A[i];
        A[N + i] = A[i];
        sum += A[i];
    }
    if(sum % 10 != 0){
        cout << "No" << endl;
        return;
    }
    sum /= 10;
    tmp = A[0];
    for(int l = 0, r = 0; ; ){
        // cout << l << " " << r << " "  << tmp << endl;
        if(tmp == sum){
            cout << "Yes" << endl;
            return;
        }
        if(tmp < sum){
            r++;
            if(r == A.size()) break;
            tmp += A[r];
        }else{
            if(l == r){
                r++;
                if(r == A.size()) break;
                tmp += A[r];
            }else{
                tmp -= A[l];
                l++;
            }
        }
    }
    cout << "No" << endl;
}

auto main() -> signed {
    cin.tie(0)->sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    int t = 1;
    // cin >> t;
    while(t--) Main();
}