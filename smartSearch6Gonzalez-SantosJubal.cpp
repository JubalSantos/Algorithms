#include <iostream>
#include <string>

using namespace std;

int found(string pattern, char txt){
	int n, i;
	n = pattern.size();
	//we compare each character and if they match return the index else return -1
	for(i = n - 2; i >= 0; i--){
		if(txt == pattern[i]){
			return i;
		}
	} 
	return -1;
}

int smartSearch(string txt, string pattern){
	int n,m,i,j,last;
	n = txt.size();
	m = pattern.size();
	i = m -1;
	j = i;
	//compare the pattern to the text
	while(i < n){
		//return where the pattern is found in the text
		if(pattern[j] == txt[i]){
			if(j == 0)
			return i;

			else{
				--j; --i;
			}
		}
		//if the pattern doesnt match move m elements over
		else{
			last = found(pattern, txt[i]);
			if(last < 0){
				i += m;
			}
			else{
				i += j - last;
			}
			//reset position
			j = m - 1;
		}
	}
	return -1;
}
int main(){
	
	string txt,pattern;
	int number, i;
	i = 0;
	cin >> number; 
	cin >> pattern;
	while(i < number){
	cin >> txt;
	cout << smartSearch(txt,pattern) << endl;
	i++;
	}
	return 0;
}
