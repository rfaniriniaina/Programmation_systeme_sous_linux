import os
import sys

while True:
    file = input("Saisissez des noms de fichier ou 'q/Q' pour quitter :") 
    if file.lower() == "Q" or file.lower() == "q":
        break

    pid = os.fork()
    if pid == 0:
        os.execv("/usr/bin/emacs", ["emacs", file])
        os._exit(1)
    else:
        os.wait()