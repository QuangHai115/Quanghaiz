#include <iostream>

using namespace std;

class Stack {
private:
    int data[10000]; // Mang du lieu
    int top;             // Chi so dinh tren cung ( = so phan tu cua Stack )

public:
    Stack() {
        top=-1; // Khoi tao ngan xep là rong
    }
	//Ham them
    void push(int n) {
        if (top==10000 - 1) { // Kiem tra xem ngan xep da day chua
            cout << "FULL!" << endl;
        } else {
            top++; // Tang ch? s? trên cùng
            data[top] = n; // Thêm ph?n t? vào ngan x?p
        }
    }
	//ham lay phan tu
    void pop() {
        if (top == -1) { // Kiem tra xem ngan xep da rong chua
            cout << "EMPTY" << endl;
        } else {
            top--; // Giam chi so trên cùng
        }
    }
	//Kiem tra rong
    void empty() {
        if (top == -1) {
            cout << "EMPTY!" << endl;
        } else {
            cout << data[top] << endl; // In phan tu trên cùng
        }
    }
	//Thuat toan bai ()((()))
    void Find(string& k) {
        int n = k.length();
        for (int i = 0; i < n; i++) {
            if (k[i] == '(') { // Mo ngoac
                push(i + 1); // Thêm chi so vào ngan xep
            } else if (k[i] == ')') { // Dong ngoac
                if (top >= 0) { // Kiem tra xem ngan xep không rong
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
