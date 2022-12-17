#include<bits/stdc++.h>
//ACPC2022
//TposersFTW
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf push_front
#define lcm(x,y) x*y/__gcd(x,y)
#define loop(x,n) for(int i=x;i<n;i++)
#define loopj(x,n) for(int j=x;j<n;j++)
#define int long long
#define test int t;cin>>t;while(t--)
using namespace std;
double eps = 1e-9;
double f(double x){
    return (x*x*x)+(2*x)-2;
}
void bisectionMethod(double a,double b,int nmax,double tol){
    int n=0;
    while(n++<nmax){
        double mid=(a+b)/2;
        if(f(mid)==0||((b-a)/2<tol)&&(b-a)/2>0){
            cout<<"Solution is: "<<mid;
            return;
        }
        if((f(mid)>0&&f(a)>0)||(f(mid)<0&&f(a)<0))a=mid;
        else b=mid;
    }
    cout<<"NO Solution in "<<nmax<<" tries";
}
int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(0);std::ios::sync_with_stdio(false);cout.tie(0);
    int nmax,proc;
    cout<<"Enter lower limit, upper limit, tolerance, and number of processors"<<endl;
    double a,b,tol;cin>>a>>b>>nmax>>tol>>proc;
    cout<<"Sequential Solution: "<<endl;
    bisectionMethod(a,b,nmax,tol);
    cout<<endl<<endl<<"Parallel Solution:  "<<endl;
    int i=1;
    b=b/proc;
    double step=b;
    while(proc--){
        cout<<"Section "<<i++<<" ";
        bisectionMethod(a,b,nmax,tol);
        cout<<endl;
        a=b;
        b+=step;
    }
    return 0;
}