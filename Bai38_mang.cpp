#include <iostream>

using namespace std;

class Stack {
private:
    int data[10000]; // Mang du lieu
    int top;             // Chi so dinh tren cung ( = so phan tu cua Stack )

public:
    Stack() {
        top = 0; // Khoi tao ngan xep là rong
    }

    void push(int n) {
        if (top == 10000 ) { // Kiem tra xem ngan xep da day chua
            cout << "FULL!" << endl;
        } else {
            top++; // Tang ch? s? trên cùng
            data[top] = n; // Thêm ph?n t? vào ngan x?p
        }
    }

    void pop() {
        if (top == 0) { // Kiem tra xem ngan xep da rong chua
            cout << "EMPTY" << endl;
        } else {
            top--; // Giam chi so trên cùng
        }
    }

    void empty() {
        if (top == 0) {
            cout << "EMPTY!" << endl;
        } else {
            cout << data[top] << endl; // In phan tu trên cùng
        }
    }
    void front(){
    	if (top == 0){
    		cout<<"EMPTY !";
		}
		else
		cout<< data[1];
	}
	 void back(){
    	if (top == 0){
    		cout<<"EMPTY !";
		}
		else
		cout<< data[top];
	}
    

};

int main() {
    Stack stack;
    int n;
	cin>>n;	
    for(int i=1; i<=n; i++){
    	int k;
    	cin >> k;
    	stack.push(k);
	}
	cout<<"Phan tu dau tien la: ";
//	stack.pop();

    stack.back();

    return 0;
}

