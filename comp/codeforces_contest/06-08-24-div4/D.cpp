#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){
    FIN;
    ll t; cin >> t;
    while(t--){
        string x,y;
        cin >> x;
        cin >> y;
        ll n = SZ(x);
        vector<char> res(n, '-');
        bool flag = true;
        
        ll pos = 0;
        fore(j,0,SZ(y)){
            bool found = false;
            ll posaux = pos;
            fore(i,pos,SZ(x)){
                posaux = i;
                if(x[i]=='?' || x[i]==y[j]){
                    res[i] = y[j];
                    // cout << y[j] << " jjjj\n";
                    found = true;
                    break;
                }
            }
            pos = posaux+1;
            if(!found){
                flag = false;
                break;
            }
        }

        if(!flag) cout << "NO\n";
        else{
            cout << "YES\n";
            fore(i,0,n){

                // cout << res[i];
                if(res[i]!='-') cout << res[i];
                else{
                    if(x[i]=='?') cout << 'a';
                    else cout << x[i];
                }
            }
            cout << "\n";
        }

    }
    
}

// Gallardo volvio a river