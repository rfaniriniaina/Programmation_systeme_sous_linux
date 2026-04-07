#fils
import os
import sys

if len(sys.argv) >= 2:
    d1 = int(sys.argv[1])
    m = os.read(d1, 100).decode()
    print(f"Fils: Message reçu : {m}")
    os.close(d1)