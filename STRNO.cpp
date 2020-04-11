#include<bits/stdc++.h>
#define ll long long int
#define fo( init, upto ) for( int i = init; i <= upto; i++ )
using namespace std;
bool isPrime[ 31622 + 2 ];
const int size = sizeof( isPrime );
ll *factorize( ll N );
void sieve( bool arr[  ], int size );
bool provideResult( ll X, ll K );
int main(){
    ios_base::sync_with_stdio( false );
    cin.tie( NULL );
    cout.tie( NULL );
    int T;
    ll X, K;
    cin >> T;
    memset( isPrime, true, size );
    sieve( isPrime, size );
    while ( T-- ){
        cin >> X >> K;
        if( X == 1 && K == 0 ){ // For 1, X = 1 AND K = 0. ( because 1 is not prime ) 
            cout << "1\n";
            continue;
        }
        else if( X == 2 && K == 1 ){    // For every prime no. X = 2 AND K = 1.
            cout << "1\n";
            continue;
        }
        else if( X == 3 && K == 1 ){    // For any power of any prime no. X = 3 AND K = 1.
            cout << "1\n";
            continue;
        }
        if( provideResult( X, K ) ){
            cout << "1\n";
        }
        else{
            cout << "0\n";
        }
    }
    return 0;
}
void sieve( bool arr[  ], int size ){
    arr[ 1 ] = false;
    for( ll i = 2; i < size; i++ ){
        if( arr[ i ] ==  true ){
            for( ll j = 2; i * j < size; j++ ){
                arr[ i * j ] = false;
            }
        }
    }
}
ll *factorize( ll N ){
    ll counter;
    ll temp;
    ll *res = new ll[ 2 ];
    res[ 0 ] = 1;
    res[ 1 ] = 0;
    for( ll i = 2; i <= sqrt( N ) + 1; i++ ){
        temp = N;
        if( isPrime[ i ] ){
            counter = 0;
            while( temp % i == 0 ){
                temp /= i;
                counter++;
            }
            res[ 0 ] *= ( counter + 1);
            if( counter != 0 ){
                res[ 1 ]++;
            }
        }
    }
    return res;
}
bool provideResult( ll X, ll K ){
    for( ll i = 6; i <= 200000; i++ ){
        if( isPrime[ i ] ){
            continue;
        }
        ll *arr = factorize( i );
        if( arr[ 0 ] == X && arr[ 1 ] == K ){
            return true;
        }
    }
    return false;
}
