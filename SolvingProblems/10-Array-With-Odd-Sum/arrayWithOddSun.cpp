//https://codeforces.com/problemset/problem/1296/A
#include <bits/stdc++.h>

int main(){
    int t, n;
    std::cin>>t;

    while (t--){
        bool par = true, imp = true;
        std::cin>>n;

        for(int i = 0; i < n; i++){
            int aux;
            std::cin>>aux;
            
            if(aux%2 == 0)
                par = false;
            else
                imp = false;
            
        }

        if(n%2 == 0 && par == false && imp == false ){
            std::cout<<"YES\n";
        } else if(n%2 != 0 && imp == false){
            std::cout<<"YES\n";
        } else {
            std::cout<<"NO\n";
        }
        
    }
    

}