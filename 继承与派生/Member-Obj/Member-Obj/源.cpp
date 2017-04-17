#include<iostream>
using namespace std;
class A{
	int m_nA;
public:
	A(){
		m_nA = 10;
		cout << "A::A" << endl;
	}
	~A(){
		cout << "A::~A" << endl;
    }
};
class B{
	int m_nB;
public:
	B(){
		m_nB = -1;
		cout << "B::B" << endl;
	}
	~B(){
		cout << "B::~B" << endl;
	}
};
class CTest{
	int m_nC;
	B b;	
	A a;
public:
	CTest(){
		m_nC = 20;
		cout << "CTest::CTest" << endl;
	}
	~CTest(){
		cout << "CTest::~CTest" << endl;
	}
};
void main(){
	CTest t;//先按顺序构造A和B对象，再构造自己的成员变量
	cout << "sizeof(A):" << sizeof(A) << endl;
	cout << "sizeof(b):" << sizeof(B) << endl;
	cout << "sizeof(t):" << sizeof(t) << endl;
	system("pause");
}