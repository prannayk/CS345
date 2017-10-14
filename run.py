import numpy as np
import subprocess as sb
import sys
j = int(sys.argv[1])
t = np.zeros([100])
for i in range(100):
	proc = sb.Popen("./naive < f%d/input%d.txt"%(j,i),shell=True, stdout=sb.PIPE)
	print(i)
	o,e = proc.communicate()
	if e != None :
		raise ValueError("Crashed")
	else :
		t[i] = float(o)
np.save(str(j),t)
