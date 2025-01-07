#include <iostream>

struct Complex {
    double real;
    double imaginary;
};

// Function to add two complex numbers
Complex addComplex(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real + num2.real;
    result.imaginary = num1.imaginary + num2.imaginary;
    return result;
}

// Function to multiply two complex numbers
Complex multiplyComplex(Complex num1, Complex num2) {
    Complex result;
    result.real = (num1.real * num2.real) - (num1.imaginary * num2.imaginary);
    result.imaginary = (num1.real * num2.imaginary) + (num1.imaginary * num2.real);
    return result;
}

int main() {
    Complex num1, num2, sum, product;

    // Input the first complex number
    std::cout << "Enter the real part of the first complex number: ";
    std::cin >> num1.real;
    std::cout << "Enter the imaginary part of the first complex number: ";
    std::cin >> num1.imaginary;

    // Input the second complex number
    std::cout << "Enter the real part of the second complex number: ";
    std::cin >> num2.real;
    std::cout << "Enter the imaginary part of the second complex number: ";
    std::cin >> num2.imaginary;

    // Perform addition and multiplication
    sum = addComplex(num1, num2);
    product = multiplyComplex(num1, num2);

    // Display the results
    std::cout << "Sum of the complex numbers: " << sum.real << " + " << sum.imaginary << "i" << std::endl;
    std::cout << "Product of the complex numbers: " << product.real << " + " << product.imaginary << "i" << std::endl;

    return 0;
}
