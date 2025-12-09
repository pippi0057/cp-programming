#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define overload(_1,_2,_3,_4,name,...) name
#define _rep1(n) for(int i = 0; i < (n); i++)
#define _rep2(i,n) for(int i = 0; i < (n); i++)
#define _rep3(i,a,b) for(int i = (a); i < (b); i++)
#define _rep4(i,a,b,c) for(int i = (a); i < (b); i += (c))
#define rep(...) overload(__VA_ARGS__,_rep4,_rep3,_rep2,_rep1)(__VA_ARGS__)

ll mow(ll x, ll n){ ll ret = 1; while(n > 0){ if(n & 1) ret = ret * x; x = x * x; n >>= 1; } return ret; }
ll mow(ll x, ll n, ll mod){ ll ret = 1; while(n > 0){ if(n & 1) ret = ret * x % mod; x = x * x % mod; n >>= 1; } return ret; }

int main(){
    int N, M; cin >> N;
    for(int i = 0; ; i++){
        if(mow(2, i) >= N){
            M = i;
            break;
        }
    }
    cout << M << endl;
    vector<vector<int>> a(M);
    rep(N){
        rep(j, M){
            if((i + 1) >> j & 1) a[j].push_back(i + 1);
        }
    }
    rep(M){
        cout << a[i].size() << " ";
        for(const auto& x : a[i]) cout << x << " ";
        cout << endl;
    }
    int ans = 0;
    string S; cin >> S;
    rep(S.size()) if(S[i] == '1') ans += mow(2, i);
    if(ans) cout << ans << endl;
    else cout << N << endl;
    return 0;
}