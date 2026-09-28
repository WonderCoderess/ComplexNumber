# Complex Number Calculator

This is a small C++ project for a programming course. The program lets the user enter two complex numbers and shows the results of basic calculations.

## What the program does

- Adds, subtracts, multiplies, and divides two complex numbers.
- Creates a third number by copying the first one.
- Displays numbers in the form `a + bi` or `a - bi`.
- Asks again if the user enters something that is not a number.
- Shows an error message when the user tries to divide by `0 + 0i`.
- Stops with a message if input ends.

## C++ topics used

- Classes and private fields.
- Constructors and a copy constructor.
- Operator overloading (`+`, `-`, `*`, `/`, and `<<`).
- A default copy assignment operator (`=`).
- Checking user input.
- Handling errors with `try` and `catch`.

## How to run

1. Open `ComplexNumber.slnx` in Visual Studio with C++ tools installed. If the solution file does not open, try `ComplexNumber/ComplexNumber.vcxproj`.
2. Press **Ctrl+F5** to build and run the program.
3. Enter the real and imaginary parts of the first number.
4. Enter the real and imaginary parts of the second number.

Enter one value at a time and press Enter after each value. Use a dot for decimal numbers, for example `2.5`.

## Example

To use `2 + 3i` as both numbers, enter `2`, `3`, `2`, and `3`, each on a separate line.

The third number is a copy of the first: `2 + 3i`.

The calculation results are:

```text
cn1 + cn2 = 4 + 6i
cn1 - cn2 = 0 + 0i
cn1 * cn2 = -5 + 12i
cn1 / cn2 = 1 + 0i
```

## Error handling

The program rejects empty input and entries such as `abc`, `12abc`, or `12 34`. It displays:

```text
Invalid input. Please enter a number.
```

Division is not allowed when both parts of the second number are zero. In this case, the program displays:

```text
cn1 / cn2 = Division by zero complex number.
```

## Limitations and ideas for improvement

Very large or very small numbers can give incorrect results because of the limits of the `double` type and the formulas used.

Possible improvements:

- Improve division for very large and very small numbers.

## Code

The program is in [main.cpp](ComplexNumber/main.cpp).
