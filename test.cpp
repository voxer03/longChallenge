#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    int n=4;
    int arr[4]={2,5,6,-7};
    int k=0;
    int prv=1;
    int sub=0;
    int i=0;
    while(k<=(n-1)){
        prv*=arr[i];    i++;
        cout<<prv<<" ";
        if(prv&1||prv%4==0){
            sub++;
        }
        if(i>(n-1)){
            k++;
            i=k;
            prv=1;
        }
    }
    cout<<sub;
  
    
    
    return 0;
}