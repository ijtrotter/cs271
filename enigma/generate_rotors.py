# credit to Calvin this is modified from his python solution
rs = [ 
    "BDFHJLCPRTXVZNYEIWGAKMUSQO", # fast 
    "AJDKSIRUXBLHWTMCQGZNPYFVOE", # medium 
    "EKMFLGDQVZNTOWYHXUSPAIBRCJ", # slow 
    "IXUHFEZDAOMTKQJWNSRLCYPBVG"  # reflect
]

A = ord('A') # value of 'A'
NC = len(rs[0]) # number of characters

# invert lambda updated to join characters into a single string
invert = lambda r : "".join([chr(p[1]+A) for p in sorted([(r[i],i) for i in range(NC)])])

rs += [invert(r) for r in rs[2::-1]]
rs = "".join(rs)

print(rs)