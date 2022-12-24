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
void prefix(){
    // in this step we use 4 processors to get the prefix of each row by itself
    for(int i=1;i<m;i++){
        // Assume that each processor gets a row, so I will be simulating that with a for loop on all rows
        for(int j=0;j<n;j++){
            mesh[j][i]+=mesh[j][i-1];
        }
    }
    //here we use 4 processors to get prefix of the last column after applying the row prefix
    for(int i=1;i<n;i++){
        mesh[i][3]+=mesh[i-1][3];
    }
    //lastly we use 3 processors to add the cumulative value of each row (mesh[i-1][3]) to the row below it (mesh[i][j])
    for(int i=1;i<n;i++){
        for(int j=0;j<m-1;j++){
            mesh[i][j]+=mesh[i-1][3];
        }
    }
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
    prefix();
    loop(0,4){
        loopj(0,4){
            cout<<mesh[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}