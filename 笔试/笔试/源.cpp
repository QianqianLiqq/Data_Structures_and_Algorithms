#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>
#include<stack>
#include<map>
#include<algorithm>
#include<math.h>
using namespace std;

bool isBalanced(int number){
	stringstream ss;
	ss << number;
	string str = ss.str();
	int length = str.size();
	if (length <= 0)
		return false;
	int left = 1;
	int right = 1;
	for (int i = 1; i < length; ++i){
		for (int j = 0; j < i; ++j)
			left *= str[j];					
		for (int k = i; k < length; ++k)
			right *= str[k];
		if (left == right)
			return true;
	}
	return false;
}

int function(vector<string> input, int n){
	if (n <= 1)
		return n;	
	vector<multiset<char>> sets;
	for (int i = 0; i<n; ++i){
		multiset<char> set;
		for (int j = 0; j < input[i].size(); ++j)
			set.insert(input[i][j]);
		sets.push_back(set);
	}
	int count = 1;
	vector<multiset<char>>::iterator it = sets.begin();
	stack<vector<multiset<char>>::iterator> stack;
	while (it!=sets.end()){
		for (size_t i = 1; i < sets.end()-it; ++i){
			if ((*it).size() == (*(it + i)).size()){
				multiset<char>::iterator it1 = (*it).begin();
				multiset<char>::iterator it2 = (*(it + i)).begin();
				while (it1 != (*it).end() && it2 != (*(it + i)).end() && *it1 == *it2){
					++it1;
					++it2;
				}
				if (it1 == (*it).end() && it2 == (*(it + i)).end()){
					stack.push(it + i);
				}
				else
					count++;
			}
			else
				count++;
		}
		while (!stack.empty()){
			vector<multiset<char>>::iterator itt = stack.top();
			stack.pop();
			sets.erase(itt);
		}
		++it;
	}
	return count;
}

int reverse(int number){
	string str;
	stringstream ss;
	ss << number;
	ss >> str;
	int length = str.size();
	int result = 0;
	for (int i = length-1; i>=0; --i){
		result = result * 10 + (str[i] - '0');
	}
	return result;
}
int reverseAdd(int a, int b){
	int result;
	if (a<1 || a>7000 || b<1 || b>7000)
		result = -1;
	else{
		result = reverse(a) + reverse(b);
	}
	return result;
}

void convert(string& init, char c){
	string result = init;
	if (c == 'R'){
		init[0] = result[5];
		init[1] = result[4];
		init[4] = result[0];
		init[5] = result[1];
	}
	if (c == 'L'){
		init[0] = result[4];
		init[1] = result[5];
		init[4] = result[1];
		init[5] = result[0];
	}
	if (c == 'A'){
		init[0] = result[3];
		init[1] = result[2];
		init[2] = result[0];
		init[3] = result[1];
	}
	if (c == 'C'){
		init[0] = result[2];
		init[1] = result[3];
		init[2] = result[1];
		init[3] = result[0];
	}
	if (c == 'F'){
		init[2] = result[4];
		init[3] = result[5];
		init[4] = result[3];
		init[5] = result[2];
	}
	if (c == 'F'){
		init[2] = result[5];
		init[3] = result[4];
		init[4] = result[2];
		init[5] = result[3];
	}
}

void converts(string& init, string str){
	int length = str.size();
	if (length <= 0)
		return;
	for (int i = 0; i<length; ++i){
		convert(init, str[i]);
	}
}

const int NO_EDGE = 1000;

vector<int> getVisitPath(vector<int> path, int startNode, int endNode){
	vector<int> visitPath;
	visitPath.push_back(endNode);
	if (path[endNode] != -1){
		while (path[endNode] != startNode){
			visitPath.insert(visitPath.begin(), path[endNode]);
			endNode = path[endNode];
		}
	}
	visitPath.insert(visitPath.begin(), startNode);
	return visitPath;
}

int dijkstra(vector<vector<int>> weights, int startNode, int endNode, vector<int>& resultPath){
	vector<int> distance;//源点到每个点的直接可达路径（距离）
	for (size_t j = 0; j < weights.size(); ++j)
		distance.push_back(weights[startNode][j]);

	vector<int> S;//被访问的点为1，未被访问的为0
	for (size_t j = 0; j < weights.size(); ++j)
		S.push_back(0);
	S[startNode] = 1;

	vector<int> path;//访问路径
	for (size_t j = 0; j < weights.size(); ++j){
		if (weights[startNode][j] == NO_EDGE)
			path.push_back(-1);
		else
			path.push_back(startNode);
	}
	path[startNode] = startNode;

	int minDistance;
	int k;//最近的点
	for (size_t i = 0; i < weights.size(); ++i){
		minDistance = NO_EDGE;
		for (size_t j = 0; j < weights.size(); ++j){
			if (S[j] == 0 && distance[j] < minDistance){
				minDistance = distance[j];
				k = j;
			}
		}
		S[k] = 1;
		for (size_t j = 0; j < weights.size(); ++j){
			if (distance[k] + weights[k][j] < distance[j]){
				distance[j] = distance[k] + weights[k][j];
				path[j] = k;
			}
		}
	}
	resultPath = getVisitPath(path, startNode, endNode);
	return distance[endNode];
}

int getPos(int n, int nlen, vector<vector<int>>& vSrc)
{
	int outNum = 1000;
	if (vSrc[5][n] != 0)
		return vSrc[5][n] + nlen;
	if (nlen >= 1000)
		return 1000;
	vector<int> temp(7, 1000);
	for (int i = 1; i < 7; ++i)
	{
		int curNum = vSrc[i][n] == 0 ? 1000 : vSrc[i][n];
		temp[i] = getPos(i, nlen + curNum, vSrc);
		outNum = outNum < temp[i] ? outNum : temp[i];
	}

	return outNum;
}

void function(vector<int>& input, int k){
	if (k <= 0 || input.size() <= 0)
		return;
	int length = input.size();
	for (int i = 0; i<k; ++i){
		int start = input[0];
		for (int j = 0; j<length - 1; ++j){
			input[j] += input[j + 1];
			if (input[j] >= 100)
				input[j] = input[j] % 100;
		}
		input[length - 1] += start;
		if (input[length - 1] >= 100)
			input[length - 1] = input[length - 1] % 100;
	}
}

void dfs(int curPos, int& countNum, vector<int> vMan, vector<vector<int>> vSrc)
{
	if (curPos == 5)
	{
		for (int i = 0; i < vSrc[curPos].size(); ++i)
		{
			if (vSrc[curPos][i] == 1 && vMan[i] == 1)
			{
				countNum++;
			}
		}
		return;
	}
	else
	{
		for (int i = 0; i < vSrc[curPos].size(); ++i)
		{
			if (vSrc[curPos][i] == 1 && vMan[i] == 1)
			{
				vMan[i] = 0;
				dfs(curPos + 1, countNum, vMan, vSrc);
				vMan[i] = 1;
			}
		}
	}
}

bool core(string str, int start, int end){
	multiset<char> sets;
	for (int i = start; i <= end; ++i)
		sets.insert(str[i]);
	multiset<char>::iterator it = sets.begin();
	while (it != sets.end()){
		if (*it == *(++it))
			++it;
		else
			return false;
	}
	return true;
}
int function(string input){
	int length = input.size();
	if (length <= 0)
		return 0;
	vector<vector<int>> result(length, vector<int>(length, 0));
	for (int i = 0; i<length; ++i){
		for (int j = 0; j<length; ++j){
			if ((j - i) % 2 == 0)
				result[i][j] = 0;
			else{
				if (core(input, i, j))
					result[i][j] = 1;
				else
					result[i][j] = 0;
			}
		}
	}
	int count = 0;
	for (int i = 0; i<length; ++i){
		for (int j = 0; j<length; ++j){
			if (result[i][j] == 1)
				count++;
		}
	}
	return count;
}

enum etest{
	eparam1,         //0
	eparam2,         //1
	eparam3=10,      //10
	eparam4,         //11
	eparam5 = 'a',   //97
	eparam6,         //98
}epr;

int function(vector<int> input, int n, int sum){
	if (input.size()<n)
		return 0;
	int count = 0;
	int temp = 0;
	int j = 0;
	for (; j<n; ++j)
		temp += input[j];
	--j;
	while (j<input.size()-1){
		if (temp <= sum)
			count++;
		temp = temp + input[j + 1] - input[j + 1 - n];
		++j;
	}
	if (temp <= sum)
		count++;
	return count;
}

char findFirstRepeat(string A, int n) {
	char res = ' ';
	// write code here
	if (n <= 0)
		return res;
	set<char> st;
	set<char>::iterator it = st.begin();
	for (int i = 0; i<n; ++i){
		if (st.find(A[i]) != st.end())
			return A[i];
		else
			st.insert(A[i]);
	}
	return res;
}

int kmp(string target, string pattern){
	int target_length = target.size();
	int pattern_length = pattern.size();
	vector<int> overly_value(pattern_length, 0);
	overly_value[0] = -1;
	int index = 0;
	for (int i = 1; i<pattern_length; ++i){
		index = overly_value[i - 1];
		while (index >= 0 && pattern[i] != pattern[index + 1])
			index = overly_value[index];
		if (pattern[i] == pattern[index + 1])
			overly_value[i] = index + 1;
		else
			overly_value[i] = -1;
	}
	int target_index = 0;
	int pattern_index = 0;
	int count = 0;
	while (target_index<target_length&&pattern_index<pattern_length){
		if ((target[target_index] == pattern[pattern_index]) || (target[target_index] == pattern[pattern_index] - 32)){
			++target_index;
			++pattern_index;
		}
		else if (pattern_index == 0)
			++target_index;
		else
			pattern_index = overly_value[pattern_index - 1] + 1;
		if (pattern_index == pattern_length){
			pattern_index = 0;
			count++;
		}
	}
	return count;
}
vector<string> findCoder(vector<string> A, int n) {
	// write code here
	vector<string> res;
	if (n <= 0)
		return res;
	multimap<int, string> mp;
	int count = 0;
	string key = "coder";
	for (int i = n - 1; i >= 0; --i){
		count = kmp(A[i], "coder");
		mp.insert(pair<int, string>(count, A[i]));
	}
	multimap<int, string>::iterator it = mp.end();
	--it;
	for (; it != mp.begin(); --it)
		res.push_back(it->second);
	return res;
}

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int data){
		val = data;
		left = right = nullptr;
	}
};
void dfs(TreeNode* root,int n,vector<int>& path,int &count){
	path.push_back(root->val);
	if (root->val == n){
		for (int i = 0; i < path.size()-1; ++i)
			cout << path[i] << "->";
		cout << path[path.size() - 1] << endl;
		count++;
	}
	if (root->left)
		dfs(root->left, n, path, count);
	if (root->right)
		dfs(root->right, n, path, count);
	path.pop_back();
}
int FindAndPrint(TreeNode* root, int n){
	if (root == nullptr){
		cout << "NotFound" << endl;
		return 0;
	}
	vector<int> path;
	int count = 0;
	dfs(root, n, path, count);
	if (count == 1)
		return 1;
	else if (count > 1)
		return 2;
}

bool checkDifferent(string iniString) {
	// write code here
	int length = iniString.size();
	if (iniString == " " || length <= 0)
		return true;
	for (int i = 0; i<length - 1; ++i){
		for (int j = i + 1; j < length; ++j){
			if (iniString[i] == iniString[j])
				return false;
		}
	}
	return true;
}

void reOrderArray(vector<int> &array) {
	int length = array.size();
	if (length <= 0)
		return;
	int i = 0, j = 0 ;
	while (i<length&&j<length){
		while (i<length && ((array[i] & 1) == 1))
			++i;
		j = i + 1;
		while (j<length && ((array[j] & 1) == 0))
			++j;
		if (j >= length)
			break;
		int temp = array[j];
		for (int k = j - 1; k >= i; --k)
			array[k + 1] = array[k];
		array[i] = temp;
	}
}

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
}; 
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr&&pHead2 == nullptr)
		return nullptr;
	ListNode* list;
	if (pHead1->val<pHead2->val){
		list = new ListNode(pHead1->val);
		pHead1 = pHead1->next;
	}
	else{
		list = new ListNode(pHead2->val);
		pHead2 = pHead2->next;
	}
	ListNode* res = new ListNode(0);
	res->next = list;
	while (pHead1&&pHead2){
		if (pHead1->val<pHead2->val){
			list->next = new ListNode(pHead1->val);
			pHead1 = pHead1->next;
			list = list->next;
		}
		else{
			list->next = new ListNode(pHead2->val);
			pHead2 = pHead2->next;
			list = list->next;
		}
	}
	while (pHead1){
		list->next = new ListNode(pHead1->val);
		pHead1 = pHead1->next;
		list = list->next;
	}
	while (pHead2){
		list->next = new ListNode(pHead2->val);
		pHead2 = pHead2->next;
		list = list->next;
	}
	return res->next;
}

void findPeak(vector<int> number){
	int length = number.size();
	if (length <= 0){
		cout << -1 << endl;
		return;
	}
	int left = 0, right = 0;
	int maxCount = 0;
	int start = 0, end = 0;
	for (int i = 1; i < length; ++i){
		if (number[i] > number[i - 1]){
			left = i - 1;
			while (i<length&&number[i]>number[i - 1])			
				i++;			
			while (i < length&&number[i] < number[i - 1])				
				i++;			
			right = i - 1;
			if (right - left + 1 > maxCount){
				maxCount = right - left + 1;
				start = left;
				end = right;
			}
		}
		--i;
	}
	cout << start << " " << end << endl;
}

set<string> slidParagraph(string paragraph){
	set<string> res;
	string temp;
	for (int i = 0; i < paragraph.size(); ++i){
		if (paragraph[i] != ' ')
			temp.push_back(paragraph[i]);
		else{
			res.insert(temp);
			temp.clear();
		}
	}
	if (paragraph[paragraph.size() - 1] != ' ')
	    res.insert(temp);
	return res;
}
void Paragraph(vector<string> input, vector<string> inquiry){
	int length1 = input.size();
	int length2 = inquiry.size();
	if (length1 <= 0 || length2 <= 0)
		return;
	for (int i = 0; i < length2; ++i){
		set<string> inquirySet = slidParagraph(inquiry[i]);
		int maxCount = 0;
		string output = input[0];
		for (int j = 0; j < length1; ++j){
			set<string> inputSet = slidParagraph(input[j]);
			int count = 0;
			set<string>::iterator it = inquirySet.begin();
			while (it != inquirySet.end()){
				if (inputSet.find(*it) != inputSet.end())
					count++;
				it++;
			}
			if (count > maxCount){
				maxCount = count;
				output = input[j];
			}
		}
		cout << output << endl;
	}
}

void inquiry(vector<int> A, vector<int> B, vector<vector<int>> xy){
	int lengthA = A.size();
	int lengthB = B.size();
	if (lengthA <= 0 || lengthB <= 0)
		return;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (int i = 0; i < xy.size(); ++i){
		int x = xy[i][0];
		int y = xy[i][1];
		int numX = 0;
		int numY = 0;
		int j = 0;
		while (j < lengthA&&A[j] < x)
			++j;
		numX = lengthA - j;
		int k = 0;
		while (k < lengthB&&B[k] < y)
			++k;
		numY = lengthB - k;
		cout << (numX < numY ? numX : numY) << endl;
	}
}

bool wordBreak(string s, unordered_set<string> &dict) {
	int length1 = s.size();
	int length2 = dict.size();
	if (length1 <= 0 || length2 <= 0)
		return false;
	vector<bool> dp(length1 + 1, false);
	dp[0] = true;
	for (int i = 1; i<length1 + 1; ++i){
		for (int j = 0; j<i; ++j){
			string temp = s.substr(j, i-j);
			if (dp[j] && dict.find(s.substr(j, i)) != dict.end()){
				dp[i] = true;
				break;
			}
		}
	}
	return dp[length1];
}

char fun(string str){
	char res;
	int length = str.size();
	set<char> sets;
	set<char>::iterator it;
	vector<char> vec;
	for (int i = 0; i<length; ++i){
		it = sets.find(str[i]);
		if (it == sets.end()){
			sets.insert(str[i]);
			vec.push_back(str[i]);
		}
		else{
			vector<char>::iterator iter = vec.begin();
			while (iter != vec.end()){
				if (*iter == str[i]){
					vec.erase(iter);
					break;
				}
				++iter;
			}
		}
	}
	if (vec.size() != 0)
		res = vec[0];
	return res;
}

char First_appearing_once(string str)
{
	if (str.empty())
	{
		//throw new exception;  
		cout << "字符串为空" << endl;
		exit(1);   /*异常退出*/
	}

	map<char, int> word_count;
	/**unsigned int i;这里要用无符号整型，因为size()产生的是无符号整型；直接用int，会产生警告*/
	string::size_type i;                       /**size_type 就是容器中定义的无符号整型*/
	char target_ch;
	for (i = 0; i < str.size(); i++)
	{
		++word_count[str[i]];
	}
	for (i = 0; i < str.size(); i++)
	{
		if (1 == word_count[str[i]])
		{
			target_ch = str[i];
			break;
		}
	}

	return target_ch;
}

vector<int> isprime(int n){
	vector<int> prime(n+1, 1);
	prime[0] = 0;
	prime[1] = 0;
	for (int i = 2; i < sqrt(n); ++i){
		if (prime[i]){
			for (int j = i*i; j <= n; j = j + i)
				prime[j] = 0;
		}
	}
	return prime;
}

int main(){
	vector<int> prime = isprime(100);
	for (int i = 0; i < prime.size(); ++i)
		if (prime[i])
			cout << i << " ";
	cout << endl;

	/*int data;
	cin >> data;
	int bin[8] = { 0 };
	int n, i = 0;
	data = abs(data);
	do{
		n = data % 2;
		bin[i] = abs(n);
		data = data / 2;
		i++;
	} while (data != 0);
	bin[7] = 1;
	for (int j = 0; j < 7; ++j){
		if (bin[j] == 0)
			bin[j] = 1;
		else
			bin[j] = 0;
	}
	bool flag = false;
	int index = 0;
	while (bin[index] + 1 == 2){
		bin[index] = 0;
		index++;
	}
	bin[index]++;
	for (i = 7; i >= 0; i--)
		cout << bin[i];*/

	/*string s = "bccdbacdbdacddabbaaaadababadad";
	unordered_set<string> dict = { "cbc", "bcda", "adb", "ddca", "bad", "bbb", "dad", "dac", "ba", "aa",
		"bd", "abab", "bb", "dbda", "cb", "caccc", "d", "dd", "aadb", "cc", "b", "bcc", "bcd", "cd",
		"cbca", "bbd", "ddd", "dabb", "ab", "acd", "a", "bbcc", "cdcbd", "cada", "dbca", "ac", "abacd",
		"cba", "cdb", "dbac", "aada", "cdcda", "cdc", "dbc", "dbcb", "bdb", "ddbdd", "cadaa", "ddbc",
		"babb" };
	wordBreak(s, dict);*/

	/*vector<int> A = { 3, 2, 4 };
	vector<int> B = { 6, 5, 8 };
	vector<vector<int>> xy = { { 1, 1 }, { 4, 8 } };
	inquiry(A, B, xy);*/


	/*vector<string> input = {
		" An algorithm is an effective method that can be expressed within a finite amount of space and time ",
		"Starting from an initial state and initial input the instructions describe a computation",
		"That when executed proceeds through a finite number of successive states",
		"Eventually producing output and terminating at a final ending state",
		"The transition from one state to the next is not necessarily deterministic",
		"Some algorithms known as randomized algorithms incorporate random input"
	};
	vector<string> inquiry = {
		"Next to the transition",
		"Wormhole infinite time and space",
		"The transition from one state to the next is not necessarily deterministic"
	};
	Paragraph(input, inquiry);*/

	/*vector<int> number = { 1, 3, 1, 2, 5, 4, 3, 1, 5, 7, 9, 10, 12, 8, 6, 5, 3, 0 };
	findPeak(number);*/



	/*int n;
	cin >> n;
	string str;
	vector<string> input;
	int i = n+1;
	while (i--){
	getline(cin, str);
	input.push_back(str);
	if (i == n)
	input.pop_back();
	}
	cout << function(input, n) << endl;*/

	/*string str = "RA";
	string init = "123456";
	converts(init, str);
	cout << init << endl;*/

	/*int X;
	cin >> X;
	int Y;
	cin >> Y;
	int startNode = 5;
	vector<vector<int>> weights = { { NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE },
	{ NO_EDGE, 0, 2, 10, 5, 3, NO_EDGE },
	{ NO_EDGE, NO_EDGE, 0, 12, NO_EDGE, NO_EDGE, 10 },
	{ NO_EDGE, NO_EDGE, NO_EDGE, 0, NO_EDGE, 7, NO_EDGE },
	{ NO_EDGE, 2, NO_EDGE, NO_EDGE, 0, 2, NO_EDGE },
	{ NO_EDGE, 4, NO_EDGE, NO_EDGE, 1, 0, NO_EDGE },
	{ NO_EDGE, 3, NO_EDGE, 1, NO_EDGE, 2, 0 } };
	for (int i = 1; i<7; ++i){
	weights[Y][i] = NO_EDGE;
	weights[i][Y] = NO_EDGE;
	}
	vector<int> resultPath;
	int time = dijkstra(weights, startNode, X, resultPath);
	cout << time << endl;
	if (resultPath.size()>0){
	cout << "[";
	for (size_t i = 0; i<resultPath.size() - 1; ++i){
	cout << resultPath[i] << ", ";
	}
	cout << resultPath[resultPath.size() - 1] << "]";
	}*/

	/*int a, b;
	cin >> a >> b;

	vector<vector<int>> vSrc(7, vector<int>(7, 0));
	vSrc[1][2] = 2;
	vSrc[1][3] = 10;
	vSrc[1][4] = 5;
	vSrc[1][5] = 3;
	vSrc[2][3] = 12;
	vSrc[2][6] = 10;
	vSrc[3][5] = 7;
	vSrc[4][1] = 2;
	vSrc[4][5] = 2;
	vSrc[5][1] = 4;
	vSrc[5][4] = 1;
	vSrc[6][1] = 3;
	vSrc[6][3] = 1;
	vSrc[6][5] = 2;
	for (int i = 1; i < 7; ++i)
	{
	vSrc[i][b] = 0;
	vSrc[b][i] = 0;
	}
	int outDis = getPos(a, 0, vSrc);
	if (outDis >= 1000)
	{
	cout << 1000;
	}
	else{
	cout << outDis;
	}*/



	system("pause");
	return 0;
}