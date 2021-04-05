#include<fstream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	ifstream input("search1.in");
	ofstream output("search1.out");
	string sub_str, str;

	input >> sub_str >> str;

	if (sub_str.length() > str.length())
	{
		output << "0" << endl;

		return 0;
	}
	else
    {
        vector<int> res;

        for(int i = 0; i < (str.length() - sub_str.length() + 1); i++)
        {
            int j;

            for(j = 0; j < sub_str.length(); j++)
            {
                if (sub_str[j] != str[i + j])
                {
                    break;
                }
            }

            if (j == sub_str.length())
            {
                res.push_back(i + 1);
            }
        }

        output << res.size() << endl;

        for(int i = 0; i < res.size(); i++)
        {
            output << res[i] << " ";
        }

        return 0;
    }
}
