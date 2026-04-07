import os
import sys

pid1 = os.fork()
if pid1 < 0:
    print("Erreur lors de la creation du fils 1")
    sys.exit(1)
if pid1 == 0:
    print("Je suis le fils 1.")

pid2 = os.fork()
if pid2 < 0:
    print("Erreur lors de la creation du fils 2")
    sys.exit(1)
if pid1 == 0:
    print("Je suis le fils 2.")

os.waitpid(pid1, 0)
os.waitpid(pid2, 0)

print("Je suis le pere")