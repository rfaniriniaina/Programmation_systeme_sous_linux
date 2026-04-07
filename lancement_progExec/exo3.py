import os

file = input("Saisissez un nom de fichier texte : ")

os.execv("/usr/bin/emacs", ["emacs", file])