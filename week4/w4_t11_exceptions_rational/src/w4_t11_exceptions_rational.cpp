#include <exception>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
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
		if (denominator == 0) {
			throw invalid_argument("invalid denominator");
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
	return Rational(num, denom);
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
	int num = lhs.Numerator() * rhs.Denominator()
			- rhs.Numerator() * lhs.Denominator();
	int denom = lhs.Denominator() * rhs.Denominator();
	return Rational(num, denom);
}

Rational operator*(const Rational &lhs, const Rational &rhs) {
	int num = lhs.Numerator() * rhs.Numerator();
	int denom = lhs.Denominator() * rhs.Denominator();
	return Rational(num, denom);
}

Rational operator/(const Rational &lhs, const Rational &rhs) {
	if (rhs.Numerator() == 0) {
		throw domain_error("zero division");
	}
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
		cout << "error\n";
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
	try {
		Rational r(1, 0);
		cout << "Doesn't throw in case of zero denominator" << endl;
		return 1;
	} catch (invalid_argument&) {
	}

	try {
		auto x = Rational(1, 2) / Rational(0, 1);
		cout << "Doesn't throw in case of division by zero" << endl;
		return 2;
	} catch (domain_error&) {
	}

	cout << "OK" << endl;
	return 0;
}
