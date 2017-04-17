#include<iostream>
using namespace std;

class CComplex
{
	int m_Real;
	int m_Imag;
public:
	CComplex(int r, int i){
		m_Real = r;
		m_Imag = i;
	}
	CComplex() { }
	~CComplex(){ }
	void Print(){
		cout<<m_Real << ',' << m_Imag << endl;
	}
	CComplex operator + (CComplex & c1);
	CComplex operator - (CComplex & c1);
	CComplex & operator ++ ();//++c
	CComplex  operator ++ (int);//c++
	CComplex & operator += (CComplex & c1);
	CComplex  operator - ();
	CComplex  operator ! ();
};

CComplex CComplex::operator + (CComplex & c1){
	CComplex c;  //临时变量，不能返回其引用
	c.m_Real = c1.m_Real + this->m_Real;
	c.m_Imag = c1.m_Imag + this->m_Imag;
	return c;
}

CComplex CComplex::operator - (CComplex & c1){//减数和被减数有歧义，根据需求来
	CComplex c;  //临时变量，不能返回其引用
	c.m_Real = c1.m_Real - this->m_Real;
	c.m_Imag = c1.m_Imag - this->m_Imag;
	return c;
}

CComplex & CComplex::operator ++ (){  //++c
	this->m_Real++;
	this->m_Imag++;
	return *this;
}

CComplex  CComplex::operator ++ (int){  //c++
	CComplex c1 = *this;
	this->m_Real++;
	this->m_Imag++;
	return c1;
}

CComplex &  CComplex::operator += (CComplex & c1){
	this->m_Real += c1.m_Real;
	this->m_Imag += c1.m_Imag;
	return *this;
}

CComplex  CComplex::operator - (){
	CComplex c1 = *this;
	c1.m_Real *= -1;
	c1.m_Imag *= -1;
	return c1;
}

CComplex  CComplex::operator ! (){
	CComplex c1 = *this;
	c1.m_Real = !c1.m_Real;
	c1.m_Imag = !c1.m_Imag;
	return c1;
}

int main(){
	CComplex c1(1, 2), c2(2, 6);
	CComplex c3 = c1 + c2;// operator+(c1, c2);
	c3.Print();
	CComplex c4 = c2 - c1;
	c4.Print();
	CComplex c5 = ++c1; //c1(2,3)
	c5.Print();
	CComplex c6 = c1++;//c1(3,4)
	c6.Print();
	CComplex c7= c1+=c2;//c1(５，１０）
	c7.Print();
	CComplex c8 = -c1;
	c8.Print();
	CComplex c9 = !c1;
	c9.Print();
	system("pause");
	return 0;
}