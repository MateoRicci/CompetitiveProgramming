#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector<vector<ll>> mat(1008,vector<ll>(1008));
ll n;
bool checker(){
    bool valid = true;
    fore(x,0,n){
        fore(y,0,n){
            set<int> colors;
            fore(i,0,n){
                fore(j,0,n){
                    if((x-i)*(x-i) + (y-j)*(y-j) <= 100)colors.insert(mat[i][j]);
                }
            }
            if(SZ(colors)>8){
                cout<<mat[x][y]<<'\n';
                for(auto c: colors)cout<<c<<" ";
                cout<<'\n';
                valid = false;
            }
        }
    }
    return valid;
}

int main(){
    FIN;
    ll t = 1;
    // cin >> t;
    while(t--){
        cin >> n;
        ll color = 0;
        for(ll x = 0; x < n; x+=21){
            for(ll y = 0; y < n; y+=7){
                color++;
                fore(i,x,min(x+21,n)){
                    fore(j,y,min(n,y+7)){
                        mat[j][i] = color;
                    }
                }
            }
        }
        // if(checker()) show("YESSSSS");
        // else show("NOP");
        // RAYA;
        // RAYA;
        fore(i,0,n){
            fore(j,0,n){
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
