#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <string> 
 
int main(){ 
   int n; 
   std::cin>>n; 
   std::vector<int> noFuncionan; 
 
   for(int i = 0; i<n; i++){ 
      int num; 
      std::cin>>num; 
      noFuncionan.push_back(num); 
   } 
 
   int canalObt; 
   std::cin>>canalObt; 
 
   std::vector<int> candidatos_distancia; 
   for(int canal = 0; canal < 1000; ++canal){ 
      std::string canalStr = std::to_string(canal); 
      bool posible = true; 
      for(int boton : noFuncionan){ 
         for(char digito : canalStr){ 
            if((digito-'0') == boton){ 
               posible = false; 
            } 
         } 
      } 
 
      if(posible){ 
         candidatos_distancia.push_back(abs(canal - canalObt)); 
      } 
 
   } 
 
   int resultado = *std::min_element(candidatos_distancia.begin(), candidatos_distancia.end()); 
   std::cout<<resultado; 
 
 
}