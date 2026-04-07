
import os
import struct

n = int(input("Nombre d'entiers : "))

tab = []
for i in range(n):
    val = int(input(f"tab[{i}] = "))
    tab.append(val)

try:
    # open("entiers.bin", O_WRONLY | O_CREAT | O_TRUNC, 0644)
    fd = os.open("entiers.bin", os.O_WRONLY | os.O_CREAT | os.O_TRUNC, 0o644)
    
    # On transforme la liste d'entiers en octets
    donnees_binaires = struct.pack(f'{n}i', *tab)
    
    os.write(fd, donnees_binaires)
    print("Ecrit dans entiers.bin .")
    os.close(fd)
except OSError:
    print("Erreur d ouverture du fichier .")
