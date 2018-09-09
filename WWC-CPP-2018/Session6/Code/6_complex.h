class Complex
{
public:
        Complex(double re,double im)
                :real{re},imag{im}
                {};
        Complex operator+(const Complex& other);
        Complex operator=(const Complex& other);
private:
        double real;
        double imag;
};

Complex Complex::operator+(const Complex&  other)
{
    double result_real = real + other.real;
    double result_imaginary = imag + other.imag;
    return Complex( result_real, result_imaginary );
}

int main()
{
    Complex a{1.0, 2.0};
    Complex b{1.0, 2.0};
    Complex c = a + b;
    //Complex c= a.operator+(b);
}