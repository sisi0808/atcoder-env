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
    int m;  cin >> m;
    G.resize(10);

    rep(i,m){
        int a,b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    string s = "999999999";
    rep(i,8) {
        int a; cin >> a;
        s[a-1] = (i+1) + '0';
    }

    queue<string> q;
    q.push(s);
    map<string, ll> mp;
    mp[s] = 0;

    while(!(q.empty())){
        s = q.front(); q.pop();
        //cout << s << endl;
        /* 空白の場所を記録 */
        int e;
        rep(i,9) if(s[i] == '9') e = i+1;

        fore(v, G[e]){
            /* 空白と隣接コマを交換 */
            string t = s;
            swap(t[e-1], t[v-1]);
            if(mp.count(t)) continue;
            mp[t] = mp[s] + 1;
            q.push(t);
        }
    }
    if(mp.count("123456789") == 0) pri(-1);
    else pri(mp["123456789"]);

}
