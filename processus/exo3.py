import os
import sys

for i in range(5):
    pid = os.fork()

    if pid < 0:
        print("Erreur lors de la creation du fils\n")
        sys.exit(1)
    
    if pid == 0:
        print(f"Je suis le fils {i+1}, PID-{i+1} = {os.getpid}. ")
        break
