# Gaussian Elimination Method

**The Gaussian elimination method** is a popular numerical method for solving systems of linear equations. It is a simple algorithm that transforms the augmented matrix of the system into row echelon form and then back-substitutes to find the solutions.

## How it Works

Given a system of linear equations:

```
a11*x1 + a12*x2 + ... + a1n*xn = b1
a21*x1 + a22*x2 + ... + a2n*xn = b2
.
.
.
an1*x1 + an2*x2 + ... + ann*xn = bn
```

We can represent this system as a matrix equation Ax=b where A is the coefficient matrix, x is the vector of unknowns, and b is the vector of constants:

```
[ a11 a12 ... a1n ][ x1 ]   [ b1 ]
| a21 a22 ... a2n || x2 | = | b2 |
| .            .  || .  |   | .  |
| .            .  || .  |   | .  |
| .            .  || .  |   | .  |
[ an1 an2 ... ann ][ xn ]   [ bn ]
```

To solve this system using Gaussian elimination, we perform a sequence of row operations on the matrix A until it is transformed into row echelon form. Row echelon form is a special form of the matrix in which the leading coefficient (i.e., the first non-zero element) of each row is strictly to the right of the leading coefficient of the row above it. Additionally, all rows consisting entirely of zeros are at the bottom of the matrix.

Once A has been transformed into row echelon form, we can solve for the unknowns by back-substitution. We start with the last equation and solve for xn, then substitute that value into the second-to-last equation and solve for xn-1, and so on until we have solved for all of the unknowns.


## Algorithm

1. Create the augmented matrix of the system.
2. For each row:
    1. Choose the pivot element (the leftmost non-zero element).
    2. If the pivot element is zero, swap the current row with a lower row that has a non-zero pivot element.
    3. Divide the pivot row by the pivot element to make the pivot element equal to 1.
    4. For each row below the pivot row, subtract a multiple of the pivot row to make the pivot column elements zero.
3. Back-substitute to find the solutions.

## Example

Let's solve the following system of linear equations using Gaussian elimination:

```
3x + 2y - z = 1
2x - 2y + 4z = -2
-x + 1/2y - z = 0
```

The augmented matrix of the system is:

```
[ 3  2 -1 |  1 ]
[ 2 -2  4 | -2 ]
[-1  1/2 -1 |  0 ]
```

We start by choosing the pivot element in the first row and dividing the row by the pivot element:

```
[ 1  2/3 -1/3 |  1/3 ]
[ 2 -2  4 | -2 ]
[-1  1/2 -1 |  0 ]
```

Then, we subtract twice the first row from the second row to make the pivot column element zero:

```
[ 1  2/3 -1/3 |  1/3 ]
[ 0 -8/3 10/3 | -8/3 ]
[-1  1/2 -1 |  0 ]
```

We choose the pivot element in the third row and divide the row by the pivot element:

```
[ 1  2/3 -1/3 |  1/3 ]
[ 0 -8/3 10/3 | -8/3 ]
[ 0  5/6 -2/3 | -1/3 ]
```

Then, we subtract 5/6 times the second row from the third row to make the pivot column element zero:

```
[ 1  2/3 -1/3 |  1/3 ]
[ 0 -8/3 10/3 | -8/3 ]
[ 0  0 -7 | -2 ]
```

Finally, we back-substitute to find the solutions:

```
z = 2/7
y = 1/3
x = -1/7
```

Therefore, the solution of the system is (x, y, z) = (-1/7, 1/3, 2/7).
