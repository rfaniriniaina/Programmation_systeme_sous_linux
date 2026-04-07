#fils_environnement
import os

s = os.getenv("DESCRIPTEUR")
if s:
    d1 = int(s)
    m = os.read(d1, 100).decode()
    print(f"Fils: Message reçu : {m}")
    os.close(d1)

