# Snakefile script to organize the data architecture of the project
# 
# Author: Marko Stamenkovic
# Site: https://mstamenk.github.io
# Mail: stamenkovim@gmail.com
#
# This script is part of the Snakemake Tutorial for data analysts
# Please visit : https://mstamenk.github.io/2017/07/snakemake-tutorial-for-data-analysts.html
# for more informations

from routines.Analysis import loc, parseDatafiles

setup_path = loc.SCRIPTS + 'setup_path.sh'


