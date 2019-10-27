#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Rational {
public:
	Rational() {
		num = 0;
		denom = 1;
	}

	Rational(int numerator, int denominator) {
		change(numerator, denominator);
	}

	int Numerator() const {
		return num;
	}

	int Denominator() const {
		return denom;
	}

	void change(int numerator, int denominator) {
		int gcd = GCD_euclid(numerator, denominator);
		numerator /= gcd;
		denominator /= gcd;
		if (denominator < 0) {
			numerator = -numerator;
			denominator = -denominator;
		}
		num = numerator;
		denom = denominator;
	}

private:
	int GCD_euclid(int a, int b) {
		a = abs(a);
		b = abs(b);
		while (a > 0 && b > 0) {
			if (a > b) {
				a = a % b;
			} else {
				b = b % a;
			}
		}
		return a + b;
	}

	int num;
	int denom;
};

bool operator==(const Rational &lhs, const Rational &rhs) {
	return lhs.Numerator() == rhs.Numerator()
			&& lhs.Denominator() == rhs.Denominator();
}

Rational operator+(const Rational &lhs, const Rational &rhs) {
	int num = lhs.Numerator() * rhs.Denominator()
			+ rhs.Numerator() * lhs.Denominator();
	int denom = lhs.Denominator() * rhs.Denominator();
	if (num == 0) {
		denom = 1;
	}
	return Rational(num, denom);
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
	int num = lhs.Numerator() * rhs.Denominator()
			- rhs.Numerator() * lhs.Denominator();
	int denom = lhs.Denominator() * rhs.Denominator();
	if (num == 0) {
		denom = 1;
	}
	return Rational(num, denom);
}

Rational operator*(const Rational &lhs, const Rational &rhs) {
	int num = lhs.Numerator() * rhs.Numerator();
	int denom = lhs.Denominator() * rhs.Denominator();
	if (num == 0) {
		denom = 1;
	}
	return Rational(num, denom);
}

Rational operator/(const Rational &lhs, const Rational &rhs) {
	return Rational(lhs.Numerator() * rhs.Denominator(),
			lhs.Denominator() * rhs.Numerator());
}

ostream& operator<<(ostream &stream, const Rational &r) {
	stream << r.Numerator() << '/' << r.Denominator();
	return stream;
}

istream& operator>>(istream &stream, Rational &r) {
	int num, denom;
	if (!(stream >> num)) {
		return stream;
	}
	if (stream.peek() != '/') {

	}
	stream.ignore(1);
	if (!(stream >> denom)) {
		return stream;
	}
	r.change(num, denom);
	return stream;
}

bool operator<(const Rational &lhs, const Rational &rhs) {
	return lhs.Numerator() * rhs.Denominator()
			< rhs.Numerator() * lhs.Denominator();
}

int main() {

// ============================ PART 1 ============================
	{
		const Rational r(3, 10);
		if (r.Numerator() != 3 || r.Denominator() != 10) {
			cout << "Rational(3, 10) != 3/10" << endl;
			return 1;
		}
	}

	{
		const Rational r(8, 12);
		if (r.Numerator() != 2 || r.Denominator() != 3) {
			cout << "Rational(8, 12) != 2/3" << endl;
			return 2;
		}
	}

	{
		const Rational r(-4, 6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(-4, 6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(4, -6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(4, -6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(0, 15);
		if (r.Numerator() != 0 || r.Denominator() != 1) {
			cout << "Rational(0, 15) != 0/1" << endl;
			return 4;
		}
	}

	{
		const Rational defaultConstructed;
		if (defaultConstructed.Numerator() != 0
				|| defaultConstructed.Denominator() != 1) {
			cout << "Rational() != 0/1" << endl;
			return 5;
		}
	}

// ============================ PART 2 ============================
	{
		Rational r1(4, 6);
		Rational r2(2, 3);
		bool equal = r1 == r2;
		if (!equal) {
			cout << "4/6 != 2/3" << endl;
			return 1;
		}
	}

	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a + b;
		bool equal = c == Rational(2, 1);
		if (!equal) {
			cout << "2/3 + 4/3 != 2" << endl;
			return 2;
		}
	}

	{
		Rational a(5, 7);
		Rational b(2, 9);
		Rational c = a - b;
		bool equal = c == Rational(31, 63);
		if (!equal) {
			cout << "5/7 - 2/9 != 31/63" << endl;
			return 3;
		}
	}

// ============================ PART 3 ============================
	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a * b;
		bool equal = c == Rational(8, 9);
		if (!equal) {
			cout << "2/3 * 4/3 != 8/9" << endl;
			return 1;
		}
	}

	{
		Rational a(5, 4);
		Rational b(15, 8);
		Rational c = a / b;
		bool equal = c == Rational(2, 3);
		if (!equal) {
			cout << "5/4 / 15/8 != 2/3" << endl;
			return 2;
		}
	}

// ============================ PART 4 ============================
	{
		ostringstream output;
		output << Rational(-6, 8);
		if (output.str() != "-3/4") {
			cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
			return 1;
		}
	}

	{
		istringstream input("5/7");
		Rational r;
		input >> r;
		bool equal = r == Rational(5, 7);
		if (!equal) {
			cout << "5/7 is incorrectly read as " << r << endl;
			return 2;
		}
	}

	{
		istringstream input("5/7 10/8");
		Rational r1, r2;
		input >> r1 >> r2;
		bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Multiple values are read incorrectly: " << r1 << " " << r2
					<< endl;
			return 3;
		}

		input >> r1;
		input >> r2;
		correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Read from empty stream shouldn't change arguments: " << r1
					<< " " << r2 << endl;
			return 4;
		}
	}

// ============================ PART 5 ============================
	{
		const set<Rational> rs = { { 1, 2 }, { 1, 25 }, { 3, 4 }, { 3, 4 }, { 1,
				2 } };
		if (rs.size() != 3) {
			cout << "Wrong amount of items in the set" << endl;
			return 1;
		}

		vector<Rational> v;
		for (auto x : rs) {
			v.push_back(x);
		}
		if (v != vector<Rational> { { 1, 25 }, { 1, 2 }, { 3, 4 } }) {
			cout << "Rationals comparison works incorrectly" << endl;
			return 2;
		}
	}

	{
		map<Rational, int> count;
		++count[ { 1, 2 }];
		++count[ { 1, 2 }];

		++count[ { 2, 3 }];

		if (count.size() != 2) {
			cout << "Wrong amount of items in the map" << endl;
			return 3;
		}
	}

	cout << "OK" << endl;
	return 0;
}
