#include<bits/stdc++.h>
using namespace std;
int main(){
    string P, C, K;
    cout << "Nhap plaintext: ";
    getline(cin, P);
    cout << "Nhap chuoi K: ";
    getline(cin, K);
    //ma hoa
    while((P.size()*16) % 16 != 0){
        P += "X";
    }
    for(int i = 0; i<P.size(); i++){
        C += P[i] ^ K[i % K.size()];
    }
   cout << "Ciphertext (hex): ";
    for (unsigned char ch : C) {
        printf("%02X ", ch);
    }
    cout << endl;
    // giai ma
    P = "";
    for(int i = 0; i<C.size(); i++){
        P += C[i] ^ K[i % K.size()];
    }
    cout << "Plaintext: " << P << endl;
}