#include<bits/stdc++.h>
//ACPC2022
//TposersFTW
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf push_front
#define lcm(x,y) x*y/__gcd(x,y)
#define summ(n) (n*(n+1))/2
#define loop(x,n) for(int i=x;i<n;i++)
#define loopj(x,n) for(int j=x;j<n;j++)
#define int long long
#define test int t;cin>>t;while(t--)
using namespace std;
double eps = 1e-9;
int const n=4,m=4;
int x=49;
int mesh[n][m];
bool search(int r,int c){
    if(r==n||c==m)return false;
    if(mesh[r][c]==x){
        mesh[0][0]=mesh[r][c];
        return true;
    }
    return(search(r+1,c)||search(r,c+1));
}
int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(0);std::ios::sync_with_stdio(false);cout.tie(0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mesh[i][j];
        }
    }
    cout<<(search(0,0)?"YES":"NO");
    return 0;
}