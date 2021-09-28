#include <iostream>
#include <cmath>
#include <cassert>

#define _USE_MATH_DEFINES

struct ComplexNumber {
    double real_part_;
    double imaginary_part_;

    ComplexNumber();
    ComplexNumber(double real_part, double imaginary_part);
    ComplexNumber(const ComplexNumber& another);

    ComplexNumber operator+ (const ComplexNumber &other) const;
    ComplexNumber operator- (const ComplexNumber &other) const;
    ComplexNumber operator* (const ComplexNumber &other) const;
    ComplexNumber operator/ (const ComplexNumber &other) const;
    ComplexNumber operator= (const ComplexNumber &other);
    ComplexNumber operator+= (const ComplexNumber &other);
    ComplexNumber operator-= (const ComplexNumber &other);
    bool operator== (const ComplexNumber &other);

    ComplexNumber operator+ (const double &other) const;
    ComplexNumber operator- (const double &other) const;
    ComplexNumber operator* (const double &other) const;
    ComplexNumber operator/ (const double &other) const;
    ComplexNumber operator= (const double &other);
    ComplexNumber operator+= (const double &other);
    ComplexNumber operator-= (const double &other);
    bool operator== (const double &other);

    //double operator+ (const ComplexNumber &other) const;

    void print() const;
    double abs() const;
    double argument() const;
};

void TestDefaultConstructor();

void TestConstructor();

void TestCopyConstructor();

void TestOperatorPlus();

void TestOperatorMinus();

void TestOperatorStar();

void TestOperatorSlash();

void TestOperatorEqual();

void TestOperatorIncrease();

void TestOperatorDecrease();

void TestOperatorCheckEqual();

void TestOperatorPlusDouble();

void TestOperatorMinusDouble();

void TestOperatorStarDouble();

void TestOperatorSlashDouble();

void TestOperatorEqualDouble();

void TestOperatorIncreaseDouble();

void TestOperatorDecreaseDouble();

void TestOperatorCheckEqualDouble();

void TestAbs();

void TestArgument();

//void TestOperatorPlusDoubleReversed();
