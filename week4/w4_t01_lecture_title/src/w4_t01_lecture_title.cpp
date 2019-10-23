#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct Specialization {
	explicit Specialization(string s) {
		value = s;
	}

	string value;
};

struct Course {
	explicit Course(string s) {
		value = s;
	}

	string value;
};

struct Week {
	explicit Week(string s) {
		value = s;
	}

	string value;
};


struct LectureTitle {
	LectureTitle(Specialization s, Course c, Week w) {
		specialization = s.value;
		course = c.value;
		week = w.value;
	}

	string specialization;
	string course;
	string week;
};

int main() {
	// allowed
	LectureTitle title(Specialization("C++"), Course("White belt"),
			Week("4th"));

	// not allowed
//	LectureTitle title("C++", "White belt", "4th");
//
//	LectureTitle title(string("C++"), string("White belt"), string("4th"));
//
//	LectureTitle title = {"C++", "White belt", "4th"};
//
//	LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};
//
//	LectureTitle title(
//	    Course("White belt"),
//	    Specialization("C++"),
//	    Week("4th")
//	);
//
//	LectureTitle title(
//	    Specialization("C++"),
//	    Week("4th"),
//	    Course("White belt")
//	);

	return 0;
}
