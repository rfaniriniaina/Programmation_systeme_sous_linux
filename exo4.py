import threading
import random
import sys
import os

TAILLE1 = 8
TAILLE2 = 15

class Tableau:
    def __init__(self, taille):
        self.tab = []
        self.taille = taille

class Inclus:
    def __init__(self, T1, T2):
        self.T1 = T1
        self.T2 = T2
        self.res = 0

def generate_tab(t):
    t.tab = [random.randint(0, 19) for _ in range(t.taille)]

def inclusion(p):
    p.res = 1
    for i in range(p.T1.taille):
        trouve = 0
        for j in range(p.T2.taille):
            if p.T1.tab[i] == p.T2.tab[j]:
                trouve = 1
                break
        if trouve == 0:
            p.res = 0
            break

def cancel():
    while True:
        c = sys.stdin.read(1)
        if c == 'A':
            print("\nAnnulation...")
            os._exit(0) # Arrête tout le processus immédiatement

# main
T1 = Tableau(TAILLE1)
T2 = Tableau(TAILLE2)

tid1 = threading.Thread(target=generate_tab, args=(T1,))
tid2 = threading.Thread(target=generate_tab, args=(T2,))
tid_kb = threading.Thread(target=cancel, daemon=True) # daemon = detach

tid1.start()
tid2.start()
tid_kb.start()

tid1.join()
tid2.join()

print(f"T1 ({T1.taille} elements) : {' '.join(map(str, T1.tab))}")
print(f"T2 ({T2.taille} elements) : {' '.join(map(str, T2.tab))}")
print("(Appuyez sur 'A' + Entrée pour annuler)")

param = Inclus(T1, T2)
tid_incl = threading.Thread(target=inclusion, args=(param,))
tid_incl.start()
tid_incl.join()

if param.res:
    print("T1 est inclus dans T2.")
else:
    print("T1 n'est pas inclus dans T2.")