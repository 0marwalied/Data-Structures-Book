#include <bits/stdc++.h>

using namespace std;

class rational {
protected:
	int numerator;
	int denominator;

	void removeAdditionalNumbers() {
		int gcd = __gcd(numerator, denominator);
		numerator /= gcd;
		denominator /= gcd;
	}

	void checkValiedFormat() const {
		if (denominator == 0) throw runtime_error("The denominator shouldn't be equal to zero");
	}

public:

	rational() {
		numerator = 0, denominator = 1;
	}
	rational(int n) {
		numerator = n, denominator = 1;
	}
	rational(int n, int d) {
		numerator = n, denominator = d, checkValiedFormat(), removeAdditionalNumbers();
	}

	//Applying the overloading with int -> adding integer to ration number
	rational operator + (const int &n) {
		return rational{numerator, denominator} + rational{n, 1};
	}

	rational operator + (const rational& r) const {
		return rational(numerator * r.denominator + r.numerator * denominator,
		                denominator * r.denominator);
	}

	void operator += (const rational &rn) {
		numerator = numerator * rn.denominator + rn.numerator * denominator;
		denominator = denominator * rn.denominator;
		removeAdditionalNumbers();
	}

	rational operator * (const rational& r) const {
		return rational(numerator * r.numerator, denominator * r.denominator);
	}

	void operator *= (const rational &rn) {
		numerator *= rn.numerator;
		denominator *= rn.denominator;
		removeAdditionalNumbers();
	}

	rational operator / (const rational& rn) const {
		return rational(numerator * rn.denominator, denominator * rn.numerator);
	}

	void operator /= (const rational &rn) {
		rational res = {rn.denominator, rn.numerator};
		res *= rational{numerator, denominator};
		numerator = res.numerator;
		denominator = res.denominator;
	}

	rational& operator = (const rational& rn) {
		numerator = rn.numerator, denominator = rn.denominator;
		return *this;
	}

	bool operator == (const rational& r) const {
		return numerator * r.denominator == denominator * r.numerator;
	}

	friend ostream& operator << (ostream& os, const rational& r) {
		r.checkValiedFormat();
		os << r.numerator << "/" << r.denominator;
		return os;
	}

	friend istream& operator >> (istream& is, rational& r) {
		is >> r.numerator >> r.denominator;
		r.checkValiedFormat();
		r.removeAdditionalNumbers();
		return is;
	}
};


// Applaying inhertance concept
class Integer: public rational {

public:
	Integer () {
		numerator = 0, denominator = 1;
	}

	Integer(long n) {
		numerator = n, denominator = 1;
	}

	friend ostream& operator<<(ostream& os, const Integer& i) {
		os << i.numerator;
		return os;
	}
};