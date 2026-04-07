import threading

# Simulation de la struct Affiche
class Affiche:
    def __init__(self, tab, taille):
        self.tab = tab
        self.taille = taille

def generate_tab(arg):
    p = arg
    print("Tableau : ", end="")
    for i in range(p.taille):
        print(f"{p.tab[i]} ", end="")
    print()

# main
tab = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
p = Affiche(tab, 10)

tid = threading.Thread(target=generate_tab, args=(p,))
tid.start()
tid.join()