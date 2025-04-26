#include<bits/stdc++.h>

using namespace std;

string mahoa(string plain, int a, int b){
	string kq = "";
	for(char c : plain){
		kq += ((c - 'A') * a + b) % 26 + 'A';
	}
	return kq;
}

int main(){
	int a, b;
	string plain;
	cout << "plain: ";
	getline(cin, plain);
	cout << "a: "; cin >> a;
	cout << "b: "; cin >> b;
	cout << "ma hoa: " << mahoa(plain, a, b);
}
