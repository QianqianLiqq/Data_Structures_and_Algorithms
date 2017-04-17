#pragma once
template<class DATA>
class CComplex
{
	DATA m_fReal, m_fImage;
public:
	CComplex(){
		m_fReal = m_fImage = 0;
	}
	CComplex(DATA r, DATA i){
		m_fReal = r;
		m_fImage = i;
	}
	~CComplex(){

	}
	void Print()
	{
		cout << m_fReal << ":" << m_fImage << endl;
	}
};

