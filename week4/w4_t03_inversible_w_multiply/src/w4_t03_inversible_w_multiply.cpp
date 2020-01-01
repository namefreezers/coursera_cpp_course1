#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

class FunctionPart {
public:
	FunctionPart(char new_op, double new_val) {
		op = new_op;
		val = new_val;
	}

	void Invert() {
		if (op == '+') {
			op = '-';
		} else if (op == '-') {
			op = '+';
		} else if (op == '*') {
			op = '/';
		} else if (op == '/') {
			op = '*';
		}
	}

	double Apply(double input_val) const {
		if (op == '+') {
			return input_val + val;
		} else if (op == '-') {
			return input_val - val;
		} else if (op == '*') {
			return input_val * val;
		} else if (op == '/') {
			return input_val / val;
		} else {
			throw runtime_error("not allowed op");
		}
	}

private:
	char op;
	double val;
};

class Function {
public:
	void AddPart(char op, double val) {
		parts.push_back( { op, val });
	}

	double Apply(double value) const {
		for (const FunctionPart &p : parts) {
			value = p.Apply(value);
		}
		return value;
	}

	void Invert() {
		for (FunctionPart &p : parts) {
			p.Invert();
		}
		reverse(begin(parts), end(parts));
	}

private:
	vector<FunctionPart> parts;
};

struct Image {
	double quality;
	double freshness;
	double rating;
};

struct Params {
	double a;
	double b;
	double c;
};

Function MakeWeightFunction(const Params &params, const Image &image) {
	Function function;
	function.AddPart('*', params.a);
	function.AddPart('-', image.freshness * params.b);
	function.AddPart('+', image.rating * params.c);
	return function;
}

double ComputeImageWeight(const Params &params, const Image &image) {
	Function function = MakeWeightFunction(params, image);
	return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params &params, const Image &image,
		double weight) {
	Function function = MakeWeightFunction(params, image);
	function.Invert();
	return function.Apply(weight);
}

int main() {
	Image image = { 10, 2, 6 };
	Params params = { 4, 2, 6 };
	cout << ComputeImageWeight(params, image) << endl;
	cout << ComputeQualityByWeight(params, image, 52) << endl;
	return 0;
}
