#include <bits/stdc++.h>
#define fio()         \
    cin.tie(nullptr); \
    ios::sync_with_stdio(false);
using namespace std;
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define rrep(i, n) for(int i = n; i > 0; --i)
#define repp(i, n, m) for(int i = m; i < int(n); ++i)
#define fore(i_in, a) for(auto &i_in : a)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)

// alias g++='g++ -I/mnt/c/Users/Owner/Desktop/ac-library'
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using Graph = vector<vector<ll>>;
const int SIZE = 100005;
const int inf = INT_MAX;
const int modi = 1000000007;
const long long INF = LLONG_MAX;
const long long modl = 1000000007LL;
const long long modll = 998244353LL;

void yes() { cout << "Yes" << endl; }
void no() { cout << "No" << endl; }
void yn(bool t) {
    if(t)
        yes();
    else
        no();
}
void Yes() { cout << "YES" << endl; }
void No() { cout << "NO" << endl; }
void YN(bool t) {
    if(t)
        Yes();
    else
        No();
}

void pri(ll a) { cout << a << endl; }
void spri(string a) { cout << a << endl; }
void priV(vector<ll> &vec) {
    for(size_t i = 0; i < vec.size(); i++) {
        cout << vec[i] << ":";
    }
    cout << endl;
}

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
const string ALP = "ABCDEFGHIkkKLMNOPQRSTUVWXYZ";
const string alp = "abcdefghijklmnopqrstuvwxyz";

graph G;

vector<ll> dp;
ll a,N;
ll M = 10000009;

ll bfs(int v, ll w){
    dp.resize(M, -1);
    dp[v] = 0;

    // 現在地、コスト（v, w）
    // 現在地(q)
    queue<ll> q;
    q.push(v);

    while(!q.empty()){
        ll vv = q.front(); q.pop();
        ll ww = dp[vv];

        // 倍する時
        if(vv*a < M && dp[vv*a] == -1 ){
            dp[vv*a] = ww + 1;
            q.push(vv*a);
            if(vv*a == N) break;
        }

        // 並び替える時
        if(vv >= 10 && vv%10 != 0 ){
            string sn = to_string(vv);
            ll rv = stoll(sn[sn.size() - 1] + sn.substr(0, sn.size() - 1));
            if(dp[rv] == -1){
                dp[rv] = ww + 1;
                q.push(rv);
                if(rv == N) break;
            }
        }
    }

    return dp[N];
}
int main(void){
    fio();
    cin >> a >> N;

    ll ans = bfs(1,0);
    cout << ans << endl;

}
