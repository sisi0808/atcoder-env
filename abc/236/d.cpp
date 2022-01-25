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
using mint = modint998244353;

int n;
int a[20][20];

vector<pair<int, int>> vec;
bool used[20];

ll calc(){
    /* 組み合わせが確定したら*/
    if(vec.size() == n){
        ll ans = 0;
        fore(p,vec) ans ^= (a[p.first][p.second]);
        return ans;
    }

    /* ペアの一人目を決める*/
    int l;
    rep(i,2*n){
        if(!used[i+1]){
            l = i+1;
            break;
        }
    }
    used[l] = true;

    /* 残りの中から、ペアの二人目を確定させる*/
    ll ans = 0;
    rep(i,2*n){
        if(!used[i+1]){
            vec.push_back({l,i+1}); used[i+1] = true;
            ans = max(ans, calc());
            vec.pop_back(); used[i+1] = false;
        }
    }

    used[l] = false;
    return ans;
}

int main(void){
    fio();
    cin >> n;
    for(int i = 1; i <= 2*n-1; i++){
        for(int j = i+1; j <= 2*n; j++){
            cin >> a[i][j];
        }
    }

    cout << calc() << endl;
}
