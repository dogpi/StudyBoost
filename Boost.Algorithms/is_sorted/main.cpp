#include <iostream>
#include <boost/algorithm/cxx11/is_sorted.hpp>
#include <vector>

using namespace std;
using namespace boost::algorithm;

int main()
{
	vector<int> sequence1 = { 1, 2, 3, 4, 5, 3 };
	vector<int>	sequence2 = { 1, 2, 3, 4, 5, 9 };
	vector<int>	sequence3 = { 9, 5, 4, 3, 2, 1 };
	vector<int>	sequence4 = { 1, 2, 3, 3, 4, 5, 9 };
	vector<int>	sequence5 = { 9, 5, 4, 3, 3, 2, 1 };

	cout << is_sorted(sequence1.begin(), sequence1.end(), std::less<int>()) << endl;		// false
	cout << is_sorted(sequence2.begin(), sequence2.end(), std::less<int>()) << endl;		// true
	cout << is_sorted(sequence3.begin(), sequence3.end(), std::greater<int>()) << endl;		// true
	
	cout << *is_sorted_until(sequence1.begin(), sequence1.end(), std::less<int>()) << endl;	// 3
	vector<int>::iterator it = is_sorted_until(sequence2.begin(), sequence2.end(), std::less<int>());
	if (it == sequence2.end()){
		cout << "sequence2.end()" << endl;
	}

	cout << is_increasing(sequence1.begin(), sequence1.end()) << endl;			// false
	cout << is_increasing(sequence1.begin(), sequence1.end()-1) << endl;		// true
	cout << is_increasing(sequence4.begin(), sequence4.end()) << endl;			// true
	cout << is_strictly_increasing(sequence4.begin(), sequence4.end()) << endl;			// false


	cout << is_decreasing(sequence3.begin(), sequence3.end()) << endl;			// true
	cout << is_decreasing(sequence5.begin(), sequence5.end()) << endl;			// true
	cout << is_strictly_decreasing(sequence5.begin(), sequence5.end()) << endl;			// false

	system("pause");
	return 0;
}