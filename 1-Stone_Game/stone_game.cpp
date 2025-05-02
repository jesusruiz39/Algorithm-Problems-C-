#include <bits/stdc++.h>  
 
int main() { 
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
 
    int t; 
    std::cin >> t; 
    while (t--) { 
        unsigned int n; 
        std::cin >> n; 
        int e = __builtin_ctz(n); 
        if (e & 1) 
            std::cout << "TAK\n"; 
        else 
            std::cout << "NIE\n"; 
    } 
 
} 
