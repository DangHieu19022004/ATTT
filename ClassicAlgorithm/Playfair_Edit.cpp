#include<bits/stdc++.h>

using namespace std;

char bang[5][5];

void taobang(string key){
	//loai trung
	string kq = "";
	bool ba[26] = {false};
	ba['J' - 'A'] = true;
	for(char s : key){
		char c = toupper(s);
		if(c == 'J') c = 'I';
		if(!ba[c - 'A']){
			kq += c;
			ba[c - 'A'] = true;
		}
	}
	//them vao bang khoa
	for(char c = 'A'; c <= 'Z'; c++){
		if(c != 'J' && kq.find(c) == -1){
			kq += c;
		}
	}
	int k=0;
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			bang[5][5] = kq[k++];
		}
	}
}

string xulychuoi(string plaintext){
	string p = "";
	for(char c : plaintext) {
		if(isalpha(c)){
			char c = toupper(c);
			if(c == 'J') c = 'I';
			p += c;
		}
	}
	string kq = "";
	
}

string mahoa(string plaintext){
	plaintext = xulychuoi(plaintext);
}

int main(){
	string key, plaintext;
	cout << "Nhap key: ";
	getline(cin, key);
	cout << "Nhap plaintext: " ;
	getline(cin, plaintext);
	
	taobang(key);
	string kqmahoa = mahoa(plaintext);
	cout << "Ket qua ma hoa: " << kqmahoa;
}
