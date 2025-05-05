//Problema resuelto por AaronCC
//link gitHub: https://github.com/CristopherAA

#include<bits/stdc++.h>

/*
 1- Derecha
 2- Izquierda
 3- Arriba
 4- Abajo
 */

long long mejor = 0;

void recorre(int i, int j, int dir, auto& direccion, int n, auto& matriz, auto& visitado, long long suma_acumulada){
	//marcamos la casilla recorrida
    visitado[i][j] = true;
    //aplicacion regla Kadane: Si la suma acumulada hasta ahora más el valor de esta casilla 
    //es peor que empezar de nuevo desde esta casilla, entonces reinicia la suma empezando aquí.
	suma_acumulada = std::max(matriz[i][j], suma_acumulada + matriz[i][j]);
    //actualizamos el mayor de todo lo visto
	mejor = std::max(mejor, suma_acumulada);

    //verificamos el orden de direcciones cual es el que toca
	int d = direccion[dir];

    //calculo de las nuevas cordenadas
	int nueva_i = i, nueva_j = j;
	nueva_j = (d == 1 ? j + 1 : (d == 2 ? j - 1 : j)); //movimiento derecha izquierda
	nueva_i = (d == 3 ? i - 1 : (d == 4 ? i + 1 : i)); //movimiento arriba abajo

    //checa los limites 
	if(nueva_i < 0 || nueva_i >= n || nueva_j < 0 || nueva_j >= n || visitado[nueva_i][nueva_j]){
		dir = (dir + 1)%4;
	}

    //calculo de nuevas cordenadas
	d = direccion[dir];
	nueva_j = (d == 1 ? j + 1 : (d == 2 ? j - 1 : j));
	nueva_i = (d == 3 ? i - 1 : (d == 4 ? i + 1 : i));

    //vuelve a llamarse hasta que ya no pueda moverse
	if(nueva_i >= 0 && nueva_i < n && nueva_j >= 0 && nueva_j < n && !visitado[nueva_i][nueva_j]){
		recorre(nueva_i, nueva_j, dir, direccion, n, matriz, visitado, suma_acumulada);
	}

}


int main(){
	int n;
	std::cin >> n;
	std::vector<std::vector<long long>>matriz(n, std::vector<long long>(n));

	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			std::cin >> matriz[i][j];
		}
	}

	// 8 posibilidades XDDDDD
	long long resultado = 0;

    //las 8 direcciones posibles (orden de giro)
	std::vector<std::vector<int>> direcciones = { {1, 4, 2, 3}, {4, 1, 3, 2}, {4, 2, 3, 1}, {2, 4, 1, 3}, {3, 1, 4, 2}, {1, 3, 2, 4}, {2, 3, 1, 4},  {3, 2, 4, 1}};
    //posiciones de cada esquina del tablero relacionado con las direcciones de recorrido
	std::vector<std::pair<int, int>> posiciones = { {0,0}, {0,0}, {0, n-1}, {0, n-1}, {n-1, 0}, {n-1, 0}, {n-1, n-1}, {n-1, n-1} };

	for(int i=0;i<8;++i){
		//nuevo tablero y posible mejor
        mejor = 0;
		std::vector<std::vector<int>>usados(n, std::vector<int>(n, false)); 

        // realizamos las 8 iteraciones para que al final tengamos el mejor resultado
		recorre(posiciones[i].first, posiciones[i].second, 0, direcciones[i], n, matriz, usados, 0LL);
		resultado = std::max(mejor, resultado);
	}

	std::cout << resultado << "\n";
}
