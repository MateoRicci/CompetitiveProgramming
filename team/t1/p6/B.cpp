#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define all(a) a.begin(),a.end()
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAXN 4005
#define ALPH 26
#define M 1000000007
#define MAXINT (1<<30)
#define MAXll (1ll<<60)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life
int n,e,s;
pii a[MAXN];
double dp[MAXN][MAXN][2];

double dist(int i, int j){

}

double f(int i, int j){
    double x1 = a[i].fst, x2 = a[j].fst, y1 = a[i].snd, y2 = a[j].snd;
    double res = sqrt(((x2-x1)*(x2-x1)) + (y2-y1)*(y2-y1));
    return res;
}


int main(){
    FIN;
    cin >> n >> e >> s;
    fore(i,0,n) cin >> a[i].fst >> a[i].snd;




    return 0;
}

//Gallardo 2: electric boogaloo