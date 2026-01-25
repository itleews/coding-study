#include <iostream>
#include <string>
using namespace std;

int main()
{
	string isbn;
	int sum = 0;
	int missing_idx = -1;

	cin >> isbn;
	for (int idx = 0; idx < 13; idx++)
	{
		if (isbn[idx] == '*')
		{
			missing_idx = idx;
			continue;
		}

		int num = isbn[idx] - '0';

		if (idx % 2 == 0)
		{
			sum += num;
		}
		else
		{
			sum += num * 3;
		}
	}

	int weight = (missing_idx % 2 == 0) ? 1 : 3;
	for (int digit = 0; digit <= 9; digit++)
	{
		int total = sum + digit * weight;
		if (total % 10 == 0)
		{
			cout << digit << endl;
			break;
		}
	}

	return 0;
}