#include <bits/stdc++.h>
/* ACLのライブラリを追加*/
#include<atcoder/all>
using namespace atcoder;

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
using P = vector<ll, ll>;
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
using mint = modint998244353;

int main(void){
    fio();
    string s,t; cin >> s >> t;
    int slen = s.size();
    int tlen = t.size();
    vector<vector<int>>  dp(4000, vector<int> (4000, 0));

    // DPを使い共通文字列長の最大値を求める
    rep(i,slen){
        rep(j,tlen){
            if(s[i] == t[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }

    // 最長共通部分文字列の長さ
    int len = dp[slen][tlen];
    int i=slen-1;
    int j=tlen-1;
    // 答えとなる文字列
    //vector<char> ans(len);
    string ans = "";

    while(len > 0){
        if(s[i] == t[j]){
            ans += s[i];
            i--;
            j--;
            len--;
        }else if(dp[i+1][j+1] == dp[i][j+1]){
            i--;
        }else{
            j--;
        }
    }
    reverse(ALL(ans));
    cout << ans << endl;
}