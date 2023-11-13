#ifndef COMPLEXNUM_HPP
#define COMPLEXNUM_HPP

#include <iostream>
#include <cmath>

class ComplexNumber
{
private:
    double real;
    double imag;

public:
    ComplexNumber();
    ComplexNumber(double real, double imag);
  
    ComplexNumber operator+(const ComplexNumber& other) const;
    ComplexNumber operator-(const ComplexNumber& other) const;
    ComplexNumber operator*(double k) const;

    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& num);
};

