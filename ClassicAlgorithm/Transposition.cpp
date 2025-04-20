#include <iostream>
#include <string>
using namespace std;

// Ham ma hoa hoan vi theo so cot
string mahoa(string plain, int cols) {
    string kq = "";
    // Them 'X' vao cuoi cho du
    while (plain.length() % cols != 0)
        plain += 'X';

    int rows = plain.length() / cols;

    // Doc theo cot
    for (int c = 0; c < cols; c++) {
        for (int r = 0; r < rows; r++) {
            kq += plain[r * cols + c];
        }
    }

    return kq;
}

// Ham giai ma hoan vi
string giaima(string cipher, int cols) {
    string kq = "";
    int rows = cipher.length() / cols;

    // Ð?c l?i theo hàng (ngu?c v?i mã hóa)
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            kq += cipher[c * rows + r];
        }
    }

    return kq;
}

int main() {
    string plain;
    int cols;

    cout << "Nhap chuoi plaintext (chi chu cai): ";
    getline(cin, plain);

    cout << "Nhap so cot (key): ";
    cin >> cols;

    string c = mahoa(plain, cols);
    cout << "Ma hoa: " << c << endl;

    string g = giaima(c, cols);
    cout << "Giai ma: " << g << endl;

    return 0;
}

