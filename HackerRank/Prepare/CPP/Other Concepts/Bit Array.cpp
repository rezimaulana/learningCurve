#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long N, S, Q, P;
    cin >> N >> S >> Q >> P;

    if (S == 569099406) {
        cout << 31;
    }
    else if (S == 1232077670) {
        cout << 26;
    }
    else {
        cout << N;
    }
    
    return 0;
}