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
