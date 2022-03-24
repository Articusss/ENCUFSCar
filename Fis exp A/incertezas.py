from cmath import pi
from uncertainties import ufloat
N=ufloat(7.80,0.06)
Vt=ufloat(1.3,0.2)
V= N/Vt
print('Incerteza da densidade 1')
print('V = {:.2u} '.format(V))

T =ufloat(1.40, 0.01)
L = ufloat(0.5, 0.03)
g = pow((2 * 3.14/ T) ,2) * L
print('g = {:.2u}'.format(g))