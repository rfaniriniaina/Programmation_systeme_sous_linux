import os
import sys
import time

debut = time.time()

pid1 = os.fork()
if pid1 == 0:
    t1 = ((os.getpid() + int(time.time())) % 10) +1
    print(f"Le fils 1 a dormi {t1} secondes.")
    time.sleep(t1)
    sys.exit(0)

pid2 = os.fork()
if pid2 == 0:
    t2 = ((os.getpid() + int(time.time())) % 10) +1
    print(f"Le fils 2 a dormi {t2} secondes.")
    time.sleep(t2)
    sys.exit(0)

os.wait()
os.wait()

fin = time.time()
total_time = int(fin - debut)
print(f"La duree totale est: {total_time} secondes.")
