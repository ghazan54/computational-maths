# Fixed Point Iteration for Solving Linear Systems

**The fixed point iteration method** is an iterative algorithm used for solving linear systems of equations in the form Ax = b. In this method, we rewrite the system of equations as x = Cx + d, where C is a square matrix with coefficients derived from A, and d is a vector derived from b.

## Algorithm

1. Given a system of linear equations Ax = b, where A is the coefficient matrix, b is the right-hand side vector, and x is the vector of unknowns.
2. Rewrite the system as x = Cx + d, where C is the iteration matrix and d is the constant vector.
3. Set an initial guess for x.
4. Iterate using x_k = Cx_k-1 + d until the solution converges, where x_k is the vector of unknowns at iteration k.
5. The solution x is the converged value of x_k.

## Example

Let's say we have the following system of linear equations:

3x + y - z = 7
2x - 5y + 3z = -12
x + y + z = 6

We can rewrite this system in matrix form as Ax = b, where:

A = [[3, 1, -1], [2, -5, 3], [1, 1, 1]]
x = [x, y, z]
b = [7, -12, 6]

To use the fixed point iteration method, we need to rewrite the system as x = Cx + d. To do this, we can isolate x in each equation:

x = (7 - y + z)/3
x = (-12 - 3z + 5y)/2
x = 6 - y - z

Now we have:

C = [[0, -1/3, 1/3], [-5/2, 0, 3/2], [-1, -1, 0]]
d = [7/3, 6, 6]

Let's start with an initial guess for x, say [0, 0, 0]. Then we can iterate using the formula x_k = Cx_k-1 + d until the solution converges:

Iteration 1: x_1 = [[0, 0, 0]] * C + [7/3, 6, 6] = [7/3, 6, 6]<br>
Iteration 2: x_2 = [[7/3, 6, 6]] * C + [7/3, 6, 6] = [5.6667, 5.5, 4.6667]<br>
Iteration 3: x_3 = [[5.6667, 5.5, 4.6667]] * C + [7/3, 6, 6] = [4.7778, 3.6944, 4.8889]<br>
Iteration 4: x_4 = [[4.7778, 3.6944, 4.8889]] * C + [7/3, 6, 6] = [4.962, 3.9945, 4.9985]<br>
Iteration 5: x_5 = [[4.962, 3.9945, 4.9985]] * C + [7/3, 6, 6] = [4.9982, 4.0006, 5.0001]<br>
Iteration 6: x_6 = [[4.9982, 4.0006, 5.0001]] * C + [7/3, 6, 6] = [4.9999, 4.0001, 5.0000]<br>
Iteration 7: x_7 = [[4.9999, 4.0001, 5.0000]] * C + [7/3, 6, 6] = [5.0000, 4.0000, 5.0000]<br>

We can see that the solution converges to x = [5, 4, 5].
