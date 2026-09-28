#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

using namespace std;

class ComplexNumber
{

public:
    ComplexNumber(double r = 0, double i = 0)
        : real(r), imaginary(i)
    {
    }

    ComplexNumber(const ComplexNumber& other)
        : real(other.real), imaginary(other.imaginary)
    {
    }

    // Operators overloading
    friend ostream& operator<<(ostream& out, const ComplexNumber& number);
    ComplexNumber operator+(const ComplexNumber& other) const;
    ComplexNumber operator-(const ComplexNumber& other) const;
    ComplexNumber operator*(const ComplexNumber& other) const;
    ComplexNumber operator/(const ComplexNumber& other) const;
    ComplexNumber& operator=(const ComplexNumber& other) = default;

private:
    double real; // real part of the complex number
    double imaginary; // imaginary part of the complex number

};

double getNumber(const string& message);

int main()
{
    try
    {
        double realPart = getNumber("Enter real part of the first number: ");
        double imaginaryPart = getNumber("Enter imaginary part of the first number: ");

        ComplexNumber cn1(realPart, imaginaryPart);

        realPart = getNumber("Enter real part of the second number: ");
        imaginaryPart = getNumber("Enter imaginary part of the second number: ");

        ComplexNumber cn2(realPart, imaginaryPart);
        ComplexNumber cn3(cn1); // copy constructor

        cout << endl;
        cout << "The first number you chose is: " << cn1 << endl;
        cout << "The second number you chose is: " << cn2 << endl;
        cout << "The third number, created using the copy constructor, is: " << cn3 << endl;
        cout << endl;
        cout << "The results of basic operations (+, -, *, /) on your chosen complex numbers are:" << endl;
        cout << "cn1 + cn2 = " << cn1 + cn2 << endl;
        cout << "cn1 - cn2 = " << cn1 - cn2 << endl;
        cout << "cn1 * cn2 = " << cn1 * cn2 << endl;

        // Handle division by a complex number whose real and imaginary parts are both zero.
        try
        {
            ComplexNumber divisionResult = cn1 / cn2;
            cout << "cn1 / cn2 = " << divisionResult << endl;
        }
        catch (const domain_error& error)
        {
            cout << "cn1 / cn2 = " << error.what() << endl;
        }
        cout << endl;
        return 0;
    }
    catch (const runtime_error& error)
    {
        cerr << error.what() << endl;
        return 1;
    }
}

// Read a full line and repeat until it contains a single number.
// Throws runtime_error if input ends or cannot be read.
double getNumber(const string& message)
{
    string line;

    while (true)
    {
        cout << message;

        if (!getline(cin, line))
        {
            throw runtime_error("Input ended or could not be read.");
        }

        istringstream input(line);
        double value;
        char extra;

        if ((input >> value) && !(input >> extra))
        {
            return value;
        }

        cout << "Invalid input. Please enter a number.\n";
    }
}


// Overload the << operator for ComplexNumber class
// in case of negative imaginary part, it will be displayed as "a - bi" instead of "a + -bi"

ostream& operator<<(ostream& out, const ComplexNumber& number)
{
    out << number.real;

    if (number.imaginary >= 0)
    {
        out << " + " << number.imaginary << "i";
    }
    else
    {
        out << " - " << -number.imaginary << "i";
    }

    return out;
}

// Overload the + operator for ComplexNumber class
// (a + bi) + (c + di) = (a + c) + (b + d)i
ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const
{
    double newReal = real + other.real;
    double newImaginary = imaginary + other.imaginary;

    return ComplexNumber(newReal, newImaginary);
}

// Overload the - operator for ComplexNumber class
// (a + bi) - (c + di) = (a - c) + (b - d)i
ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const
{
    double newReal = real - other.real;
    double newImaginary = imaginary - other.imaginary;

    return ComplexNumber(newReal, newImaginary);
}

// Overload the * operator for ComplexNumber class
// (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const
{
    double newReal = real * other.real - imaginary * other.imaginary;
    double newImaginary = real * other.imaginary + imaginary * other.real;

    return ComplexNumber(newReal, newImaginary);
}

// Overload the / operator for ComplexNumber class
// (a + bi) / (c + di) = ((ac + bd) + (bc - ad)i) / (c^2 + d^2)
// Throws domain_error when the divisor is zero (0 + 0i).
ComplexNumber ComplexNumber::operator/(const ComplexNumber& other) const
{
    double denominator = other.real * other.real + other.imaginary * other.imaginary;

    if (other.real == 0.0 && other.imaginary == 0.0)
    {
        throw domain_error("Division by zero complex number.");
    }

    double newReal = (real * other.real + imaginary * other.imaginary) / denominator;
    double newImaginary = (imaginary * other.real - real * other.imaginary) / denominator;

    return ComplexNumber(newReal, newImaginary);
}
