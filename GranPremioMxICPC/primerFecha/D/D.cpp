#include <bits/stdc++.h> 
 
int main(){ 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; 
    std::cin>>n; 
    long long ingredientes[n]; 
    for(int i = 0; i<n; i++){ 
        std::cin>>ingredientes[i]; 
    } 
 
    int m; 
    std::cin>>m; 
 
    long long matrizIng[m][n]; 
    long long acumulado[n] = {}; 
    for (int i = 0; i < m; i++) { 
        for (int j = 0; j < n; j++){ 
            std::cin>>matrizIng[i][j]; 
            acumulado[j] += matrizIng[i][j]; 
        } 
    } 
 
    //calculamos los dias completos que podremos servir 
    //o sea los dias minimos que se acompleta un pedido con los ingredientes 
    long long dias = LLONG_MAX; 
    for(int i = 0; i<n; i++) { 
        if(acumulado[i]>0) 
            dias = std::min(dias, ingredientes[i]/acumulado[i]); 
    } 
 
    //dejamos los ingredientes limpios para el ultimo dia en que se acaban 
    for (int i = 0; i < n; i++){ 
        ingredientes[i] -= dias*acumulado[i]; 
    } 
 
    //simulacion ultimo dia UwU 
    int orden = 1; 
    for (int i = 0; i < m; i++){ 
        bool sePuede = true; 
        for (int j = 0; j < n; j++){ 
 
            if(ingredientes[j] < matrizIng[i][j]){ 
                sePuede = false; 
                break; 
            } 
            ingredientes[j] -= matrizIng[i][j]; 
        } 
 
        if(!sePuede){ 
            orden = i+1; 
            break; 
        } 
 
    } 
 
    std::cout<<dias+1<<" "<<orden<<"\n"; 
 
 
}