import os
import sys

while True:
    rep = input("Saisissez des noms de repertoires ou 'q/Q' pour quitter :") 
    if rep.lower() == "Q" or rep.lower() == "q":
        break

    pid = os.fork()
    if pid == 0:
        os.execvp("cp", ["cp", "-r", ".", rep])
        os._exit(1)
    else:
        os.wait()