#include <iostream>
#include <string>
using namespace std;

// Hàm F đơn giản dùng phép XOR thay vì phép trừ
char F(char R, char Ki) {
    return R ^ Ki; // XOR
}

// Hàm quay phải ký tự k đi n bit
char rotateRight(char k, int n) {
    return (k >> n) | (k << (8 - n)); // Quay phải n lần
}

// Mã hóa một khối gồm 2 ký tự P0, P1 với khóa k
string MHKhoi(char P0, char P1, char k) {
    char K[8], L[8], R[8];
    string C = "  "; // 2 ký tự

    // Khởi tạo
    R[0] = P0;
    L[0] = P1;
    K[0] = k;

    // Tạo 7 khóa con và thực hiện 7 vòng Feistel
    for (int i = 1; i <= 7; i++) {
        K[i] = rotateRight(K[0], i); // Quay phải i lần tạo khóa con
        R[i] = L[i - 1] ^ F(R[i - 1], K[i]); // R mới
        L[i] = R[i - 1]; // L mới
    }

    // Kết quả sau 7 vòng: L7 và R7 là ciphertext
    C[0] = L[7];
    C[1] = R[7];
    return C;
}

// Giải mã một khối gồm 2 ký tự C0, C1 với khóa k
string GiaiMaKhoi(char C0, char C1, char k) {
    char K[8], L[8], R[8];
    string P = "  "; // plaintext 2 ký tự

    // Gán lại giá trị L7, R7 từ ciphertext
    L[7] = C0;
    R[7] = C1;
    K[0] = k;

    // Tạo khóa con
    for (int i = 1; i <= 7; i++) {
        K[i] = rotateRight(K[0], i);
    }

    // Giải mã ngược từ vòng 7 → 1
    for (int i = 7; i >= 1; i--) {
        R[i - 1] = L[i]; // R trước = L sau
        L[i - 1] = R[i] ^ F(R[i - 1], K[i]); // L trước
    }

    // Kết quả ban đầu
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

    // Nếu độ dài lẻ → thêm 'X'
    if (P.size() % 2 == 1) P += 'X';

    // Mã hóa từng cặp ký tự
    for (int i = 0; i < P.size(); i += 2) {
        C += MHKhoi(P[i], P[i + 1], k);
    }

    cout << "Chuoi ma hoa: " << C << endl;

    // Giải mã từng cặp ký tự
    for (int i = 0; i < C.size(); i += 2) {
        decryptedP += GiaiMaKhoi(C[i], C[i + 1], k);
    }

    // Xoá ký tự 'X' nếu có (dùng để đệm)
    if (!decryptedP.empty() && decryptedP[decryptedP.size() - 1] == 'X') {
        decryptedP.erase(decryptedP.size() - 1);
    }

    cout << "Chuoi giai ma: " << decryptedP << endl;

    return 0;
}
