import os
import sys

# MO = 1024 * 1024
MO = 1048576

for i in range(1, len(sys.argv)):
    try:
        # opendir(argv[i])
        contenu_liste = os.listdir(sys.argv[i])
    except OSError:
        print(f"Erreur d'ouverture du dossier {sys.argv[i]} .")
        continue

    for nom_fichier in contenu_liste:
        # sprintf(chemin , "%s/%s" , ...)
        chemin = os.path.join(sys.argv[i], nom_fichier)

        try:
            # stat(chemin, &st)
            st = os.stat(chemin)
            
            # S_ISREG(st.st_mode) et taille >= MO
            if os.path.isfile(chemin) and st.st_size >= MO:
                taille_mo = st.st_size // MO
                print(f"{chemin} taille={taille_mo}Mo UID={st.st_uid}")
        except OSError:
            continue
