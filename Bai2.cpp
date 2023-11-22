#include<iostream>
#include<cmath>
#include <fstream>

using namespace std;

class node{
private:
	int bac;
	float heso;
	node *next;
public:
	node(){	// Khoi tao con tro next bang null
		next = nullptr;
	}                                           
	node(float hs,int b,node *n = nullptr){	   // Khoi tao ham tao co doi
		heso=hs; bac=b; next=n;	
	} 
	void set_bac(int b){ 
		this->bac=b;
	}                                    
	void set_heso(float hs){
		heso=hs;
	}                      
	void set_next(node *n=nullptr){
		next=n;	
	}                      
	int get_bac(){
		return bac;		
	} 
	float get_heso(){
		return heso;	
	}
	node *get_next(){
		return next;	
	}
};

class dathuc{
private:
	node *head; 
	node *tail;
	int num;
public:
	dathuc(){
		head=tail=nullptr; num=0;	
	}
	int size(){
		return num;	
	}
	// Sap xep cac phan tu trong da thuc 
	void sort(){
		for(node *p=head; p!=tail; p=p->get_next()){
			for(node *q=p->get_next(); q!=nullptr; q=q->get_next()){
				if(q->get_bac() > p->get_bac()){
					float tmp_hs=p->get_heso();
					int   tmp_b =p->get_bac();
					p->set_heso(q->get_heso());
					p->set_bac(q->get_bac());
					q->set_heso(tmp_hs);
					q->set_bac(tmp_b);
				}
			}
		}
	}
	//Them phan tu dau
	void push_back(float heso, int bac){
		if(heso!=0){
			if(num==0)	head=tail=new node(heso,bac,nullptr);
			else{
				tail->set_next(new node(heso,bac,nullptr));
				tail=tail->get_next();
			}
			num++;
		}else return;
	}
	//Them phan tu cuoi
	void push_front(float heso, int bac){
		if(heso!=0){
			if(num==0)	head=tail=new node(heso,bac,nullptr);
			else{
				node *p=new node(heso,bac,head);
				head->set_next(p);
			}
			num++;
		}else	return;
	}
	//Toan tu nhap
	friend istream& operator >> (istream &cin, dathuc &w){
		cout<<"Nhap so luong phan tu da thuc: ";
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cout<<"Nhap phan tu thu "<<i<<": \n";
			int bac;
			float hs;
			cout<<"Nhap he so: ";cin>>hs;
			cout<<"Nhap bac: ";cin>>bac;
			w.push_back(hs,bac);
		}
		w.sort();
		return cin;
	}
	//Toan tu xuat
	friend ostream& operator << (ostream &cout,dathuc &w){
		if(w.num==0){
			cout<<"0\n";
			return cout;
		}
		node *p=w.head;
		if(p->get_heso() > 0)
			cout<<p->get_heso()<<"x^"<<p->get_bac();
		else if(p->get_heso() < 0)
			cout<<p->get_heso()<<"x^"<<p->get_bac();
		p=p->get_next();
		
		while(p!=nullptr){
			if(p->get_heso() > 0){
				if(p->get_heso()==1){
					cout<<"+";
				}else{
					cout<<"+"<<p->get_heso();
				}
			}				
			else if(p->get_heso()<0){
				if(p->get_heso()==-1){
					cout<<"-";
				}else{
					cout<<p->get_heso();
				}
			}			
			if(p->get_bac()!=0)	cout<<"x^"<<p->get_bac();
			p=p->get_next();
		}cout<<endl;
		return cout;
	}
	
	dathuc operator + (dathuc list2){
		dathuc list1=*this,list3;
		node *p=list1.head;
		node *q=list2.head;
		while(p!=nullptr && q!=nullptr){
			if(p->get_bac()==q->get_bac()){
				list3.push_back(p->get_heso()+q->get_heso(),p->get_bac());
				p=p->get_next();
				q=q->get_next();
			}else if(p->get_bac()>q->get_bac()){
				list3.push_back(q->get_heso(),q->get_bac());
				q=q->get_next();
			}else{
				list3.push_back(p->get_heso(),p->get_bac());
				p=p->get_next();
			}
		}
		while(p!=nullptr){
			list3.push_back(p->get_heso(),p->get_bac());
			p=p->get_next();
		}
		while(q!=nullptr){
			list3.push_back(q->get_heso(),q->get_bac());
			q=q->get_next();
		}
		list3.sort();
		return list3;
	}
	
	void operator += (dathuc list2){
		dathuc list1 = (*this), list3;
		list3 = list1 + list2;
		list1 = list3;
	}
	
	void operator = (dathuc w){
		if(this->size()==0){
			node *p=w.head;
			while(p!=nullptr){
				push_back(p->get_heso(),p->get_bac());
				p=p->get_next();
			}
		}else{
			dathuc list1=(*this);
			if(size()>w.size()){
				int n=size()-w.size();
				node *p=w.head;
				node *q=list1.head;
				while(p!=nullptr){
					q->set_bac(p->get_bac());
					q->set_heso(p->get_heso());
					p=p->get_next();q=q->get_next();
				}
				while(n!=0){
					pop_back();
					n--;
				}
			}else if(size()<w.size()){
				node *p=w.head;
				node *q=list1.head;
				while(q!=nullptr){
					q->set_bac(p->get_bac());
					q->set_heso(p->get_heso());
					p=p->get_next();q=q->get_next();
				}
				while(p!=nullptr){
					push_back(p->get_heso(),p->get_bac());
					p=p->get_next();
				}
			}else{
				node *p=w.head;
				node *q=list1.head;
				while(q!=nullptr&p!=nullptr){
					q->set_bac(p->get_bac());
					q->set_heso(p->get_heso());
					p=p->get_next();q=q->get_next();
				}
			}
		}
	}
	
	void doi_dau(){
		node *p=head;
		while(p!=nullptr){
			p->set_heso(p->get_heso()*(-1));
			p=p->get_next();
		}
	}
	dathuc operator - (dathuc list2){
		dathuc list1=*this,list3;
		list2.doi_dau();
		list3=list1 + list2;
		return list3;
	}
	dathuc operator*(node *tmp){
		dathuc list;
		node *p=head;
		while(p!=nullptr){
			list.push_back(p->get_heso() * tmp->get_heso(), p->get_bac() + tmp->get_bac());
			p=p->get_next();
		}
		return list;
	}	
	dathuc operator*(dathuc list2){
		dathuc list1 = (*this), list3, list;
		node *p = list1.head;
		list = list2 * p;
		p = p->get_next();
		while(p!=nullptr){
			list += list2 * p;
			p = p->get_next();
		}
		return list;
	}
	
	void pop_back(){
		if(num==0)	return;
		if(num==1){
			head=tail=nullptr;num--;	
		}
		else{
			node *p=head;
			while(p->get_next()!=tail)	p=p->get_next();
			node *q=p->get_next();
			p->set_next(nullptr);
			tail=p;
			delete q;
			num--;
		}
	}
	
	void pop_front(){
		if(num==0)	return;
		if(num==1){
			head=tail=nullptr;num--;	
		}
		else{
			head=head->get_next();
			num--;
		}
	}
	void erase(int index){
		if(num==0||index>num||index<1)	return;
		if(index==1){
			pop_front();
			return;
		}else if(index==num){
			pop_back();return;
		}
		else{
			node *p=head;
			int i=1;
			while(p!=tail){
				if(i==index-1){
					node *q=p->get_next();
					p->set_next(p->get_next()->get_next());
					delete q;
				}
				i++;
				p=p->get_next();
			}
			num--;
		}
	}
	
	float operator!(){
		float x;
		cout<<"x = ";
		cin>>x;
		float t=0;
		node *p=head;
		while(p!=nullptr){
			t+=p->get_heso()*pow(x,p->get_bac());
			p=p->get_next();
		}
		return t;
	}
};

int main(){
	dathuc a,b;
	cin>>a>>b;
	cout<<"P(x) = "<<a;
	cout<<"Q(x) = "<<b;
	dathuc tong = a+b;
	cout<<"Tong hai da thuc la: " << tong;
	dathuc hieu = a-b;
	cout<<"Hieu hai da thuc la: "<< hieu;
	dathuc tich=a*b;
	cout<<"Tich hai da thuc la: "<< tich;  
	ofstream outfile("ketqua.txt");
	outfile << "Tong hai da thuc la: " << tong << endl;
	outfile << "Hieu hai da thuc la: "<< hieu << endl;
	outfile << "Tich hai da thuc la: "<< tich;
 	outfile.close();
 	cout<<!a;

	return 0;
}
