import threading
import random

class TypeTableau:
    def __init__(self):
        self.tab = []
        self.n = 0
        self.x = 0
        self.result = None # Pour stocker le retour (void* 1 ou 0)

def generate_tab(t):
    t.tab = [random.randint(0, 99) for _ in range(t.n)]

def find(t):
    for i in range(t.n):
        if t.tab[i] == t.x:
            t.result = 1
            return
    t.result = 0

t = TypeTableau()

t.n = int(input("Donner la taille du tableau : "))
t.x = int(input("Donner la valeur de x (à rechercher) : "))

tid1 = threading.Thread(target=generate_tab, args=(t,))
tid1.start()
tid1.join()

print("Tableau rempli : ", end="")
for val in t.tab:
    print(f"{val} ", end="")
print()

tid2 = threading.Thread(target=find, args=(t,))
tid2.start()
tid2.join()

if t.result == 1:
    print(f"{t.x} est dans le tableau.")
else:
    print(f"{t.x} n'est pas dans le tableau.")