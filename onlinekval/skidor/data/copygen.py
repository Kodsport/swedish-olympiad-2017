import sys
import shutil

tc = sys.argv[-2]
sys.stdout.write(open("../testcases/{}.in".format(tc)).read())
