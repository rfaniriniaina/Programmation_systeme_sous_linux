import os
import sys

# d1[2] (fils -> pere), d2[2] (pere -> fils)
d1 = os.pipe() 
d2 = os.pipe()

pid = os.fork()

if pid == 0:
    os.close(d1[0])
    os.close(d2[1])

    mot = input("Entrez un mot : ")
    os.write(d1[1], mot.encode()) # envoyer au pere

    # recevoir le resultat (int)
    res_bytes = os.read(d2[0], 4)
    valeurR = int.from_bytes(res_bytes, byteorder='little')
    print(f"Résultat reçu : {valeurR}")

    os.close(d1[1])
    os.close(d2[0])
    sys.exit(0)

else:
    os.close(d1[1])
    os.close(d2[0])

    mot = os.read(d1[0], 100).decode().strip() # recevoir du fils
    found = 0

    if os.path.exists("fichier.txt"):
        with open("fichier.txt", "r") as fp:
            for mot_fichier in fp.read().split():
                if mot == mot_fichier:
                    found = 1
                    break
    
    # envoyer le resultat au fils
    os.write(d2[1], found.to_bytes(4, byteorder='little'))

    os.close(d1[0])
    os.close(d2[1])
    os.wait()