#include <iostream>
using namespace std;

char bang[5][5];

string loaiTrung(string s) {
    bool da[26] = {false};
    da['J' - 'A'] = true;
    string kq = "";
    for (char c : s) {
        c = toupper(c);
        if (c == 'J') c = 'I';
        if (!da[c - 'A']) {
            kq += c;
            da[c - 'A'] = true;
        }
    }
    return kq;
}

void taoBang(string khoa) {
    string full = loaiTrung(khoa);
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c != 'J' && full.find(c) == -1)
            full += c;
    }
    int k = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            bang[i][j] = full[k++];
}

void tim(char c, int &x, int &y) {
    if (c == 'J') c = 'I';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (bang[i][j] == c) {
                x = i; y = j;
                return;
            }
}

string xuLyChuoi(string s) {
    string p = "";
    for (char c : s) {
        if (isalpha(c)) {
            c = toupper(c);
            if (c == 'J') c = 'I';
            p += c;
        }
    }
    string kq = "";
    for (int i = 0; i < p.length(); i++) {
        char a = p[i];
        char b = (i + 1 < p.length()) ? p[i + 1] : 'X';
        if (a == b) b = 'X';
        else i++;
        kq += a;
        kq += b;
    }
    return kq;
}

string mahoa(string s) {
    s = xuLyChuoi(s);
    string kq = "";
    for (int i = 0; i < s.length(); i += 2) {
        char a = s[i], b = s[i + 1];
        int ax, ay, bx, by;
        tim(a, ax, ay); tim(b, bx, by);
        if (ax == bx) {
            kq += bang[ax][(ay + 1) % 5];
            kq += bang[bx][(by + 1) % 5];
        } else if (ay == by) {
            kq += bang[(ax + 1) % 5][ay];
            kq += bang[(bx + 1) % 5][by];
        } else {
            kq += bang[ax][by];
            kq += bang[bx][ay];
        }
    }
    return kq;
}

string giaima(string s) {
    string kq = "";
    for (int i = 0; i < s.length(); i += 2) {
        char a = s[i], b = s[i + 1];
        int ax, ay, bx, by;
        tim(a, ax, ay); tim(b, bx, by);
        if (ax == bx) {
            kq += bang[ax][(ay + 4) % 5];
            kq += bang[bx][(by + 4) % 5];
        } else if (ay == by) {
            kq += bang[(ax + 4) % 5][ay];
            kq += bang[(bx + 4) % 5][by];
        } else {
            kq += bang[ax][by];
            kq += bang[bx][ay];
        }
    }
    return kq;
}

int main() {
    string khoa, plain;
    cout << "Nhap tu khoa: ";
    cin >> khoa;
    cin.ignore();
    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, plain);

    taoBang(khoa);

    string c = mahoa(plain);
    cout << "Ma hoa: " << c << endl;

    string goc = giaima(c);
    cout << "Giai ma: " << goc << endl;

    return 0;
}

