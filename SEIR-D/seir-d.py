import numpy as np

# определяем параметры модели
alpha_E = 0.999
alpha_I = 0.999
kappa = 0.042
rho = 0.952
beta = 0.999
mu = 0.0188
c_isol = 0
E_0 = 99
R_0 = 24
N0 = 2798170

# определяем начальные данные
S_0 = N0 - E_0 - R_0
I_0 = 0
D_0 = 0
t_0 = 0

# определяем функцию для расчета c(t)
def c(t):
    a_t = np.sin(np.pi * (t - 35) / 35) if t < 70 else 0
    return 1 + c_isol * (1 - 2/5 * a_t)

# определяем функцию правых частей системы уравнений
def f(t, Y):
    S, E, I, R, D = Y
    N = S + E + I + R + D
    c_t = c(t)
    dSdt = -c_t * (alpha_I * S * I / N + alpha_E * S * E / N)
    dEdt = c_t * (alpha_I * S * I / N + alpha_E * S * E / N) - (kappa + rho) * E
    dIdt = kappa * E - beta * I - mu * I
    dRdt = beta * I + rho * E
    dDdt = mu * I
    return np.array([dSdt, dEdt, dIdt, dRdt, dDdt])

# определяем функцию метода Эйлера
def euler_method(f, t_0, Y_0, h, t_max):
    t = t_0
    Y = Y_0
    solution = [(t, Y)]
    while t < t_max:
        Y = Y + h * f(t, Y)
        t = t + h
        solution.append((t, Y))
    return solution

# находим решение системы уравнений
solution = euler_method(f, t_0, [S_0, E_0, I_0, R_0, D_0], 0.0001, 90)

# выводим результаты
for t, Y in solution:
    print("t = {:.2f}, S = {:.2f}, E = {:.2f}, I = {:.2f}, R = {:.2f}, D = {:.2f}".format(t, *Y))
