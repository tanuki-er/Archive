#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

bool higher(vector<double> &h)
{
	for(int i = 2; i < h.size(); i++)
	{
		h[i] = (h[i - 1] + 1) * 2 - h[i - 2];

		if (h[i] <= 0)
        {
            return false;
        }
	}

	return true;
}

int main()
{
	ifstream input("garland.in");
	ofstream output("garland.out");
	int n;

	input >> n;

	vector<double> h(n);

	input >> h[0];

	double min, max;

	min = 0;
	max = h[0];

	while (true)
	{
		h[1] = (min + max) / 2;

		if ((h[1] == min) || (h[1] == max))
        {
            break;
        }

		if (higher(h))
        {
            max = h[1];
        }
		else
        {
            min = h[1];
        }
	}

	output << fixed << setprecision(2) << abs(h[n - 1]);
	return 0;
}
