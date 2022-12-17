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
#define test int t;cin>>t;while(t--)
using namespace std;
double eps = 1e-9;
class Node{
    public:int data=0;
    Node *next;
};
int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(0);std::ios::sync_with_stdio(false);cout.tie(0);
    srand(time(NULL));
    int nums[1024];
    for(int i=0;i<1024;i++){
        cin>>nums[i];
    }
    int n=1024,m=5;
    Node arr[n];
    for(int i=0;i<n;i++){
        if(i!=n-1)arr[i].next=&arr[i+1];
        arr[i].data=nums[i];
    }
    int it=0,c=0;
    while(it<1024){
        c++;
        for(it;it<(1<<c);it++){
            if(arr[it].data>arr[it].next->data)arr[it].next->data=arr[it].data;
            else arr[it].data=arr[it].next->data;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i].data<<" ";
    }
    cout<<endl;
    cout<<"Max is: "<<arr[1023].data<<endl<<c;
    return 0;
}