 
#include<iostream>   
using namespace std;
const int c = 10;             //����������  
const int w[] = { 0, 2, 2, 6, 5, 4 };//��Ʒ������������0��λ�ò�ʹ�� ��   
const int v[] = { 0, 6, 3, 5, 4, 6 };//��Ʒ��Ӧ�Ĵ��ӣ�0��λ����Ϊ�ա�  
const int n = sizeof(w) / sizeof(w[0]) - 1; //nΪ��Ʒ�ĸ���   
int x[n + 1];
void package0_1(int m[n + 1][c + 1], const int w[], const int v[], const int n)//n������Ʒ�ĸ���   
{
/*	//���ôӵ׵�����˳��������m[i][j]��ֵ  
	//���ȷ�w[n]  
	for (int j = 0; j <= c; j++)
		if (j < w[n]) m[n][j] = 0;     //jС��w[n],����Ӧ��ֵ��Ϊ0�������Ϊ���Է���   
		else         m[n][j] = v[n];

		//��ʣ�µ�n-1����Ʒ���з��á�  
		int i;
		for (i = n - 1; i >= 1; i--)
			for (int j = 0; j <= c; j++)
				if (j < w[i])
					m[i][j] = m[i + 1][j];//���j < w[i]�򣬵�ǰλ�þͲ��ܷ��ã���������һ��λ�õ�ֵ��  
		//���򣬾ͱȽϵ����Ƿ���֮���ֵ�󣬻��ǲ����õ�ֵ��ѡ�����нϴ��ߡ�              
				else         m[i][j] = m[i + 1][j] > m[i + 1][j - w[i]] + v[i] ?
					m[i + 1][j] : m[i + 1][j - w[i]] + v[i];*/
	for (int i = 1, j = 0; j <= c; ++j){
		if (j >= w[i])
			m[i][j] = v[i];
		else
			m[i][j] = 0;
	}
	for (int i = 2; i <= n; ++i){
		for (int j = 0; j <= c; ++j)
			if (j >= w[i])
				m[i][j] = (m[i - 1][j] >= m[i - 1][j - w[i]] + v[i]) ? m[i - 1][j] : m[i - 1][j - w[i]] + v[i];
			else
				m[i][j] = m[i - 1][j];
	}
}
void answer(int m[n + 1][c + 1], const int n)
{
	int j = c;
	int i;
/*	for (i = 1; i <= n - 1; i++)
		if (m[i][j] == m[i + 1][j]) x[i] = 0;
		else {
			x[i] = 1;
			j = j - w[i];
		}
		x[n] = m[i][j] ? 1 : 0;*/
	for (i = n; i >= 2; --i){
		if (m[i][j] == m[i - 1][j])
			x[i] = 0;
		else{
			x[i] = 1;
			j = j - w[i];
		}
	}
	x[1] = m[1][j] ? 1 : 0;
}
int main()
{
	int m[n+1][c+1] = { 0 };

	package0_1(m, w, v, n);
	for (int i = 0; i <= 5; i++)
	{
		for (int j = 0; j <= 10; j++)
			cout << m[i][j] << "   ";
		cout << endl;
	}
	answer(m, n);
	cout << "The best answer is:\n";
	for (int i = 1; i <= 5; i++)
		cout << x[i] << " ";
	system("pause");
	return 0;
}