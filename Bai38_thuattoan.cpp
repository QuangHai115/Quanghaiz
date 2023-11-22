#include <iostream>

using namespace std;

class Stack {
private:
    int data[10000]; 
    int top;             /

public:
    Stack() {
        top=-1; 
    }
	//Ham them
    void push(int n) {
        if (top==10000 - 1) { 
            cout << "FULL!" << endl;
        } else {
            top++; 
            data[top] = n; 
        }
    }
	//ham lay phan tu
    void pop() {
        if (top == -1) { 
            cout << "EMPTY" << endl;
        } else {
            top--; 
        }
    }
	//Kiem tra rong
    void empty() {
        if (top == -1) {
            cout << "EMPTY!" << endl;
        } else {
            cout << data[top] << endl; 
        }
    }
	//Thuat toan bai ()((()))
    void Find(string& k) {
        int n = k.length();
        for (int i = 0; i < n; i++) {
            if (k[i] == '(') { 
                push(i + 1); 
            } else if (k[i] == ')') { 
                if (top >= 0) { 
                    cout << data[top] << " " << i + 1 << endl; 
                    pop(); 
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
