#include<afxtempl.h>
template<class TYPE, class ARG_TYPE = const TYPE&>
class CListEx :public CList<TYPE, ARG_TYPE>{
public:
	typedef bool(*SORT_FUNC)(const TYPE &t1, const TYPE &t2);
	//表内排序
	void Sort(){
		CNode* pos = m_pNodeHead, *m, *q;
		while (pos){
			m = pos;
			q = pos->pNext;
			while (q){
				if (q->data < m->data)
					m = q;
				q = q->pNext;
			}
			if (m != pos){
				TYPE t = pos->data;
				pos->data = m->data;
				m->data = t;
			}
			pos = pos->pNext;
		}
	}

	//表外排序
	POSITION* Sort2(SORT_FUNC byFunc){
		int n = m_nCount, i = 0;
		CNode** ps = new CNode*[n+1];
		CNode* pos = m_pNodeHead;
		while (ps[i++]=pos)			
			pos = pos->pNext;
		i = 0;
		int j, m;
		while (i < n){
			j = i + 1;
			m = i;
			while (j < n){
				if (byFunc(ps[j]->data , ps[m]->data))
					m = j;
				++j;
			}
			if (m != i){
				CNode* t = ps[i];
				ps[i] = ps[m];
				ps[m] = t;
			}
			++i;
		}
		return (POSITION*)ps;
	}


	void Sort(SORT_FUNC byFunc){
		CNode* pos = m_pNodeHead, *m, *q;
		while (pos){
			m = pos;
			q = pos->pNext;
			while (q){
				if (byFunc(q->data,m->data))
					m = q;
				q = q->pNext;
			}
			if (m != pos){
				TYPE t = pos->data;
				pos->data = m->data;
				m->data = t;
			}
			pos = pos->pNext;
		}
	}
};