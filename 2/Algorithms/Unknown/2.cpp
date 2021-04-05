#include <fstream>

using namespace std;

int matrix[100][100];

int main(){
	ifstream input("input.txt");
	ofstream output("output.txt");
	int n;
	input >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
            input >> matrix[i][j];
        }
    }

	for (int i = 0; i < n; ++i){
		for (int j = i; j < n; ++j){
			if (((i == j) && (matrix[i][j] == 1)) || (matrix[i][j] != matrix[j][i])){
				output << "NO";
				return 0;
			}
        }
    }
	output << "YES";
	return 0;
}
