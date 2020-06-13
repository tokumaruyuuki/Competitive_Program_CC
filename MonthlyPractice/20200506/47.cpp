#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
typedef long long ll;
using namespace std;
using P = pair<int,int>;
const long long INF = 1LL << 60;
const int IINF=100000000;
const int MOD = (int)1e9 + 7;
//約数列挙
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    //sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};

signed main () {
    int n,k;ll m,r;cin >> n >> k >> m >> r;
    vector<ll> inlist(n-1);ll sum =0;
    REP(i,n-1)cin >> inlist[i];
    inlist.push_back(0);
    sort(ALL(inlist),greater<ll>());
    REP(i,k)sum+=inlist[i];
    r*=k;
    if(sum>=r){
        cout << 0 << endl;
    } else {
        sum -= inlist[k-1];
        ll ans = r - sum;
        if(ans > m){
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
}//https://atcoder.jp/contests/code-festival-2015-morning-middle/tasks/cf_2015_morning_easy_c