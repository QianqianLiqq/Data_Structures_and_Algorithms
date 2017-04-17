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
//ģ����cpp�ļ��������ͷ�ļ��У��������Ӳ��ϣ�����2019����
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