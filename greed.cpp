#include <iostream>

using namespace std;

int greed(int n, int x[]){ 
	int a,b,c,min;
	x[n] =  -1;
	
	if(n == 0){
		return 0;
	}
	if(n < 0){
		return 10000000;
	}

	if(x[n-1] != -1){
		a = greed(n-1,&x[n]);
	}

	if(x[n-3] != -1){
		b = greed(n-3,&x[n]);
	}

	if(x[n-4] != -1){
		c = greed(n-4,&x[n]);
	}

	a = greed(n-1,&x[n]);
	b = greed(n-3,&x[n]);
	c = greed(n-4,&x[n]);

	min = a;
	if(b < min){
		min = b;
	}
	else if(c < min){
		min = c;
	}

	return (1+min);	
}
int main(){
	
	int n;
	int x;
	cin >> n;
	cout << greed(n,&x) << endl;

	return 0;
}
