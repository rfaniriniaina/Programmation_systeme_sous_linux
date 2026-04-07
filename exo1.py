import os
import sys

pid = os.fork()

if pid < 0:
    print("Erreur lors de la creation du fils.")
    sys.exit(1)
elif pid == 0:
    print("Je suis le fils.")
else:
    print("Je suis le pere.")