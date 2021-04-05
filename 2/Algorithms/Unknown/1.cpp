#include <fstream>

using namespace std;

int matrix[100][100];

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	int n, m, edge1, edge2;
	input >> n >> m;
	for(int i = 0; i < m; i++){
		input >> edge1 >> edge2;
		matrix[edge1 - 1][edge2 - 1] = 1;
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
        {
            output << matrix[i][j] << " ";
        }
		output << "\n";
	}

	return 0;
}
