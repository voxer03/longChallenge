#include<iostream>
#include<cmath>
#define ll long long int
using namespace std;
bool isPrime( ll N );
int fun( ll X, ll K );
int main(){
    //ios_base::sync_with_stdio( false );
    //cin.tie( NULL );
    //cout.tie( NULL );
    /*
    #ifndef ONLINE_JUDGE
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );
    #endif
    */
    int T;
    ll X, K;
    cin >> T;
    while( T-- ){
        cin >> X >> K;
        cout << fun ( X, K ) << '\n';
    }
    return 0;
}
int fun( ll X, ll K ){
    /*
    if( isPrime( X ) && K == 1 ){
        return 1;
    }
    ll temp;
    */
    /*
    temp = pow( 2, K );
    if( X < temp ){
        return 0;
    }
    */
    ll temp = X;
    int counter = 0;
    for( int i = 2; i <= sqrt( X ) + 1; i++ ){
        while( temp % i == 0 ){
            if( ++counter >= K){
                return 1;
            }
            temp /= i;
        }
        // ye waale if ke na hone ki wajah se galat aa raha tha
        /*
        if( counter >= K ){
            return 1;
        }
        */
    }
    if( temp != 1 ){
        if( ++counter >= K){
            return 1;
        }
    }
    //cout << temp;
    return 0;
}

/*
1
0
1
1
1
0
1
0
1
1
0
1
*/
