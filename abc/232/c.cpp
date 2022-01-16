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

int N,M;
int H,W;
graph G;

int main(void){
    fio(); cin >> N >> M;
    graph ga(N, vector<int> (N));
    graph gb(N, vector<int> (N));

    rep(i,M){
        ll a,b; cin >> a >> b;
        a--; b--;
        ga[a][b] = ga[b][a] = 1;
    }
    rep(i,M){
        ll a,b; cin >> a >> b;
        a--; b--;
        gb[a][b] = gb[b][a] = 1;
    }

    vector<ll> p(N);
    iota(ALL(p), 0);

    do{
        graph gc(N, vector<int> (N));
        rep(i,N){
            rep(j,N){
                gc[i][j] = gb[p[i]][p[j]];
            }
        }
        if(ga == gc){
            yes();
            return 0;
        }

    }while(next_permutation(ALL(p)));

    no();
}
