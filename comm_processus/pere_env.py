#pere_environnement
import os
import sys

t = os.pipe()
d1 = t[0]
d2 = t[1]
os.set_inheritable(d1, True)

pid = os.fork()
if pid == 0:
    os.close(d2)
    fd = str(d1)
    
    os.environ["DESCRIPTEUR"] = fd
    os.execv(sys.executable, [sys.executable, "fils_env.py"])
else:
    os.close(d1)
    m = "Salut le fils"
    os.write(d2, m.encode())
    os.close(d2)
    os.wait()