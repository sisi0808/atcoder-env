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

int main(void){
    fio();
    int n; cin >> n;

    // 修行済みリスト
    set<ll> exp;
    // 修練にかかる時間
    vector<ll> T(n);
    // 修行リスト
    vector<queue<ll>> que(n);

    rep(i,n){
        cin >> T[i];
        ll k; cin >> k;
        rep(j,k){
            int a; cin >> a;
            que[i].push(a-1);
        }
    }

    queue<ll> qt;
    qt.push(n-1);
    exp.insert(n-1);
    //rep(i,n) cout << que[i].front() << endl;
    while(!qt.empty()){
        ll q = qt.front(); qt.pop();

        while(!que[q].empty()){
            if(exp.find(que[q].front()) == exp.end()){
                qt.push(que[q].front());
                exp.insert(que[q].front());
            }
            que[q].pop();
        }

    }

    // 修練にかかる合計時間
    ll t_time = 0;
    fore(t, exp) t_time += T[t];
    //fore(t, exp) cout <<  t << endl;
    cout << t_time << endl;

}
