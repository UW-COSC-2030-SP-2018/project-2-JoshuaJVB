#include<string>
#include<vector>
#include<iostream>

using std::string;
using std::vector;
using std::cin;
using std::cout;

typedef unsigned int(*HashFunction)(std::string);

class BloomFilter {
	unsigned int numberOfCells;
	unsigned int numberOfFunctions;
	bool* cell;
	std::vector<HashFunction> hashFunctions;

public:

	BloomFilter(unsigned int numbCells, std::vector<HashFunction> funcs) : numberOfCells(numbCells), hashFunctions(funcs) {
		cell = (bool*)calloc(numbCells, sizeof(bool));
	}

	void addElement(std::string str) {
		for (std::vector<HashFunction>::iterator iter = hashFunctions.begin(); iter != hashFunctions.end(); iter++) {
			cell[(*iter)(str) % numberOfCells] = true;
		}
	}

	bool searchElement(std::string str) {
		bool strInSet = true;

		for (std::vector<HashFunction>::iterator iter = hashFunctions.begin(); iter != hashFunctions.end(); iter++) {
			if (cell[(*iter)(str) % numberOfCells] == false) {
				strInSet = false;
				break;
			}
		}

		return strInSet;
	}

	~BloomFilter() {
		free(cell);
		cell = NULL;
	}
};
