#include <iostream>

using namespace std;

class Stack {
private:
    int data[10000]; // Mang du lieu
    int top;             // Chi so dinh tren cung ( = so phan tu cua Stack )

public:
    Stack() {
        top=-1; // Khoi tao ngan xep l� rong
    }
	//Ham them
    void push(int n) {
        if (top==10000 - 1) { // Kiem tra xem ngan xep da day chua
            cout << "FULL!" << endl;
        } else {
            top++; // Tang ch? s? tr�n c�ng
            data[top] = n; // Th�m ph?n t? v�o ngan x?p
        }
    }
	//ham lay phan tu
    void pop() {
        if (top == -1) { // Kiem tra xem ngan xep da rong chua
            cout << "EMPTY" << endl;
        } else {
            top--; // Giam chi so tr�n c�ng
        }
    }
	//Kiem tra rong
    void empty() {
        if (top == -1) {
            cout << "EMPTY!" << endl;
        } else {
            cout << data[top] << endl; // In phan tu tr�n c�ng
        }
    }
	//Thuat toan bai ()((()))
    void Find(string& k) {
        int n = k.length();
        for (int i = 0; i < n; i++) {
            if (k[i] == '(') { // Mo ngoac
                push(i + 1); // Th�m chi so v�o ngan xep
            } else if (k[i] == ')') { // Dong ngoac
                if (top >= 0) { // Kiem tra xem ngan xep kh�ng rong
                    cout << data[top] << " " << i + 1 << endl; // In ra
                    pop(); // Xoa ngoac mo khop
                }
            }
        }
    }
};

int main() {
    Stack stack;
    string k;

    cin >> k;

    stack.Find(k);

    return 0;
}
