import threading
import random

N = 10

def generate_tab(arg, res_container):
    tab = []
    for i in range(N):
        tab.append(random.randint(0, 99))
    res_container.append(tab) # On met le tableau dans le conteneur

n = 5
result_container = [] # Pour simuler le retour de malloc/pthread_join

tid = threading.Thread(target=generate_tab, args=(n, result_container))
tid.start()
tid.join()

result = result_container[0] # On récupère le tableau généré

for i in range(N):
    print(f"{result[i]} ", end="")
print()