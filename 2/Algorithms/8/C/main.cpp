#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> res;
string str;

vector<int> F(string &str)
{
	res.push_back(0);

	for(int i = 1; i < str.length(); i++)
	{
		int j = res[i - 1];

		while (j > 0 && str[i] != str[j])
        {
            j = res[j - 1];
        }

		if (str[i] == str[j])
        {
            j++;
        }

		res.push_back(j);
	}

	return res;
}
int main()
{
	ifstream input("prefix.in");
	ofstream output("prefix.out");

	input >> str;

	res = F(str);

	for(int i = 0; i < res.size(); i++)
    {
        output << res[i] << " ";
    }

	return 0;
}
