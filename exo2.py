import os
import sys

if len(sys.argv) < 2:
    print("Le programme n'a recu aucun argument.")
    sys.exit()

pid = os.fork()
if pid == 0:
    os.execvp("cp", ["cp", "-r", ".", sys.argv[1]])

else:
    os.wait()
    print("Copie terminé.")