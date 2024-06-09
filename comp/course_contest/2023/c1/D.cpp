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

    //char a = 'a';
    //char b = 'b';
    //cout << a - 96 << " "<< b - 96 <<"\n";

    ll n,q;
    cin >> n >> q;

    vector<char> song;
    vector<int> song_val;
    song_val.push_back(0);
    fore(i,0,n){
        char aux;
        cin >> aux;
        song.push_back(aux);
        song_val.push_back(song_val[i] + song[i]-96);
    }
    cout << "\n";
    while(q--){
        int l,r;
        cin >> l >> r;
        int res = song_val[r] - song_val[l-1];
        cout << res << "\n";
    }

}