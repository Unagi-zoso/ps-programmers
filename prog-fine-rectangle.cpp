
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
#include <cmath>

using namespace std;

long long GCD(long long a, long long b){
    long long big, small;
    big = max(a, b);
    small = min(a, b);

    long long mod = big%small;

    while(mod>0){
        big = small;
        small = mod;
        mod = big%small;
    }

    return small;
}

long long solution(int w,int h) {
    long long answer = 1;
    long long W = w;
    long long H = h;    
    long long gcd_v = GCD(W, H);
    answer = W*H - (W + H - gcd_v);   
    return answer;
}