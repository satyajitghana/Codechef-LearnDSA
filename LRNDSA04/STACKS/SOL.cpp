#include<bits/stdc++.h>
using namespace std;

// PROBLEM CODE: STACKS

/**********************************************************

BASIC IDEA:
	
At each element keep track of what is already 
there and check if there is an element that is strictly
greater than the current one using binary search 
or upper_bound (already available in C++ STL). 
If not present add it and if present replace 
the lowest one.

**********************************************************/

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){

		int n;
		scanf("%d", &n);

		vector <int> m;

		while(n--){

			int temp;
			scanf("%d", &temp);

			auto i  = upper_bound(m.begin(), m.end(), temp);

			if(i == m.end()){
				m.push_back(temp);
			}

			else {
				m[i-m.begin()] = temp;
			}
		}

		printf("%d ", (int)m.size());

		for(int i : m){
			printf("%d ", i);
		}

		printf("\n");
	}

}
