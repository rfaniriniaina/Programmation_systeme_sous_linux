import os
import sys

d1 = os.pipe()
d2 = os.pipe()

pid = os.fork()

if pid == 0:
    os.dup2(d1[1], sys.stdout.fileno()) # redirection stdout vers d1
    os.dup2(d2[0], sys.stdin.fileno())  # redirection stdin vers d2
    
    os.close(d1[0]); os.close(d1[1])
    os.close(d2[0]); os.close(d2[1])

    # Simulation de l'envoi au père via stdout
    mot = "test" 
    sys.stdout.write(mot + "\n")
    sys.stdout.flush()
    sys.exit(0)

else:
    os.dup2(d1[0], sys.stdout.fileno())
    os.dup2(d2[1], sys.stdin.fileno())
    
    os.close(d1[0]); os.close(d1[1])
    os.close(d2[0]); os.close(d2[1])

    os.wait()