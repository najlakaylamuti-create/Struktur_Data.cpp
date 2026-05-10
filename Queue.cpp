#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        // Rotasi: elemen baru jadi paling depan
        for (int i = 0; i < (int)q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int t = q.front();
        q.pop();
        return t;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack st;

    cout << "=== Implement Stack using Queue ===" << endl;
    cout << endl;

    st.push(1);
    cout << "push(1) -> top: " << st.top() << endl;

    st.push(2);
    cout << "push(2) -> top: " << st.top() << endl;

    st.push(3);
    cout << "push(3) -> top: " << st.top() << endl;

    cout << endl;
    cout << "pop()   -> keluar: " << st.pop() << endl;
    cout << "top()   -> sekarang: " << st.top() << endl;

    cout << "pop()   -> keluar: " << st.pop() << endl;
    cout << "top()   -> sekarang: " << st.top() << endl;

    cout << "pop()   -> keluar: " << st.pop() << endl;
    cout << "empty() -> " << (st.empty() ? "true (stack kosong)" : "false") << endl;

    return 0;
}