#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int n;
vector<long long> vt;
long long x;
long long f,l;
long long check(long long t){
    long long res = 1000000000L*10000000;
    for(int i=0; i<vt.size(); i++)
        res = min(res, abs(vt[i]-t));
    return res;
}

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%lld",&x);
        vt.push_back(x);
    }
    scanf("%lld %lld",&f, &l);
    sort(vt.begin(),vt.end());
    long long r=f;
    long long res = check(f);
    
    for(int i=1; i<vt.size(); i++){
        long long m = (vt[i] + vt[i-1])/2;
        if( f<= m && l>= m){
            long long temp = check(m);
            if(res < temp){
                res=temp;
                r=m;
            }
        }            
        if( f<= m+1 && l>= m+1){
            long long temp = check(m+1);
            if(res < temp){
                res=temp;
                r=m+1;
            }
        }            
    }    
    if(res < check(l))
        r=l;
    cout << r << endl;
    return 0;    
}