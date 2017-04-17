#include<iostream>
#include<vector>
using namespace std;
class WordDictionary {
public:
	vector<string> mem_word;
	// Adds a word into the data structure.
	void addWord(string word) {
		mem_word.push_back(word);
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		for (int start = 0; start < mem_word.size(); ++start){
			int t = 0;
			if (word[0] == '.'){
				while (word[t] == '.')
					++t;
			}
			if (t == word.size() && t <= mem_word[start].size())
				return true;
			for (int i = t; i < mem_word[start].size(); ++i){
				int j = t;
				if (mem_word[start][i] == word[j]){
					int k = i;
					while (k < mem_word[start].size() && j < word.size() && (mem_word[start][k] == word[j] || word[j] == '.')){
						++k;
						++j;
					}
					if (j == word.size())
						return true;
				}
			}
		}
		return false;
	}
};
int main(){
	WordDictionary wordDictionary;
	wordDictionary.addWord("a");
	wordDictionary.addWord("a");
	bool flag = wordDictionary.search("aa");
	cout << flag << endl;
	system("pause");
	return 0;
}