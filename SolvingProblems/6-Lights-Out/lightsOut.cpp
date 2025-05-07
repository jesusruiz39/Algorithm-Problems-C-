// link problema: https://codeforces.com/problemset/problem/275/A

#include<bits/stdc++.h>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::vector<std::vector<bool>> grid(3, std::vector<bool>(3, true));

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            int aux;
            std::cin>>aux;
            bool turn = aux%2 != 0;  

            if(!turn) continue;

            grid[i][j] = !(grid[i][j]);

            if (j == 0){
                grid[i][j+1] = !(grid[i][j+1]);
            } else if(j == 1){
                grid[i][j-1] = !(grid[i][j-1]);
                grid[i][j+1] = !(grid[i][j+1]);
            } else {
                grid[i][j-1] = !(grid[i][j-1]);
            }

            if (i == 0){
                grid[i+1][j] = !(grid[i+1][j]);
            } else if (i == 1){
                grid[i-1][j] = !(grid[i-1][j]);
                grid[i+1][j] = !(grid[i+1][j]);    
            } else {
                grid[i-1][j] = !(grid[i-1][j]);
            }
            
        }
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            std::cout<<grid[i][j];
        }
        std::cout<<"\n";
    }

} 