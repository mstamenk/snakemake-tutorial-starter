from routines.Analysis import loc, parseDatafiles
import matplotlib.pyplot as plt
import numpy as np

import argparse
parser = argparse.ArgumentParser()
parser.add_argument('--mode', default = 'Linear')
parser.add_argument('--show', action = 'store_true')
args = parser.parse_args()

def read_file(filename):
    xaxis = []
    yaxis = []
    for x in open(filename).readlines():
        xaxis.append(int(x.split(' ')[0]))
        yaxis.append(int(x.split(' ')[1]))
    return xaxis, yaxis

name, color = parseDatafiles(args.mode)
filename = loc.RESSOURCE + name
x, y = read_file(filename)

plt.plot(x,y, color)
plt.title(args.mode + ' order plot')

if args.show : plt.show()

save_path = loc.PLOTS + name.replace('.dat','.pdf')
plt.savefig(save_path)
print "Plot saved at %s"%save_path 


