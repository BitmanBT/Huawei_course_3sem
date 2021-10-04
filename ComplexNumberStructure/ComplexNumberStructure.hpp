#ifndef COMPLEXNUMBERSTRUCTURE_HPP_INCLUDED
#define COMPLEXNUMBERSTRUCTURE_HPP_INCLUDED

struct ComplexNumber {
    double real_part;
    double imaginary_part;

    ~ComplexNumber();

    ComplexNumber();
    ComplexNumber(double real_part_new, double imaginary_part_new);
    ComplexNumber(const ComplexNumber& another);

    ComplexNumber operator+ (const ComplexNumber &other) const;
    ComplexNumber operator- (const ComplexNumber &other) const;
    ComplexNumber operator* (const ComplexNumber &other) const;
    ComplexNumber operator/ (const ComplexNumber &other) const;
    ComplexNumber& operator+= (const ComplexNumber &other);
    ComplexNumber& operator-= (const ComplexNumber &other);
    ComplexNumber& operator*= (const ComplexNumber &other);
    ComplexNumber& operator/= (const ComplexNumber &other);
    ComplexNumber& operator= (const ComplexNumber &other);
    bool operator== (const ComplexNumber &other) const;

    ComplexNumber operator* (double &other) const;
    ComplexNumber operator/ (double &other) const;
    ComplexNumber& operator*= (double &other);
    ComplexNumber& operator/= (double &other);

    ComplexNumber& operator- () const;

    void print() const;
    double abs() const;
    double argument() const;
};

#endif // COMPLEXNUMBERSTRUCTURE_HPP_INCLUDED
