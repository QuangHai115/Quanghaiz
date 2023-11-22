#include"iostream"

using namespace std;
template<class T>

class Node{
	private:
		T data;
		Node* next;
	public:
		Node(){
			next=nullptr;
		}
		Node(T data){
			this->data=data;
			next=nullptr;
		}
		Node(T data, Node *n){
			this->data=data;this->next=n;
		}
		T get_data(){
			return data;
		}
		void set_data(T data){
			this->data=data;
		}
		Node *get_next(){
			return next;
		}
		void set_next(Node* next){
			this->next=next;
		}
		
};
template<class T> //Ham mau
class Stack {
	private:
		int size;
		Node<T>* head, *tail;
	public:
		Stack(){
			head=NULL;
			size=0;
		}
		//Tham phan tu
		void push(T data){
			if(size==0){
					tail=head=new Node<T>();
					tail->set_data(data);
					head->set_data(data);
			}
			
			else{
				tail->set_next(new Node<T>(data,nullptr));
				tail=tail->get_next();
			}
			size++;
		}
		//Lay phan tu
		T pop()			
		{
			if(size > 1){
				Node<T> *p=head;
				while(p->get_next() != tail ){
					p = p->get_next();
				}	
				Node<T> *q=tail;
				T cmp=q->get_data();
				tail=p;
				tail->set_next(nullptr);
//				delete q;
				size--;
				return cmp;
			}	
			else if(size==1){
				return head->get_data();
			}
		}
		//Phan tu o cuoi
		T back(){
			return tail->get_data();
		}
		int get_size(){
			return size;
		}
		//kiem tra rong
		bool Empty(){
			return size==0;
		}
		
			
};
main(){
	Stack < string > stack; 
	int n;
	cin>>n;	
	for(int i=0; i < n; i++ ){
		string x;
		cin >> x;
		stack.push(x);
	}
	if(stack.Empty()==1) cout<<"Empty !";
	else stack.pop();
	cout<< stack.get_size( );
	cout<<endl;
	cout<<"Day sau khi da loai phan tu dau tien: ";
	for(int i=1; i <= n-1; i++ ){	
		cout<<stack.pop();               
	}
	cout<<"\nPhan tu dau tien: "<<stack.back();


	return 0;
}

	 

