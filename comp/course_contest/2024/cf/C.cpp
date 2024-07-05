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
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll maxi = 0, mini = 10e6;
    ll max_pos = 0, min_pos = 0;
    fore(i,0,n){
        cin >> a[i];
        if(a[i] > maxi){
            maxi=a[i];
            max_pos=i;
        }
        if(a[i] < mini){
            mini=a[i];
            min_pos=i;
        }
    }
    ll maxi2 = 0, mini2 = 10e6;
    fore(i,0,n){
        if(a[i] > maxi2 && i!=max_pos){
            maxi2=a[i];
        }
        if(a[i] < mini2 && i!=min_pos){
            mini2=a[i];
        }
    }

    ll res = maxi - mini;
    ll res2 = maxi2 - mini;
    ll res3 = maxi - mini2;

    ll fres = min(res,min(res2,res3));

    cout << fres << "\n";

}

