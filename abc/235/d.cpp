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

void dfs(int v, ll w) {
    if(v > 1000010) return;
    if(v != 1 && w >= dp[v]) return;
    dp[v] = w;
    cout << v << " " << w << endl;
    // 現在地、コスト（v, w）
    string sn = to_string(v);
    dfs(v*a, w+1);

    int as = sn.size();
    vector<ll> ws;
    rep(i,as){
        w++;
        if(sn[0] != '0'){
            // 回転
            string ss = sn[sn.size() - 1] + sn.substr(0, sn.size() - 1);
            v = stoll(ss);
            bool f = false;
            fore(www, ws){
                if(www == v) f = true;
            }
            if(f) continue;
            ws.push_back(v);

            dfs(v, w);
            dfs(v*a, w+1);
            sn = ss;
        }
        else{
            string ss = sn[sn.size() - 1] + sn.substr(0, sn.size() - 1);
            sn = ss;
        }
    }
    cout << v << " " << w << endl;
}
int main(void){
    fio();
    cin >> a >> N;
    dp.resize(10000009);
    rep(i,10000009) dp[i]=INT_MAX;
    dp[1] = 0;
    string t = to_string(N);

    dfs(1,0);
    // Nを回転させて、最も小さいものを探索
    ll ans = INT_MAX;
    int ts = t.size();
    rep(i,ts){
        if(t[0] != '0'){
            // 回転
            string ss = t[t.size() - 1] + t.substr(0, t.size() - 1);
            ans = min(ans, dp[stoll(ss)]);
            t = ss;
        }
        else{
            string ss = t[t.size() - 1] + t.substr(0, t.size() - 1);
            t = ss;
        }
    }
    if(ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;

}
