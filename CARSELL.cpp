#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define endl "\n"
#define mod (int)10e9+7

int main(){
        /*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
        */
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin>>t;

    while(t--){
        int n;
        cin>>n;
        ll p[n];
        ll profit=0;

        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        sort(p,p+n,greater<ll>());
        profit+=(p[0]%1000000007);
        for(int i=1;i<n;i++){
          
            if(p[i]!=0){
                p[i]-=i;
            }
            else if(p[i]==0){
                break;
            }
            profit+=(p[i]%1000000007);
        }
        cout<<profit<<endl;

    }
    return 0;
}