#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> Fast(string &str)
{
	vector<int> res;
	res.push_back(0);
	for(int i = 1; i < str.length(); i++){
		int k;
		k = res[i - 1];
		while (k > 0 && str[i] != str[k])   k = res[k - 1];
		if (str[i] == str[k])   k++;
		res.push_back(k);
	}
	return res;
}

vector<int> Knuth_Morris_Pratt(string &sub_str, string &str){
	int sub_str_len, str_len;
	sub_str_len = sub_str.length();
	str_len = str.length();
	vector<int> res, Prefix;
	string copy_str;

	copy_str = sub_str + "#" + str;
	Prefix = Fast(copy_str);
	for(int i = 0; i < str_len; i++)
        if (Prefix[sub_str_len + i + 1] == sub_str_len) res.push_back(i - sub_str_len + 2);
	return res;
}

int main(){
	ifstream fin("search2.in");
	ofstream fout("search2.out");
	string sub_str, str;
	fin >> sub_str >> str;

	vector<int> res;

	res = Knuth_Morris_Pratt(sub_str, str);
	fout << res.size() << endl;
	for(int i = 0; i < res.size(); i++) fout << res[i] << " ";

	return 0;
}
