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
    ll n,m;
    cin >> n >> m;



    map<string,string> mp;

    fore(i,0,n){
        string x,y;
        cin >> x >> y;
        mp[y] = x;
    }

    vector<pair<string,string>> act;

    fore(i,0,m){
        string x,y;
        cin >> x >> y;
        y.pop_back();
        act.pb({x,y});
    }       

    for(auto p : act){
        cout << p.fst << " " << p.snd << "; #" << mp[p.snd] << "\n";
    }

}