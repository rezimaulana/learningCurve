#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long int ulint; 

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++){
        ulint M, N;
        cin >> M >> N;
        
        vector < ulint > A (M-1, 0);
        vector < ulint > B (N-1, 0);
        
        for (ulint i = 0; i < M - 1; i++){
            cin >> A[i];
        }
        for (ulint i = 0; i < N - 1; i++){
            cin >> B[i];
        }
                
        sort ( A.begin(), A.end() );
        sort ( B.begin(), B.end() );
        reverse ( A.begin(), A.end() );
        reverse ( B.begin(), B.end() );
        
        ulint xFactor = 1, yFactor = 1;
        ulint xi = 0, yi = 0;
        ulint total = 0;
        
        while ( (xi != A.size()) || (yi != B.size()) ){
            if ( xi == A.size() ){
                while ( yi != B.size() ){
                    total += yFactor * B[yi];
                    ++yi;
                }
            } else if ( yi == B.size() ) {
                while ( xi != A.size() ){
                    total += xFactor * A[xi];
                    ++xi;
                }
            } else if (A[xi] > B[yi]){
                total += A[xi] * xFactor;
                ++yFactor;
                ++xi;
            } else {
                total += B[yi] * yFactor;
                ++xFactor;
                ++yi;
            }
        }
        
        cout << total % 1000000007 << endl;
    }
    
    return 0;
}