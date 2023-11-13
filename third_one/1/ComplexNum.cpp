// ComplexNum.cpp

#include "ComplexNum.hpp"

ComplexNumber::ComplexNumber() : real(0.0), imag(0.0) {}

ComplexNumber::ComplexNumber(double real, double imag) : real(real), imag(imag) {}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const
{
    return ComplexNumber(real + other.real, imag + other.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const
{
    return ComplexNumber(real - other.real, imag - other.imag);
}

ComplexNumber ComplexNumber::operator*(double k) const
{
    return ComplexNumber(real * k, imag * k);
}

std::ostream& operator<<(std::ostream& os, const ComplexNumber& num)
{
    os << num.real << " + " << num.imag << "i";
    return os;
}

