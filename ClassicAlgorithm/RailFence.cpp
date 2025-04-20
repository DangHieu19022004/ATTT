#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Ham ma hoa Rail Fence
string mahoa(string text, int rails) {
    if (rails <= 1) return text;

    vector<string> rail(rails);
    int dir = 1;  // 1: xuong, -1: lên
    int row = 0;

    for (char c : text) {
        rail[row] += c;
        row += dir;

        if (row == 0 || row == rails - 1)
            dir *= -1;
    }

    string kq = "";
    for (string r : rail)
        kq += r;
    return kq;
}

// Ham giai ma Rail Fence
string giaima(string cipher, int rails) {
    if (rails <= 1) return cipher;

    vector<vector<bool>> mark(rails, vector<bool>(cipher.length(), false));

    // Danh dau vi tri zigzag
    int row = 0, dir = 1;
    for (int i = 0; i < cipher.length(); i++) {
        mark[row][i] = true;
        row += dir;
        if (row == 0 || row == rails - 1)
            dir *= -1;
    }

    // Gán ky tu vào vi tri da danh dau
    vector<string> rail(rails);
    int idx = 0;
    for (int r = 0; r < rails; r++) {
        for (int c = 0; c < cipher.length(); c++) {
            if (mark[r][c] && idx < cipher.length()) {
                rail[r] += cipher[idx++];
            }
        }
    }

    // Ðoc theo zic-zac
    string kq = "";
    row = 0; dir = 1;
    vector<int> pos(rails, 0);
    for (int i = 0; i < cipher.length(); i++) {
        kq += rail[row][pos[row]++];
        row += dir;
        if (row == 0 || row == rails - 1)
            dir *= -1;
    }

    return kq;
}
int main() {
    string text;
    int rails;

    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, text);

    cout << "Nhap so hang (rails): ";
    cin >> rails;

    string c = mahoa(text, rails);
    cout << "Chuoi ma hoa: " << c << endl;

    string g = giaima(c, rails);
    cout << "Giai ma lai: " << g << endl;

    return 0;
}

