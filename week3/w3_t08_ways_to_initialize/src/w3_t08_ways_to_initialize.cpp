#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;


struct Incognizable {
	int a = 1;
	int b = 2;
};

int main() {
	Incognizable a;
	Incognizable b = { };
	Incognizable c = { 0 };
	Incognizable d = { 0, 1 };
	return 0;
}
