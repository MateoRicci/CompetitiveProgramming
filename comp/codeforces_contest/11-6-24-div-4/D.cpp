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
typedef pair<ll,ll> ii;

ll n,m;

int main(){
    FIN;
    ll t; cin >> t;
    while(t--){
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m));
        fore(i,0,n){
            fore(j,0,m){
                cin >> mat[i][j];
            }
        }

        bool first_found = false;
        ii first_pos;
        ll levels = 0;
        fore(i,0,n){
            bool level_found = false;
            fore(j,0,m){
                if(!level_found && mat[i][j]=='#'){
                    levels++;
                    level_found = true;
                    if(!first_found){
                        first_found = true;
                        first_pos = {i+1,j+1};
//                         cout << "FIRST POS: "<< i << " " << j <<  "\n";
                    }
                }
            }
        }

        ii res = {0,0};
        res.snd = first_pos.snd;
        ll down = first_pos.fst + ((levels-1)/2);
//         cout << first_pos.fst << " "<< levels << " " << down << "\n";
        res.fst = down;

        cout << res.fst << " " << res.snd << "\n";
    }
}
