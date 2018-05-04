#include <vector>
#include <functional>
#include <string>

using std::vector;
using std::hash;
using std::string;

template <class T>

int binSearch(vector<T> t1, T t2, int loop) {
	int counter = 0;
	if(t1.size() > 1){
		for (int x = 0; x < (t1.size() / 2); x++) {
			if (t2 == t1[x]) {
				return x + loop;
			}
			counter++;
		}
	}
	else {
		if (t1[0] == t2) {
			return (loop + 1);
		}
		return -1;
	}
	loop = loop + counter;
	vector<T> tempVec;
	for (int x = t1.size() / 2; x < t1.size(); x++) {
		tempVec.push_back(t1[x]);
	}
	return binSearch(tempVec, t2, loop);
}

template <class T>

vector<T> QuickSort(vector<T>& vec1, vector<T>& vec2) {
	vector <T> vecTemp = vec1;
	int right = vecTemp.size();
	int left = 0;
	int mid = right / 2;

	for (int x = 0; x < 10; x++) {
		vecTemp = qSort(vecTemp, left, right);
		vecTemp = qSort(vecTemp, left, mid);
		vecTemp = qSort(vecTemp, mid, right);
	}


	vec2 = vecTemp;

	return vec2;
}

template <class T>

vector<T> qSort(vector <T> vec, int L, int R) {
	int pivot = (R + L) / 2;
	vector<T> vecLow;
	vector<T> vecHigh;
	vector<T> vecCopy = vec;
	vec = {};

	if (L > 0) {
		for (int x = 0; x < L; x++) {
			vec.push_back(vecCopy[x]);
		}
	}

	for (int x = L; x < pivot; x++) {
		if (vecCopy[x] < vecCopy[pivot]) {
			vecLow.push_back(vecCopy[x]);
		}
		else if (vecCopy[x] > vecCopy[pivot]) {
			vecHigh.push_back(vecCopy[x]);
		}
	}

	for (int x = pivot; x < R; x++) {
		if (vecCopy[x] < vecCopy[pivot]) {
			vecLow.push_back(vecCopy[x]);
		}
		else if (vecCopy[x] > vecCopy[pivot]) {
			vecHigh.push_back(vecCopy[x]);
		}
	}

	for (int x = 0; x < vecLow.size(); x++) {
		vec.push_back(vecLow[x]);
	}
	vec.push_back(vecCopy[pivot]);
	for (int x = 0; x < vecHigh.size(); x++) {
		vec.push_back(vecHigh[x]);
	}

	if (R < vecCopy.size()) {
		for (int x = R; x < vecCopy.size(); x++) {
			vec.push_back(vecCopy[x]);
		}
	}

	return vec;
}

template <class T>
void mergeSort(vector<T>& t, int low, int high) {
	int mid;
	if (low<high)
	{
		mid = low + (high - low) / 2; //This avoids overflow when low, high are too large
		mergeSort(t, low, mid);
		mergeSort(t, mid + 1, high);
		merge(t, low, mid, high);
	}
}
template <class T>
void merge(vector<T>& t, int low, int mid, int high) {
	int h, i, j, k;
	vector<T> temp = t;

	h = low;
	i = low;
	j = mid + 1;

	while ((h <= mid) && (j <= high))
	{
		if (t[h] <= t[j])
		{
			temp[i] = t[h];
			h++;
		}
		else
		{
			temp[i] = t[j];
			j++;
		}
		i++;
	}
	if (h>mid)
	{
		for (k = j; k <= high; k++)
		{
			temp[i] = t[k];
			i++;
		}
	}
	else
	{
		for (k = h; k <= mid; k++)
		{
			temp[i] = t[k];
			i++;
		}
	}
	for (k = low; k <= high; k++) t[k] = temp[k];
}

static int hashing(string s) {
	hash<string> str_hash;
	return str_hash(s);
}

static int hashing(int i) {
	hash<int> int_hash;
	return int_hash(i);
}