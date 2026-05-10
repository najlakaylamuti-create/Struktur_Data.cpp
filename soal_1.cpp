#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char c : s) {
        // Jika kurung buka, push ke stack
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        // Jika kurung tutup
        else {
            // Stack kosong = tidak ada pasangan
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            // Cek apakah cocok dengan pasangannya
            if (c == ')' && top != '(') return false;
            if (c == '}' && top != '{') return false;
            if (c == ']' && top != '[') return false;
        }
    }

    // Valid jika stack kosong
    return st.empty();
}

int main() {
    // Test cases
    string tests[] = {"()", "()[]{}", "(]", "([)]", "{[]}", "", "{"};
    bool expected[] = {true, true, false, false, true, true, false};
    int n = 7;

    cout << "===== Validasi Bracket =====" << endl;
    cout << endl;

    for (int i = 0; i < n; i++) {
        bool result = isValid(tests[i]);
        string status = (result == expected[i]) ? "PASS" : "FAIL";
        string resultStr = result ? "Valid" : "Tidak Valid";
        string input = tests[i].empty() ? "(kosong)" : "\"" + tests[i] + "\"";

        cout << "[" << status << "] Input: " << input
             << " => " << resultStr << endl;
    }

    cout << endl;

    // Input dari user
    cout << "===== Coba Input Sendiri =====" << endl;
    cout << "Masukkan string bracket: ";
    string input;
    cin >> input;

    if (isValid(input)) {
        cout << "Hasil: VALID" << endl;
    } else {
        cout << "Hasil: TIDAK VALID" << endl;
    }

    return 0;
}