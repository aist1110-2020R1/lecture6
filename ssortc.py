import sys
from subprocess import call

if __name__ == "__main__":
   n = 10
   if len(sys.argv) == 2:
      n = int(sys.argv[1])
   call(["./ssort", str(n)])