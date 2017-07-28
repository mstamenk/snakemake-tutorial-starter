import os
from routines.Analysis import loc, parseDatafiles
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("--mode", default='Linear')
parser.add_argument("--start", default=20)
parser.add_argument("--end", default=100)
args = parser.parse_args()

def process_data(dtype,start,end):
    save_path = loc.RESOURCE
    save_name, c = parseDatafiles(dtype)
    os.chdir(loc.CPP)
    os.system("./produce.out --mode %s --start %s --end %s --location %s --saveName %s"%(dtype, start, end, save_path, save_name))

process_data(args.mode, args.start, args.end)
