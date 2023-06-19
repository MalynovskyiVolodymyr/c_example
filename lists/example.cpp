#include <iostream>
#include <stack>
#include <cstring>
#include <string>
using namespace std;

void Reverse(char* C, int n){
	stack<char> S;
	
	for(int i = 0; i < n; i++){
		S.push(C[i]);
	}

	for(int i = 0; i < n; i++){
		C[i] = S.top();	
		S.pop();
	}
}

int main(){
	string C = "";
	cout << "Enter a string: ";
	getline(cin, C);
	
	//Reverse(C, strlen(C));
	cout << endl << "Output = " << C << endl;
}
