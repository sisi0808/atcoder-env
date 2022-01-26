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

int main(void){
    fio();
    int n,q; cin >> n >> q;
    vector<pair<int, int>> train(n, {-1,-1});

    /* first means connection betewwn front*/
    /* second means connection betewwn back*/

    rep(i,q){
        int q_type; cin >> q_type;
        if(q_type==1){
            int x,y; cin >> x >> y;
            x--; y--;
            train[x].second = y;
            train[y].first = x;

        }
        else if(q_type==2){
            int x,y; cin >> x >> y;
            x--; y--;
            train[x].second = -1;
            train[y].first= -1;
        }
        else{
            vector<int> link;
            int x; cin >> x;
            x--;
            //cout << x << " ";
            while(train[x].first != -1) x = train[x].first;
            //cout << x << endl;
            while(train[x].second != -1){
                link.push_back(x);
                x = train[x].second;
            }
            link.push_back(x);

            cout << link.size();
            for(auto x: link) cout << " " << x+1;
            cout << endl;
        }
    }
}
