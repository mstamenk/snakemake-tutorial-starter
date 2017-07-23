# Python script to handle the informations relative to the analysis.
#
# Author: Marko Stamenkovic
# Site: https://mstamenk.github.io
# Mail: stamenkovim@gmail.com
#
# This file is part of the Snakemake Tutorial for data analysts
# Please visit: https://mstamenk.github.io/2017/07/snakemake-tutorial-for-data-analysts.html
# for more informations.

import os

NAME = 0
COLOR = 1


class loc : pass
loc.CPP = os.getenv("CPP") + '/'
loc.CPPSRC = os.getenv("CPPSRC") + '/'
loc.PYTHON = os.getenv("PYTHON") + '/'
loc.ROUTINES = os.getenv("ROUTINES") + '/'
loc.RESSOURCE = os.getenv("RESSOURCE") + '/'
loc.PLOTS = os.getenv("PLOTS") + '/'
loc.SCRIPTS = os.getenv("SCRIPTS") + '/'

dataID = { 'Zero'   : ['Zero_forPlotting.dat',  'b'],
           'Linear' : ['Linear_forPlotting.dat','c'],
           'Square' : ['Square_forPlotting.dat','m'],
           'Cubic'  : ['Cubic_forPlotting.dat', 'k' ]}


def parseDatafiles(dtype): 
    return dataID[dtype][NAME],dataID[dtype][COLOR]


