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
	friend CComplex operator + (const CComplex & c1, const CComplex & c2);
	friend CComplex operator - (const CComplex & c1, const CComplex & c2);
	friend CComplex & operator ++ (CComplex & c);//++c
	friend CComplex  operator ++ (CComplex & c, int);//c++
	friend CComplex & operator += (CComplex & c1, const CComplex & c2);
	friend CComplex  operator - (const CComplex & c);
	friend CComplex  operator ! (const CComplex & c);
	friend bool operator == (const CComplex & c1, const CComplex & c2);
};

CComplex operator + (const CComplex & c1, const CComplex & c2){
	CComplex c;  //临时变量，不能返回其引用
	c.m_Real = c1.m_Real + c2.m_Real;
	c.m_Imag = c1.m_Imag + c2.m_Imag;
	return c;
}

CComplex operator - (const CComplex & c1, const CComplex & c2){
	CComplex c;  //临时变量，不能返回其引用
	c.m_Real = c1.m_Real - c2.m_Real;
	c.m_Imag = c1.m_Imag - c2.m_Imag;
	return c;
}

CComplex & operator ++ (CComplex & c){  //++c
	c.m_Real++;
	c.m_Imag++;
	return c;
}

CComplex  operator ++ (CComplex & c,int){  //c++
	CComplex c1 = c;
	c.m_Real++;
	c.m_Imag++;
	return c1;
}

CComplex &  operator += (CComplex & c1, const CComplex & c2){
	c1.m_Real += c2.m_Real;
	c1.m_Imag += c2.m_Imag;
	return c1;
}

CComplex  operator - (const CComplex & c){
	CComplex c1 = c;
	c1.m_Real *= -1;
	c1.m_Imag *= -1;
	return c1;
}

CComplex  operator ! (const CComplex & c){
	CComplex c1 = c;
	c1.m_Real = !c1.m_Real;
	c1.m_Imag = !c1.m_Imag;
	return c1;
}

bool operator == (const CComplex & c1, const CComplex & c2){
	return c1.m_Real == c2.m_Real && c1.m_Imag == c2.m_Imag;
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
	CComplex c7= c1+=c2;//c1(5,10）
	c7.Print();
	if (c7 == c1)
		cout << "相等" << endl;
	CComplex c8 = -c1;
	c8.Print();
	CComplex c9 = !c1;
	c9.Print();
	system("pause");
	return 0;
}