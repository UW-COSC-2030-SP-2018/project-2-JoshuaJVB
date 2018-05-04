#include "bloomFilter.cpp"
#include<iostream>
#include "project2.cpp"

using std::cin;
using std::cout;
using std::endl;

unsigned int djb2(std::string str) {
	unsigned int hash = 5381;

	for (std::string::iterator iter = str.begin(); iter != str.end(); iter++) {
		hash = ((hash << 5) + hash) + *iter;
	}

	return hash;
}

int main() {
	vector<int> vec1 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<string> vec01 = { "This", "is", " a string", "test" , "for binsearch" };
	string sBin = "test";
	string sBinFail = "watermelon";

	cout << "vector int: ";
	for (int x = 0; x < vec1.size(); x++) {
		cout << vec1[x] << " ";
	}
	cout << endl << "If binSearch returns -1, element is not in vector:" << endl;
	cout << "vector int binsearch 4: " << binSearch(vec1, 4, 0) << endl;
	cout << "vector int binsearch 8: " << binSearch(vec1, 8, 0) << endl;
	cout << "vector int binsearch 10: " << binSearch(vec1, 10, 0) << endl;

	cout << "vector string: ";
	for (int x = 0; x < vec01.size(); x++) {
		cout << "'" << vec01[x] << "' ";
	}
	cout << endl << "vector string binsearch: 'test': " << binSearch(vec01, sBin, 0) << endl;
	cout << "vector string binsearch: 'watermelon': " << binSearch(vec01, sBinFail, 0) << endl << endl;



	vector<int> vec2 = { 11, 6, 77, 8, 0, 22, 35, 100 };
	vector<int> vec3;

	vector<char> vec4 = { 'c', 'a', 'z', '0', '`', 'b' };
	vector<char> vec5;

	cout << "vec2 before sort: ";
	for (int x = 0; x < vec2.size(); x++) {
		cout << vec2[x] << " ";
	}
	cout << endl;

	vec3 = QuickSort(vec2, vec3);
	vec5 = QuickSort(vec4, vec5);

	cout << "quick sort vec2: ";
	for (int x = 0; x < vec3.size(); x++) {
		cout << vec3[x] << " ";
	}
	cout << endl;

	cout << "vec4 before sort: ";
	for (int x = 0; x < vec4.size(); x++) {
		cout << vec4[x] << " ";
	}
	cout << endl;
	cout << "quick sort vec4: ";
	for (int x = 0; x < vec5.size(); x++) {
		cout << vec5[x] << " ";
	}
	cout << endl;

	vector<int> vec6 = { 2, 4, 1, 10, 2, 5, 22, 8, 7, 9 };
	cout << "vec6 before merge sort: ";
	for (int x = 0; x < vec6.size(); x++) {
		cout << vec6[x] << " ";
	}
	cout << "merge sort vec6: ";

	mergeSort(vec6, 0, vec6.size() - 1);

	for (int x = 0; x < vec6.size(); x++) {
		cout << vec6[x] << " ";
	}
	cout << endl;
	cout << endl;

	string s = "the quick brown fox";
	cout << "string hashing: " << s  << " "
		<< hashing(s) << endl;
	cout << "Int hashing: 17: " << hashing(17);
	cout << endl << endl;


	// create bloom filter
	std::vector<HashFunction> hashFunctions;
	hashFunctions.push_back(djb2);

	BloomFilter bf(1024, hashFunctions);

	// insert words into the filter
	std::vector<std::string> setOfStrings({
		"Hello World!",
		"sweet potato",
		"C++",
		"alpha",
		"beta",
		"gamma"
	});

	std::cout << "Bloom filter created." << std::endl;
	std::cout << "Bloom filter tests for the following set of strings:" << std::endl;

	for (std::vector<std::string>::iterator iter = setOfStrings.begin(); iter != setOfStrings.end(); iter++) {
		bf.addElement(*iter);
		std::cout << "\t" + *iter << std::endl;
	}

	// testing a set of strings against the bloom filter
	std::vector<std::string> testSetOfStrings({
		"Hello World!",
		"sweet potato",
		"C++",
		"alpha",
		"beta",
		"gamma",
		"delta",
		"where am i?",
		"foo",
		"bar"
	});

	std::cout << "Testing set inclusion for the following strings:" << std::endl;
	std::cout << std::boolalpha;

	for (std::vector<std::string>::iterator iter = testSetOfStrings.begin(); iter != testSetOfStrings.end(); iter++) {
		std::cout << "\t" + *iter + ": " << bf.searchElement(*iter) << std::endl;
	}

	return 1;
}