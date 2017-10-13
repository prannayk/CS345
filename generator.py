import numpy as np
import sys
n = int(sys.argv[1])
fil = str(sys.argv[2])
for i in range(100):
	t = '%d\n'%(n)
	x = np.random.normal(0,10, [n])
	y = np.random.normal(0,10, [n])
	for j in range(n):
		t += '%f %f\n'%(x[j],y[j])
	with open("%s/input%d.txt"%(fil,i), mode="w") as f:
		f.write(t)
