b=(input())
d=1
a=["hallo", "klempner", "das", "ist", "fantastisch", "fluggegecheimen"]
a1="".join(a)
for i in range(len(b)):
    d*=(a1.count(b[i])/45)
print(d)
