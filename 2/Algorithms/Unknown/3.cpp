#include <fstream>

using namespace std;

int array[100][100];

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	int n, m, num1, num2;

	input >> n >> m;

	for(int i = 0; i < m; i++){
		input >> num1 >> num2;

		array[num1 - 1][num2 - 1]++;
		array[num2 - 1][num1 - 1]++;
	}

	for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (array[i][j] > 1){
				output << "YES";

				return 0;
			}
        }
    }

	output << "NO";

	return 0;
}
