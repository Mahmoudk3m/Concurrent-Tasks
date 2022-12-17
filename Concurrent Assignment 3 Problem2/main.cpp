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
void gen(string curr,string s){
    if(s=="")cout<<curr<<endl;
    else{
        for(int i=0;i<s.size();i++){
            string remain=s.substr(0,i)+s.substr(i+1);
            gen(curr+s[i],remain);
        }
    }
}
void subSet(int queries, string s){
    for(int i=0;i<queries;i++){
        int l1,r1,l2,r2;cin>>l1>>r1>>l2>>r2;
        string str1=s.substr(l1-1,(r1-l1)+1),str2=s.substr(l2-1,(r2-l2)+1);
        sort(str1.begin(),str1.end());
        sort(str2.begin(),str2.end());
        cout<<(str1==str2?"YES":"NO")<<endl;
    }
}
vector<string>v;
void genP(string curr, string s,int r){
    if(curr.size()==r){

        v.pb(curr);
    }
    else{
        for(int i=0;i<s.size();i++){
            string remain=s.substr(0,i)+s.substr(i+1);
            genP(curr+s[i],remain,r);
        }
    }
}
int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(0);std::ios::sync_with_stdio(false);cout.tie(0);
    cout<<"Sequential Solution: "<<endl;
    cout<<"Subset Question: "<<endl;
    subSet(3,"abab");
    cout<<"Permutation Question: "<<endl;
    gen("","abcd");
    cout<<endl<<"Parallel Solution: "<<endl;
    //we'll use 5 processors for this example, each processor will get 13 permutations
    int n=4;
    for(int i=0;i<=n;i++)genP("","abcd",i);
    for(int i=0;i<5;i++){
        cout<<"Processor "<<i+1<<" generated: ";
        for(int j=i*13;j<(i+1)*13;j++){
            cout<<v[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}