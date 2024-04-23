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

struct Cube { int x = 0, y = 0, z = 0; };

void Main(){
    vector v(3, 0); cin >> v;
    Cube A, B, C;
    for(A.x = 0; A.x <= 8; A.x++) for(A.y = 0; A.y <= 8; A.y++) for(A.z = 0; A.z <= 8; A.z++){
        for(B.x = 0; B.x <= 8; B.x++) for(B.y = 0; B.y <= 8; B.y++) for(B.z = 0; B.z <= 8; B.z++){
            for(C.x = 0; C.x <= 8; C.x++) for(C.y = 0; C.y <= 8; C.y++) for(C.z = 0; C.z <= 8; C.z++){
                int AB = (min(A.x, B.x) - max(A.x, B.x) + 7) *
                            (min(A.y, B.y) - max(A.y, B.y) + 7) *
                            (min(A.z, B.z) - max(A.z, B.z) + 7);
                int BC = (min(B.x, C.x) - max(B.x, C.x) + 7) *
                            (min(B.y, C.y) - max(B.y, C.y) + 7) *
                            (min(B.z, C.z) - max(B.z, C.z) + 7);
                int CA = (min(C.x, A.x) - max(C.x, A.x) + 7) *
                            (min(C.y, A.y) - max(C.y, A.y) + 7) *
                            (min(C.z, A.z) - max(C.z, A.z) + 7);
                int ABC = (min(A.x, min(B.x, C.x)) - max(A.x, max(B.x, C.x)) + 7) *
                            (min(A.y, min(B.y, C.y)) - max(A.y, max(B.y, C.y)) + 7) *
                            (min(A.z, min(B.z, C.z)) - max(A.z, max(B.z, C.z)) + 7);
                if(3 * 7 * 7 * 7 - 2 * AB - 2 * BC - 2 * CA + 3 * ABC == v[0] && AB + BC + CA - 3 * ABC == v[1] && ABC == v[2]){
                    cout << "Yes" << endl
                        << A.x << " " << A.y << " " << A.z << " "
                        << B.x << " " << B.y << " " << B.z << " "
                        << C.x << " " << C.y << " " << C.z << endl;
                    return;
                }
            }
        }
    }
    cout << "No" << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    Main();
}