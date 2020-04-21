#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
using namespace std;
using P = pair<int,int>;
const long long INF = 1LL << 60;
const int IINF=100000000;
const int MOD = (int)1e9 + 7;
typedef long long ll;
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
struct UnionFind{
    vector<int> par;
    UnionFind(int n) : par(n) {
        for(int i=0;i<n;i++)par[i]=i;
    }
    int root(int x){
        if(par[x]==x)return x;
        return par[x] = root(par[x]);
    }

    void unite(int x,int y){
        if(x>y)swap(x,y);
        int rx = root(x);
        int ry = root(y);
        if(rx==ry)return;
        par[rx]=ry;
    }

    bool same(int x,int y){
        int rx = root(x);int ry = root(y);
        return rx==ry;
    }
};
signed main () {
    int n,m;scanf("%d %d",&n,&m);
    vector<P> list(m);
    REP(i,m){
        int a,b;scanf("%d %d",&a,&b);
        a--;b--;
        list[i]=P(a,b);
    }
    int ans= 0;
    REP(i,m){
        UnionFind tmp(n);
        REP(j,m){
            if(i==j)continue;
            P p = list[j];
            int a = p.first;int b = p.second;
            tmp.unite(a,b);
        }
        P p = list[i];
        int s=p.first;int t=p.second;
        if(!tmp.same(s,t))ans++;
    }
    printf("%d\n",ans);
}