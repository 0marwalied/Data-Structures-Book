#include <iostream>
#include <algorithm>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

struct rational {
	int numerator;
	int denominator;

	rational() {}
	rational(int n, int d) {
		numerator = n, denominator = d, checkValiedFormat();
	}

	void removeAdditionalNumbers() {
		int gcd = __gcd(numerator, denominator);
		numerator /= gcd;
		denominator /= gcd;
	}

	rational operator + (const rational &ra) {
		rational res;
		res.numerator = numerator * ra.denominator + ra.numerator * denominator;
		res.denominator = denominator * ra.denominator;
		res.removeAdditionalNumbers();
		return res;
	}

	void operator += (const rational &rn) {
		numerator = numerator * rn.denominator + rn.numerator * denominator;
		denominator = denominator * rn.denominator;
		removeAdditionalNumbers();
	}

	rational operator * (const rational &rn) {
		rational res;
		res.numerator = numerator * rn.numerator;
		res.denominator = denominator * rn.denominator;
		res.removeAdditionalNumbers();
		return res;
	}

	void operator *= (const rational &rn) {
		numerator *= rn.numerator;
		denominator *= rn.denominator;
		removeAdditionalNumbers();
	}

	bool operator == (const rational &ra) {
		return numerator * ra.denominator == denominator * ra.numerator;
	}

	friend void operator<<(ostream& os, const rational& r) {
		os << r.numerator << "/" << r.denominator;
	}

	friend void operator>>(istream& is, rational& r) {
		is >> r.numerator >> r.denominator;
		r.checkValiedFormat();
	}

	void checkValiedFormat() {
		if (denominator == 0) throw runtime_error("The denominator shouldn't be equal to zero");
	}
};