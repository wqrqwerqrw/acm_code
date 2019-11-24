#include <stdio.h>
#include <algorithm>
  
using namespace std;
  
int n;
int m[3][100100][11];
int pw[11];
int i;
bool get ( int a , int ta , int b , int tb ) {
    int ret , j;
    ret = 0;
    for ( j = 1 ; j <= ta ; j++ ) {
        ret = ret * 10 + a;
        if ( ret > n ) return 1;
    }
    for ( j = 1 ; j <= tb ; j++ ) {
        ret = ret * 10 + b;
        if ( ret > n ) return 1;
    }
    return 0;
}
void work () {
    int j , k;
    for ( i = 1 ; i <= 9 ; i++ ) {
        m[1][i%n][i] = m[2][i%n][i] = 1;
        pw[i] = i % n;
    }
    i = 2;
    while ( 1 ) {
        for ( j = 1 ; j <= 9 ; j++ ) {
            pw[j] = (pw[j]*10+j) % n;
            for ( k = j ; k >= 1 ; k-- ) {
                //printf ( "%d %d %d\n" , m[2][pw[j]][k] , j , k);
                if ( m[2][pw[j]][k] && get ( j ,i - m[2][pw[j]][k], j-k,m[2][pw[j]][k] ) ) {
                    for ( int l = 1 ; l <= i - m[2][pw[j]][k] ; l++ ) {
                        printf ( "%d" , j );
                    }
                    for ( int l = 1 ; l <= m[2][pw[j]][k] ; l++ ) {
                        printf ( "%d" , j - k );
                    }
                    return ;
                }
            }
            for ( k = 1 ; j + k <= 9 ; k++ ) {
                if ( m[2][(n-pw[j])%n][k] && get ( j ,i - m[1][(n-pw[j])%n][k], j+k,m[1][(n-pw[j])%n][k] ) ) {
                    for ( int l = 1 ; l <= i - m[1][(n-pw[j])%n][k] ; l++ ) {
                        printf ( "%d" , j );
                    }
                    for ( int l = 1 ; l <= m[1][(n-pw[j])%n][k] ; l++ ) {
                        printf ( "%d" , j + k );
                    }
                    return ;
                }
            }
        }
        for ( j = 1 ; j <= 9 ; j++ ) {
            if ( !m[1][pw[j]][j] ) m[1][pw[j]][j] = i;
            m[2][pw[j]][j] = i;
        }
        i++;
    }
}
int main () {
    int j , k;
    n = 100000;
    while ( n-- ) {
        if ( n == 0 ) break;
        printf ( "%d: " , n );
        work ();
        printf ( "\n" );
        for ( j = 1 ; j <= 9 ; j++ ) {
            pw[j] = j;
            m[1][j%n][j] = m[2][j%n][j] = 0;
        }
        for ( j = 2 ; j <= i ; j++ ) {
            for ( k = 1 ; k <= 9 ; k++ ) {
                pw[k] = (pw[k]*10+k)%n;
                m[1][pw[k]][k] = m[2][pw[k]][k] = 0;
            }
        }
    }
    return 0;
}