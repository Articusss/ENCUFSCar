from random import randrange
import time

start = time.time()
nprovas = 100000000
alternativas = 10
aprov = 0
for i in range(nprovas):
    acertos = 0
    for j in range (alternativas):
        if(randrange(2) == 1): 
            acertos += 1
    if(acertos > 2):
        aprov += 1

print(aprov/nprovas * 100, "%");
print("Tempo = ", (time.time() - start), "s")
