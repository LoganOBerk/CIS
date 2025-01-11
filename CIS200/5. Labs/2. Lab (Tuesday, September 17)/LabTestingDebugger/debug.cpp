#include <vector>
#include <iostream>
using namespace std;
class Data
{
public:
	Data()
	{
		_values.push_back(1);
		_values.push_back(2);
	}
	int getSum()
	{
		int total = 0;
		for (vector<int>::iterator itr = _values.begin(), end = _values.end();
			itr != end; ++itr)
		{
			total += *itr;
		}
		return total;
	}
	int getCount() { return _values.size(); }
private:
	vector<int> _values;
};
double compute_average(int sum, int count)
{
	return sum / static_cast<double>(count);
}
int main()
{
	Data d;
	cout << compute_average(d.getSum(), d.getCount()) << endl;
	return 0;
}