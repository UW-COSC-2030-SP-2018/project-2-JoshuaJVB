#include <vector>

using std::vector;

template <class T, class T2>

int binSearch(vector<T> t1, T2 t2, int loop) {
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