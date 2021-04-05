#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

const int num1 = 1733;
const int num2 = 227;

struct structure
{
    string key;
    list <string> numbers[num2];
};

vector <string> res_get;
list <structure> first[num1];
list <structure>::iterator n1;
list <string>::iterator n2;

int get_hash(string& s, int mod)
{
    int res;

    res = 0;

    for(int i = 0; i < s.size(); i++)
    {
        res = res * 31 % mod;
        res += (s[i] - 'A' + 1);
        res = res % mod;
    }

    return res;
}

void ins(string &s1, string &s2)
{
    structure structure_new;
    int h1, h2;

    h1 = get_hash(s1, num1);
    h2 = get_hash(s2, num2);

    for(n1 = first[h1].begin(); n1 != first[h1].end(); n1++)
    {
        if (n1->key == s1)
        {
            for(n2 = n1->numbers[h2].begin(); n2 != n1->numbers[h2].end(); n2++)
            {
                if (*n2 == s2)
                {
                    return;
                }
            }

            n1->numbers[h2].push_back(s2);

            return;
        }
    }

    structure_new.key = s1;

    structure_new.numbers[h2].push_back(s2);
    first[h1].push_back(structure_new);
}

void del(string &s1, string &s2)
{
    int h1, h2;

    h1 = get_hash(s1, num1);
    h2 = get_hash(s2, num2);

    for(n1 = first[h1].begin(); n1 != first[h1].end(); n1++)
    {
        if (n1->key == s1)
        {
            for(n2 = n1->numbers[h2].begin(); n2 != n1->numbers[h2].end(); n2++)
            {
                if (*n2 == s2)
                {
                    n1->numbers[h2].erase(n2);

                    return;
                }
            }
        }
    }
}

void get(string &s)
{
    int h = get_hash(s, num1);

    for(n1 = first[h].begin(); n1 != first[h].end(); n1++)
    {
        if (n1->key == s)
        {
            for(int i = 0; i < num2; i++)
            {
                for(n2 = n1->numbers[i].begin(); n2 != n1->numbers[i].end(); n2++)
                {
                    res_get.push_back(*n2);
                }
            }
        }
    }

    int k;

    k = res_get.size();

    cout << k << " ";

    for(int j = 0; j < k; j++)
    {
        cout << res_get.back() << " ";

        res_get.pop_back();
    }

    res_get.clear();

    cout << endl;
}

void delete_all(string &s)
{
    int h;

    h = get_hash(s, num1);

    for(n1 = first[h].begin(); n1 != first[h].end(); n1++)
    {
        if (n1->key == s)
        {
            first[h].erase(n1);

            return;
        }
    }
}

int main()
{
    freopen("multimap.in", "r", stdin);
    freopen("multimap.out", "w", stdout);

    string str, str1, str2;

    while(cin >> str)
    {
        if (str == "put")
        {
            cin >> str1 >> str2;

            ins(str1, str2);
        }

        if (str == "get")
        {
            cin >> str1;

            get(str1);
        }

        if (str == "delete")
        {
            cin >> str1 >> str2;

            del(str1, str2);
        }

        if (str == "deleteall")
        {
            cin >> str1;

            delete_all(str1);
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
