
#include<iostream>
#include<vector>
#include "project2.cpp"

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
	vector<int> vec1 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	cout << "If binSearch returns -1, element is not in vector:" << endl;
	cout << "vector int binsearch 4: " << binSearch(vec1, 4, 0) << endl;
	cout << "vector int binsearch 8: " << binSearch(vec1, 8, 0) << endl;
	cout << "vector int binsearch 10: " << binSearch(vec1, 10, 0) << endl << endl;
	//

	vector<int> vec2 = { 11, 6, 77, 8, 0, 22, 35, 100 };
	vector<int> vec3;

	vector<char> vec4 = { 'c', 'a', 'z', '0', '`', 'b' };
	vector<char> vec5;

	vec3 = QuickSort(vec2, vec3);
	vec5 = QuickSort(vec4, vec5);

	cout << "quick sort vec2: ";
	for (int x = 0; x < vec3.size(); x++) {
		cout << vec3[x] << " ";
	}
	cout << endl;
	cout << "quick sort vec4: ";
	for (int x = 0; x < vec5.size(); x++) {
		cout << vec5[x] << " ";
	}


	int test;
	cin >> test;
	return 1;
}