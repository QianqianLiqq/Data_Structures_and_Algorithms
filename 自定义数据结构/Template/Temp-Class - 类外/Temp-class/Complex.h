#pragma once
template<typename DATA>
class CComplex
{
	DATA m_fReal, m_fImage;
public:
	CComplex();
	CComplex(DATA r, DATA i);
	~CComplex();
	void Print();
	
};
//模板中cpp文件必须放在头文件中，否则链接不上，出现2019错误
template<typename DATA>
CComplex<DATA>::CComplex(){
	m_fReal = m_fImage = 0;
}

template<typename DATA>
CComplex<DATA>::CComplex(DATA r, DATA i){
	m_fReal = r;
	m_fImage = i;
}

template<typename DATA>
CComplex<DATA>::~CComplex(){

}

template<typename DATA>
void CComplex<DATA>::Print()
{
	cout << m_fReal << ":" << m_fImage << endl;
}