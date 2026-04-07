import os
import sys
import signal

pid = os.fork()

if pid < 0:
    print("Erreur")
    sys.exit(1)

if pid == 0:
    print(f"Fils (PID {os.getpid()}) : ")
    i = 0
    while True:
        i += 1
else:
    while True:
        print("s : Endormir le fils (SIGSTOP)")
        print("r : Redémarrer le fils (SIGCONT)")
        print("q : Tuer le fils et quitter (SIGKILL)")
        
        choix = input("Votre choix : ").strip()

        if choix == 's':
            os.kill(pid, signal.SIGSTOP)
            print("Signal SIGSTOP envoyé au fils.")
        
        elif choix == 'r':
            os.kill(pid, signal.SIGCONT)
            print("Signal SIGCONT envoyé au fils.")
        
        elif choix == 'q':
            os.kill(pid, signal.SIGKILL)
            print("Fils éliminé. Fermeture du programme.")
            break
        
        else:
            print("Option invalide.")