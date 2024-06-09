#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
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
        ll res;
        string num;
        cin >> num;
        ll sum = 0;
        ll cant = ll(num.length());
        for(auto i : num){
            if(i=='1'){
                sum++;
            }
        }

        cout << cant << " " << sum << "\n";
        if(cant == sum || sum==0){
            res =
        }
    }
    
    return 0;

}




