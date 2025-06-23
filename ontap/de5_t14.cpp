#include <iostream>
#include <string>
using namespace std;

char F(char R, char Ki) {
    return R - Ki;
}

char rotateRight(char ch, int i) {
    return (char)((ch >> i) | (ch << (8 - i)));
}

string MHKhoi(char P0, char P1, char k) {
    char K[6], L[6], R[6];
    string C = "  ";  // Độ dài 2 ký tự

    R[0] = P0;
    L[0] = P1;
    K[0] = k;

    for (int i = 1; i <= 5; i++) {
        K[i] = rotateRight(K[0], i);        // Quay phải i lần
        R[i] = L[i - 1] ^ F(R[i - 1], K[i]); // Feistel function
        L[i] = R[i - 1];
    }

    C[0] = L[5];
    C[1] = R[5];
    return C;
}

string GiaiMaKhoi(char C0, char C1, char k) {
    char K[6], L[6], R[6];
    string P = "  ";

    L[5] = C0;
    R[5] = C1;
    K[0] = k;

    for (int i = 1; i <= 5; i++) {
        K[i] = rotateRight(K[0], i);  // Quay phải i lần
    }

    for (int i = 5; i >= 1; i--) {
        R[i - 1] = L[i];
        L[i - 1] = R[i] ^ F(R[i - 1], K[i]);
    }

    P[0] = R[0];
    P[1] = L[0];
    return P;
}

int main() {
    string P, C, decryptedP;
    char k;

    cout << "Nhap chuoi plaintext: ";
    getline(cin, P);
    cout << "Nhap khoa K: ";
    cin >> k;

    if (P.size() % 2 == 1) P += 'X';  // Thêm 'X' nếu độ dài lẻ

    for (int i = 0; i < P.size(); i += 2) {
        C += MHKhoi(P[i], P[i + 1], k);
    }

    cout << "Chuoi ma hoa: " << C << endl;

    for (int i = 0; i < C.size(); i += 2) {
        decryptedP += GiaiMaKhoi(C[i], C[i + 1], k);
    }

    if (!decryptedP.empty() && decryptedP[decryptedP.size() - 1] == 'X') {
        decryptedP.erase(decryptedP.size() - 1); // Bỏ 'X' cuối nếu có
    }

    cout << "Chuoi giai ma: " << decryptedP << endl;

    return 0;
}
