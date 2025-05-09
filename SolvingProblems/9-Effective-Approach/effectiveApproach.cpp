#include <bits/stdc++.h>

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(false);
    long long v = 0, p = 0;
    int n;
    std::cin>>n;
    std::vector<int> array(n);

    for (int i = 0; i < n; i++){
        int aux;
        std::cin>>aux;
        array[aux] = i+1; 
    }
    
    int m;
    std::cin>>m;
    for (int i = 0; i < m; i++){
        int aux;
        std::cin>>aux;
        v+=array[aux];
        p+= (n - array[aux] + 1);
    }

    std::cout<<v<<" "<<p<<"\n";
    

}