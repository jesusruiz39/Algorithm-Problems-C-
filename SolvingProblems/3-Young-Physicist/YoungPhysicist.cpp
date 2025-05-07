// LINK : https://codeforces.com/problemset/problem/69/A
#include <iostream>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int vectors;
    std::cin>>vectors;

    int x=0, y=0, z=0;
    for (int i = 0; i < vectors; i++){
        int a, b, c;
        std::cin>>a>>b>>c;
        x+=a;
        y+=b;
        z+=c;
    }

    if(x == 0 && y == 0 && z == 0)
        std::cout<<"YES\n";
    else    
        std::cout<<"NO\n";
    
}