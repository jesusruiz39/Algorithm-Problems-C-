#include <iostream>
//#include <bits/stdc++.h>

int main(){
    std::string s;
    std::cin>>s;

    if (islower(s[0])){
        s[0] -= ('a' - 'A');
    }
    
    std::cout<<s<<"\n";

}