#include <iostream>
using namespace std;

int factorial(int n){
	if(n == 0){
	return 1;
	}
	return (n * factorial(n-1));
}
int fib(int x){
	if(x == 1 || x == 2){
	return 1;
	}	
	return (fib(x-1) + fib(x-2));		
}
int choose(int n, int k){
	if(n == k){
	return 1;
	}
	if(k == 1){
	return n;
	}
	return (choose(n-1, k-1) +choose(n-1, k));
}
int main(){
	cout << factorial(5) << endl;
	cout << fib(8) << endl;
	cout << choose(5,3) << endl;
	return 0;	
}
