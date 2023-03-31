# Lagrange Interpolation Method

**The Lagrange interpolation method** is a mathematical technique used to estimate the value of a function at a certain point within a given range, based on a set of data points. The method uses a polynomial to approximate the function, and is particularly useful when dealing with discrete data.

## Algorithm

Given a set of data points (x_1, y_1), (x_2, y_2), ..., (x_n, y_n) and a value of x at which to estimate the function, the Lagrange interpolation method works as follows:

1. Define the Lagrange basis polynomials:<br>
    L_k(x) = [(x - x_1) * ... * (x - x_{k-1}) * (x - x_{k+1}) * ... * (x - x_n)] / [(x_k - x_1) * ... * (x_k - x_{k-1}) * (x_k - x_{k+1}) * ... * (x_k - x_n)]

2. Compute the polynomial interpolant:<br>
    P_n(x) = y_1L_1(x) + y_2L_2(x) + ... + y_n*L_n(x)

3. Evaluate the polynomial at the desired value of x to obtain the estimated function value.

## Example

Suppose we are given the following set of data points: (1,2), (2,3), (4,1). We want to estimate the value of the function at x=3.

1. The Lagrange basis polynomials are:<br>
    L_1(x) = (x - 2)(x - 4) / (1 - 2)(1 - 4) = (x^2 - 6x + 8) / 3<br>
    L_2(x) = (x - 1)(x - 4) / (2 - 1)(2 - 4) = -(x^2 - 5x + 4) / 2<br>
    L_3(x) = (x - 1)(x - 2) / (4 - 1)(4 - 2) = (x^2 - 3x + 2) / 3<br>

2. The polynomial interpolant is:<br>
    P_3(x) = 2L_1(x) + 3L_2(x) + 1L_3(x)
    = (2/3)x^2 - (11/3)x + 10

3. Evaluating at x=3, we obtain:<br>
    P_3(3) = (2/3)*3^2 - (11/3)*3 + 10
    = 2

Thus, the estimated value of the function at x=3 is 2.