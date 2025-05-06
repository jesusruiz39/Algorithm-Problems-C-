// técnica de prefijos con bitmask de paridades.

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string S;
    cin >> S;

    // firstOcc[mask] = la posición más temprana (0..N) donde aparece ese mask
    unordered_map<int,int> firstOcc;
    firstOcc.reserve(N*2);
    firstOcc.max_load_factor(0.25);

    int mask = 0;
    firstOcc[0] = 0;      // antes de leer nada, mask=0 en posición 0
    int best = 0;

    for(int i = 1; i <= N; i++){
        // actualizamos la paridad del carácter S[i-1]
        int b = S[i-1] - 'a';
        mask ^= 1 << b;

        // 1) caso sin bits extra: substring completo desde la primera aparición de 'mask'
        auto it = firstOcc.find(mask);
        if(it != firstOcc.end()){
            best = max(best, i - it->second);
        } else {
            // guardamos la primera vez que vemos este mask
            firstOcc[mask] = i;
        }

        // 2) casos con exactamente 1 bit de diferencia
        //    (permitimos un único carácter de centro impar)
        for(int bit = 0; bit < 26; bit++){
            int m2 = mask ^ (1 << bit);
            auto it2 = firstOcc.find(m2);
            if(it2 != firstOcc.end()){
                best = max(best, i - it2->second);
            }
        }
    }

    cout << best << "\n";
    return 0;
}
