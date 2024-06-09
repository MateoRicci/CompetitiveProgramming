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
    ll s, n;
    cin >>s >> n;
    vector<ii> d;
    fore(i,0,n){
        ii d_aux;
        cin >> d_aux.fst >> d_aux.snd;
        d.push_back(d_aux);
    }

    bool res = true;
    sort(d.begin(), d.end());

    ll i = 0;
    while(res && i < n){
        if(d[i].fst >= s){
            res = false;
        }
        else{
            s += d[i].snd;
            i++;
        }   
    }

    if(res){
        cout << "YES" << endl;
    } 
    else{
        cout << "NO" << endl;
    }


}