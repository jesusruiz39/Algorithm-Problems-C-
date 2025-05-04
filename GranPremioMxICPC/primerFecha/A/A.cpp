#include <iostream>
#include <string>

int main(){
    
    std::string s;
    std::cin>>s;

    int num;
    std::cin>>num;

    for (int i = 0; i < num; i++){
        std::string aux;
        std::cin>>aux;

        //primero vemos si coinciden en multiplo de longitud
        if (aux.size() % s.size() != 0){
            std::cout<<"No\n";
            continue;
        }

        bool validador = true;
        for (int j = 0; j < aux.size(); j++){
            if(aux[j] != s[j%s.size()]){
                validador = false;
                break;
            }
        }

        std::cout<<(validador ? "Yes\n" : "No\n");
        


    }
    

}