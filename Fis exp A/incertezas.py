from cmath import pi
from uncertainties import ufloat
N=ufloat(7.80,0.06)
Vt=ufloat(1.3,0.2)
V= N/Vt
print('Incerteza da densidade 1')
print('V = {:.2u} ml'.format(V))

N=ufloat(25.10,0.03)
Vt=ufloat(2.2,0.03)
V= pi * (N/2) * (N/2) * Vt;
print('Incerteza do volume ')
print('V = {:.2u} ml'.format(V))

N=ufloat(7.80,0.06)
Vt=ufloat(1.1,0.2)
V= N/Vt
print('Incerteza da densidade 2')
print('V = {:.2u} ml'.format(V))