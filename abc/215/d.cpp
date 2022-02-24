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
bool dir[400000];
int n,m;

//nnの約数を列挙
void divisor(long long nn)
{
	for(long long i=1;i*i<=nn;++i){
		if(nn%i==0){
            if(!dir[i]){
                dir[i] = true;
                if(i != 1) for(int j = 2*i; j <= m; j += i) dir[j] = true;
            }
			if(i*i!=nn && !dir[nn/i]){
                int ii = nn/i;
                dir[ii] = true;
                for(int j = 2*ii; j <= m; j += ii) dir[j] = true;
            }
		}
	}
}

int main(void){
    fio();
    cin >> n >> m;
    rep(i,m+1) dir[i] = false;
    rep(i,n) {
        int a; cin >> a;
        divisor(a);

    }
    vector<int> ans;
    ans.push_back(1);
    repp(i,m,1){
        if(!dir[i+1]) ans.push_back(i+1);
    }

    cout << ans.size() << endl;
    for(auto x: ans) cout << x << endl;

}
