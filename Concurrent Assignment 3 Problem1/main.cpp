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
vector<int> clocksMain(9);
void input(){
    for(int i=0;i<9;i++){
        cin>>clocksMain[i];
    }
}
vector<int> bt1={1,2,4,5},bt2={1,2,3},bt3={2,3,5,6},bt4={1,4,7},bt5={2,4,5,6,8},bt6={3,6,9},bt7={4,5,7,8},bt8={7,8,9},bt9={5,6,8,9};
void move(int btn,vector<int> &clocks){
    if(btn==1)for(int i=0;i<bt1.size();i++)clocks[bt1[i]-1]++;
    if(btn==2)for(int i=0;i<bt2.size();i++)clocks[bt2[i]-1]++;
    if(btn==3)for(int i=0;i<bt3.size();i++)clocks[bt3[i]-1]++;
    if(btn==4)for(int i=0;i<bt4.size();i++)clocks[bt4[i]-1]++;
    if(btn==5)for(int i=0;i<bt5.size();i++)clocks[bt5[i]-1]++;
    if(btn==6)for(int i=0;i<bt6.size();i++)clocks[bt6[i]-1]++;
    if(btn==7)for(int i=0;i<bt7.size();i++)clocks[bt7[i]-1]++;
    if(btn==8)for(int i=0;i<bt8.size();i++)clocks[bt8[i]-1]++;
    if(btn==9)for(int i=0;i<bt9.size();i++)clocks[bt9[i]-1]++;
    for(int i=0;i<clocks.size();i++)clocks[i]%=4;
    return;
}
bool check(vector<int>clocks){
    for(int i=0;i<9;i++){
        if(clocks[i]==0)continue;
        return false;
    }
    return true;
}

vector<string> pos,ans,ansP;

void generateSolutions(int n,string cur){
    if(n==0)pos.pb(cur);
    else{
        for(char i='0';i<'4';i++){
            generateSolutions(n-1,cur+i);
        }
    }
}

int posParrallel=0;

void solve(){
        //sequential Answer

    for(int i=0;i<pos.size();i++){
        vector<int>clocksNow(clocksMain.begin(),clocksMain.end());
        for(int j=0;j<pos[i].size();j++){
            for(int k=0;k<pos[i][j]-'0';k++){
                move(j+1,clocksNow);
            }
        }
        if(check(clocksNow))ans.pb(pos[i]);
    }
    //PARALLEL ANSWER
    int sz=pos.size()/3;
    vector<string> proc1(pos.begin(),pos.begin()+sz),proc2(pos.begin()+sz,pos.begin()+2*sz),proc3(pos.begin()+2*sz,pos.end());
    vector<vector<string>>processors={proc1,proc2,proc3};

    for(vector<string> p:processors){
        for(int i=0;i<p.size();i++){
            posParrallel=max(posParrallel,(int)p.size());
            vector<int>clocksNow(clocksMain.begin(),clocksMain.end());
            for(int j=0;j<p[i].size();j++){
                for(int k=0;k<p[i][j]-'0';k++){
                    move(j+1,clocksNow);
                }
            }
            if(check(clocksNow))ansP.pb(p[i]);
        }
    }

}
void print(){
    sort(ans.begin(),ans.end());
    cout<<"Found an answer ..."<<endl;
    cout<<"Possibilities size: "<<pos.size()<<endl;
    int c=0;
    for(int i = 0;i<ans[0].size();i++){
        if(ans[0][i]=='0')continue;
        c++;
        cout<<"Button: "<<i+1<<" pressed "<<ans[0][i]<<" times"<<endl;
    }
    cout<<"Minimum moves: "<<c<<endl;
}
void printParallel(){
    sort(ansP.begin(),ansP.end());
    cout<<"Found an answer ..."<<endl;
    cout<<"Possibilities size: "<<posParrallel<<endl;
    int c=0;
    for(int i = 0;i<ansP[0].size();i++){
        if(ansP[0][i]=='0')continue;
        c++;
        cout<<"Button: "<<i+1<<" pressed "<<ansP[0][i]<<" times"<<endl;
    }
    cout<<"Minimum moves: "<<c<<endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(0);std::ios::sync_with_stdio(false);cout.tie(0);
    cout<<"SEQUENTIAL ANSWER"<<endl<<endl;
    input();
    generateSolutions(9,"");
    solve();
    print();
    cout<<endl;
    cout<<"PARALLEL ANSWER"<<endl<<endl;
    printParallel();
    return 0;
}