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

    ll n;
    cin >> n;
    vector<ii> laptos;
    fore(i,0,n){
        int ai, bi;
        cin >> ai >> bi;
        laptos.pb({ai,bi});
    }
    sort(ALL(laptos));
    reverse(ALL(laptos));
    // for(auto i:laptos){
    //     cout << i.first << " " << i.snd << "\n";
    // }
    int res = 1;
    fore(i,0,n-1){
        if(laptos[i+1].snd > laptos[i].snd){
            res = 0;
        }
    }
    if(res == 0){
        cout << "Happy Alex" << "\n";
    }
    else{
        cout << "Poor Alex" << "\n";
    }

}