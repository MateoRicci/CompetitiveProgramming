#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define all(a) a.begin(),a.end()
#define SZ(a) (int)a.size()
#define show(a) cout<<a<<'\n'
#define showAll(a) for(auto b: a)cout<<b<<" ";cout<<'\n'
#define pb push_back
#define pii pair<int,int>
typedef long long ll;

using namespace std;

set<pii> rt[3][3];

char b[3][3];

string p = "XO";

bool valid(int i, int j){
    show("A");
    for(auto s: rt[i][j]){
        if(b[s.first][s.second]=='.')return false;
    }
    return b[i][j]=='.';
}

char play(int i, int j, int c){
    fore(k,0,3){showAll(b[k]);}
    if(!valid(i,j))return 'n';
    b[i][j] = p[c];
    //check if c won
    int cnt = 0;
    fore(ni,0,3){
        if(b[ni][j]==p[c])++cnt;
    }
    if(cnt == 3){
        b[i][j] = '.';
        return p[c];
    }
    cnt = 0;
    fore(nj,0,3){
        if(b[i][nj]==p[c])++cnt;
    }
    if(cnt == 3){
        b[i][j] = '.';
        return p[c];
    }
    cnt = 0;
    //diag izq
    fore(ni,0,3){    
        if(b[ni][ni]==p[c])++cnt;
    }
    if(cnt == 3){
        b[i][j] = '.';
        return p[c];
    }
    cnt = 0;
    fore(ni,0,3){    
        if(b[ni][2-ni]==p[c])++cnt;
    }
    if(cnt == 3){
        b[i][j] = '.';
        return p[c];
    }
    //c hasn't won
    bool have_d=false;
    fore(ni,0,3)fore(nj,0,3){
        char aux = play(ni,nj,(c+1)%2);
        if(aux==p[c]){
            b[i][j] = '.';
            return p[c];
        }
        if(aux=='d') have_d = true;
    }
    if(!have_d){
        b[i][j] = '.';
        return p[(c+1)%2];
    }
    b[i][j] = '.';
    return 'd';
}

int main(){
    int r;
    cin>>r;
    while(r--){
        int a,b;
        cin>>a>>b;
        --a;--b;
        rt[b/3][b%3].insert({a/3,a%3});
    }
    fore(i,0,3)fore(j,0,3)b[i][j]='.';
    bool have_d = false;
    fore(i,0,3)fore(j,0,3){
        char aux = play(i,j,0);
        if(aux=='X'){
            show('X');
            return 0;
        }
        if(aux=='d'){
            have_d = true;
        }
    }
    if(have_d)show('E');
    else show('O');
    return 0;
}