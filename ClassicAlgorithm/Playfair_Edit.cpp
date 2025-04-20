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
			bang[i][j] = kq[k++];
		}
	}
	cout << "kq = " << kq << endl;
}

string xulychuoi(string plaintext){
	// dua ve in hoa, chuyen J thanh I. Neu 2 ky tu lien ke giong nhau thi chen X vao giua. Chen X vao cuoi chuoi
	string p = "";
	for(char c : plaintext) {
		if(isalpha(c)){
			c = toupper(c);
			if(c == 'J') c = 'I';
			p += c;
		}
	}
	string kq = "";
	for(int i=0; i<p.length(); i++){
		char a = p[i];
		char b = (i == p.length() - 1) ? 'X' : p[i+1];
		if(a == b) b = 'X';
		else i++; //duyet tung cap 1 nen phai cho i++ de bo qua b dang xet o vong lap hien tai
		kq += a;
		kq += b;
	}
	
	return kq; //output co dang chuoan cua Playflair
}

void tim(char a, int &x, int &y){
	if(a == 'J') a = 'I';
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			if(bang[i][j] == a){
				x = i;
				y = j;
				return;
			}
		}
	}
}

string mahoa(string plaintext){
	plaintext = xulychuoi(plaintext);
	string kq = "";
	for(int i=0; i<plaintext.length(); i+=2){
		char a = plaintext[i];
		char b = plaintext[i+1];
		int ax, ay, bx, by;
		tim(a, ax, ay);
		tim(b, bx, by);
		if(ax == bx){
			kq += bang[ax][(ay + 1) % 5];
			kq += bang[bx][(by + 1) % 5];
		}else if(ay == by){
			kq += bang[(ax + 1) % 5][ay];
			kq += bang[(bx + 1) % 5][by];
		}else{
			kq += bang[ax][by];
			kq += bang[bx][ay];
		}
	}
	return kq;
}

string giaima(string kqmahoa){
	string kq = "";
	for(int i=0; i<kqmahoa.length(); i+=2){
		char a = kqmahoa[i];
		char b = kqmahoa[i+1];
		int ax, ay, bx, by;
		tim(a, ax, ay);
		tim(b, bx, by);
		if(ax == bx){
			kq += bang[ax][(ay - 1 + 5) % 5]; //-1 + 5 de quay vong
			kq += bang[bx][(by - 1 + 5) % 5];
		}else if(ay == by){
			kq += bang[(ax - 1 + 5) % 5][ay];
			kq += bang[(bx - 1 + 5) % 5][by];
		}else{
			kq += bang[ax][by];
			kq += bang[bx][ay];
		}
	}
	return kq;
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
	
	cout << endl << "Ket qua chuoi ban dau: " << giaima(kqmahoa);
}
