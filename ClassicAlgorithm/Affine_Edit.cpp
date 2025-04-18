#include<bits/stdc++.h>

using namespace std;

string mahoa(string P, int a, int b){
	string C = "";
	for(char s : P){
		if(isalpha(s)){
			char base = isupper(s) ? 'A' : 'a';
			C += ((s - base) * a + b) % 26 + base;
		}else{
			C += s;
		}
	}
	return C;
}

int finda(int a){
	for(int i=1; i<26; i++){
		if((a*i) % 26 == 1) return i;
	}
	return -1;
}

void giaima(string mahoakq, int a, int b){
	if(finda(a) == -1) return;
	string C = "";
	for(char s : mahoakq){
		if(isalpha(s)){
			char base = isupper(s) ? 'A' : 'a';
			C += ((s-base) - b + 26)*finda(a) % 26 + base;
		}else{
			C += s;
		}
	}
	cout << "Ket qua giai ma: " << C;
}

int main(){
	string P;
	int a, b;
	cout << "Nhap chuoi Plaintext: ";
	getline(cin, P);
	cout << endl << "Nhap khoa a = ";
	cin >> a;
	cout << endl << "Nhap khoa b = ";
	cin >> b;
	
	string mahoakq = mahoa(P, a, b);
	cout << endl << "Chuoi ma hoa: " << mahoakq;
	cout << endl << "Pha khoa:" << endl;
	giaima(mahoakq, a, b);
}
