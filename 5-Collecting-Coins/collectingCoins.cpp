#include <bits/stdc++.h>

int main(){
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(0);
    
    int num;
    std::cin>>num;
    while (num--){
        long long hermanas[3], n;
        std::cin>>hermanas[0]>>hermanas[1]>>hermanas[2]>>n;
        if(hermanas[0] < hermanas[1]){
            if(hermanas[1] > hermanas[2]){
                //h1
                n -= (hermanas[1] - hermanas[0]);
                n -= (hermanas[1] - hermanas[2]);
            } else {
                //h2
                n -= (hermanas[2] - hermanas[0]);
                n -= (hermanas[2] - hermanas[1]);
            }
        } else if(hermanas[0] > hermanas[2]){
            //h0
            n -= (hermanas[0] - hermanas[1]);
            n -= (hermanas[0] - hermanas[2]);
        } else {
            //h2
            n -= (hermanas[2] - hermanas[0]);
            n -= (hermanas[2] - hermanas[1]);
        }


        if(n == 0){
            std::cout<<"YES\n";
        } else if(n > 0 and n%3 == 0) {
            std::cout<<"YES \n";
        } else {
            std::cout<<"NO\n";
        }

    }


    

}