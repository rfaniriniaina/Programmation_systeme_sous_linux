import sys

def somme(a, b):
    resultat = a + b
    print(f"{a} + {b} = {resultat}")
    return resultat

def main():
    if len(sys.argv) <= 2:
        print("Le programme n'a pas reçu assez d'arguments.")
        sys.exit(1)

    try:
        a = int(sys.argv[1])
        b = int(sys.argv[2])
        
        s = somme(a, b)
        
    except ValueError:
        print("Erreur : Veuillez fournir des nombres entiers en arguments.")
        sys.exit(1)

if __name__ == "__main__":
    main()