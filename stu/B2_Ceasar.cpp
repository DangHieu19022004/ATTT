 #include<bits/stdc++.h>
 
 using namespace std;
 
 string mahoa(string plain, int k){
 	string kq = "";
 	for(char c : plain){
 		kq += (c - 'A' + k) % 26 + 'A';
	}
	return kq;
 }
 
 string giaima(string kqmh, int k){
 	string kq = "";
 	for(char c : kqmh){
 		kq += (c - 'A' - k + 26) % 26 + 'A';
	 }
	 return kq;
 }
 
 void phakhoa(string kqmh, string plain){
 	for(int k = 0; k<26; k++){
 		string kq = "";
 		for(char c : kqmh){
 			kq += (c - 'A' - k + 26) % 26 + 'A';
		 }
		 if(kq == plain){
		 	cout << endl << "Ma hoa thanh cong: " << "k = " << k << " plain: " << kq;
		 }else{
		 	cout << endl << "k = " << k << "KQMH: " << kq; 
		 }
		 
	 }
 }
 
 int main(){
 	string plain;
 	int k;
 	cout << "Nhap plain: ";
 	getline(cin, plain);
 	cout << "Nhap k: ";
 	cin >> k;
 	cout << "ma hoa: " << mahoa(plain, k);
 	cout << endl << "giai ma: " << giaima(mahoa(plain, k), k);
 	cout << endl;
 	phakhoa(mahoa(plain, k), plain);
 }
