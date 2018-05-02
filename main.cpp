
#include<iostream>
#include<vector>
#include "project2.cpp"

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
	vector<int> vec1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };


	cout << "vector int binsearch 4: " << binSearch(vec1, 4, 0) << endl;
	cout << "vector int binsearch 8: " << binSearch(vec1, 8, 0) << endl;
	cout << "vector int binsearch 10: " << binSearch(vec1, 10, 0);


	int test;
	cin >> test;
	return 1;
}