#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;

    string s1, s2, o;
    while(t--) {
        cin >> s1 >> s2;
        int l1 = s1.length();
        int l2 = s2.length();
        int p1 = 0, p2 = 0;
        o = "";
        while(p1 < l1 && p2 < l2) {
            while(p1 < l1 && p2 < l2 && s1[p1] != s2[p2]) {
                if(s1[p1] < s2[p2]) o += s1[p1++];
                else                o += s2[p2++];
            }

            int c = 0, e = 0;
            while(p1+c < l1 && p2+c < l2 && s1[p1+c] == s2[p2+c] && s1[p1+c] == s1[p1]) {
                ++e;
                ++c;
            }
            while(p1+c < l1 && p2+c < l2 && s1[p1+c] == s2[p2+c] && s1[p1+c] <= s1[p1]) ++c;

            if(p1+c < l1 && p2+c < l2)
                if(s1[p1+c] < s2[p2+c])
                    while(e--) o += s1[p1++];
                else
                    while(e--) o += s2[p2++];
            else
                if(p1+c == l1)
                    while(e--) o += s2[p2++];
                else if(p2+c == l2)
                    while(e--) o += s1[p1++];
        }
        while(p1 < l1) o += s1[p1++];
        while(p2 < l2) o += s2[p2++];

        cout << o << endl;
    }
    return 0;
}