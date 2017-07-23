# BASH script to setup the working environment and to activate snakemake or not
# 
# Author: Marko Stamenkovic
# Site: https://mstamenk.github.io
# Mail: stamenkovim@gmail.com
#
# This is part of the Snakemake Tutorial for data analysts
# Please visit: https://mstamenk.github.io/2017/07/snakemake-tutorial-for-data-analysts.html
# for more informations

# The script can be used to set the snakemake environment or not
if [ "$1" = "snake" ]; then
    echo "Setup with snakemake using python3"
    source activate snake  
else 
    echo "Setup without snakemake using python2"
    source scripts/setup_path.sh
fi
# Definition of various path in the architecture of the project
export CPP=$PWD/cpp
export CPPSRC=$CPP/src

export TUTO=$PWD
export SCRIPTS=$PWD/scripts

export PYTHON=$PWD/python

export RESSOURCE=$PWD/ressource
export ROUTINES=$PWD/routines

# User-sensitive way to define your project, define the folders that are not the same from one person to the other.
# Once the repertories updated with a git pull, every user should be able to run the full analysis
if [ "$USER" = "marko" ]
then
    export PLOTS=$HOME/Desktop/plots
elif [ "$USER" = "COMPLETE HERE" ]
then
    export PLOTS=/PATH/TO/PLOTS
else
    echo "Don't forget to compelte the paths in the setup.sh in order to run the scripts!"
fi

# Snakemake environment requires python3. In order to overcome this issue, you can store the path to python2 and use it in the shell commands of the Snakefile
export PY2=path/to/python2
# To ensure that the python modules can be imported correctly
export PYTHONPATH=$PYTHONPATH:$TUTO:$ROUTINES:$PYTHON:$PY2
