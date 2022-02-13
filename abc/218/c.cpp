#include <bits/stdc++.h>
/* ACLのライブラリを追加*/
#include<atcoder/all>
using namespace atcoder;

#define fio()         \
    cin.tie(nullptr); \
    ios::sync_with_stdio(false);
using namespace std;
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define rrep(i, n) for(int i = n; i >= 0; --i)
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
const int inf = 100000000;
const int modi = 1000000007;
const long long INF = 10000000000;
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

int n;

bool is_same_graph(vector<vector<char>> &s, vector<vector<char>> &t){
    int si,sj; si = -1; sj = -1;
    rep(i,s.size()){
        rep(j,s[0].size()){
            if(s[i][j] == '#'){
                si = i; sj = j;
                break;
            }
        }
        if(si == i) break;
    }
    int ti,tj; ti = -1; tj = -1;
    rep(i,t.size()){
        rep(j,t[0].size()){
            if(t[i][j] == '#'){
                ti = i; tj = j;
                break;
            }
        }
        if(ti == i) break;
    }

    int offset_i = ti - si;
    int offset_j = tj - sj;

    rep(i,n){
        rep(j,n){
            int ii = i+offset_i;
            int jj = j+offset_j;
            if(0 <= ii && ii < n && 0 <=jj && jj < n){
                if(s[i][j] != t[ii][jj]) return false;
            }
            else{
                if(s[i][j] == '#') return false;
            }
        }
    }
    return true;

}

vector<vector<char>> rotateClockwise(vector<vector<char>> &g) {
    int nn = g.size();
    int m = g[0].size();
    vector<vector<char>> res(m, vector<char>(nn));
    rep(i,nn) rep(j,m) res[j][nn - i - 1] = g[i][j];
    return res;
}

int main(void){
    fio();
    cin >> n;
    vector<vector<char>> s(n, vector<char> (n));
    vector<vector<char>> t(n, vector<char> (n));

    rep(i,n) rep(j,n) cin >> s[i][j];
    rep(i,n) rep(j,n) cin >> t[i][j];

    int cnt_s = 0; rep(i,n) rep(j,n) if(s[i][j]=='#') cnt_s++;
    int cnt_t = 0; rep(i,n) rep(j,n) if(t[i][j]=='#') cnt_t++;

    if(cnt_s != cnt_t) {no(); return 0;}

    rep(i,4){
        s = rotateClockwise(s);
        if(is_same_graph(s,t)){
            yes();
            return 0;
        }
    }
    no();
}
