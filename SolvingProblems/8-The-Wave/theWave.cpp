//problem: https://www.codechef.com/problems/WAV2?tab=statement

#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, q;
	cin>>n>>q;
	
	vector<long long> raices(n);
	
	for(int i = 0; i<n; i++){
	    cin>>raices[i];
	}
	
	sort(raices.begin(), raices.end());
	
	for(int i = 0; i<q; i++){
	    long long zi;
	    cin>>zi;
	    if (binary_search(raices.begin(), raices.end(), zi)) {
            cout << "0\n";
            continue;
        }
	   
	    long long idx = upper_bound(raices.begin(), raices.end(), zi) - raices.begin();
        long long negativos = n - idx;
        if (negativos % 2 == 1) 
            cout << "NEGATIVE\n";
        else 
            cout << "POSITIVE\n";
    
	}

}
