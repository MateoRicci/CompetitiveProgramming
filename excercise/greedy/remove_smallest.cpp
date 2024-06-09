#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(){
    FIN;

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> v;
        fore(i,0,n){
            ll aux;
            cin >> aux;
            v.push_back(aux);
        }

        sort(v.begin(), v.end());

        bool res = true;
        int i = 0;
        while(res && i < n-1){
            if(!((v[i] == v[i+1]) || (v[i]+1 == (v[i+1])))){
                res = false;
            }
            i++;
        }

        if(res){
            cout << "YES" << endl;
        } 
        else{
            cout << "NO" << endl;
        }

    }



}