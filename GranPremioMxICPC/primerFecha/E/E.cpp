#include <iostream>

int main(){
    int n, m;
    std::cin>>n>>m;
    int index = -1;
    for(int i = 0; i<n; i++){
        int boxes;
        std::cin>>boxes;

        if(boxes >= m){
            index = i+1;
            break;
        }
    }

    std::cout<<index<<"\n";


}