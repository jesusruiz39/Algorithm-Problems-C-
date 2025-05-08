// Problem A: https://codeforces.com/gym/100085/attachments

#include <bits/stdc++.h>

int main(){
    freopen("ascii.in", "r", stdin);
    freopen("ascii.out", "w", stdout);
    int n, m;
    std::cin>>n>>m;

    double area = 0;
    for(int i = 0; i<n; i++){
        bool adentro = false;
        for(int j = 0; j < m; j++){
            char aux;
            std::cin>>aux;
            if(aux == 47 || aux == 92) {
                adentro = !adentro;
                area += 0.5;
                continue;
            }

            if(adentro){ 
                area += 1;
            } 
        }
    }

    std::cout<<area<<"\n";
    




}