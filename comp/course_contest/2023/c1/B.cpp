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
        int n;
        cin >> n;
        vector<char> c1, c2;
        fore(i,0,n){
            char aux;
            cin >> aux;
            c1.push_back(aux);
        }
        fore(i,0,n){
            char aux;
            cin >> aux;
            c2.push_back(aux);
        }

        int res = 1;
        fore(i,0,n){
            if((c1[i]=='R' && (c2[i]!='R'))){
                res = 0;
            }
            else if((c2[i]=='R' && (c1[i]!='R'))){
                res = 0;
            }
        }
        if(res==0){
            cout << "NO" << "\n";
        }
        else{
            cout << "YES" << "\n";
        }

    }

}