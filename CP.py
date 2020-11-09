import sys
import inspect
import re

if __name__=="CP":
    sys.stdin = open('ip.txt', 'r') 
    sys.stdout = open('op.txt', 'w')

def debug(arg):
    frame = inspect.currentframe()
    try:
        context = inspect.getframeinfo(frame.f_back).code_context
        caller_lines = ''.join([line.strip() for line in context])
        m = re.search(r'debug\s*\((.+?)\)$', caller_lines)
        if m:
            caller_lines = m.group(1)
        sys.stderr.write(caller_lines+" = "+str(arg)+"\n")
    finally:
        del frame

try:
    
    def main():
        t=1
        t=int(sys.stdin.readline())
        while(t):
            n=int(sys.stdin.readline())
            for i in range(n):
                sys.stdout.write(str(2*(n+i))+" ")
            sys.stdout.write(str("\n"))

            t-=1
        
    main()
     
except Exception as e:
    sys.stdout.write("ErrOR : "+str(e))