import sys
import random as rand
import time

size = int(sys.argv[1])
lines = []


def end(message):
    elapsed = time.clock() - timer
    message = "En {0:.6f} segundos ".format(elapsed) + message + "\n"
    sys.stderr.write(message)


# Llenar

timer = time.clock()

for i in range(size):
    lines.append(rand.random())

end("se genero la lista")

# elapsed = time.clock() - timer
# message = "Lista generada en {0:.6f} segundos\n".format(elapsed)
# sys.stderr.write(message)

# print size

# Recorrer

timer = time.clock()

s = 0
for l in lines:
    s += l
end("se recorrio la lista usando for")
timer = time.clock()

for i in range(size):
    s+= lines[i]
end("se recorrio la lista usando indices")
timer = time.clock()

i = 0
while i < size:
    s+=lines[i]
    i += 1


end("se recorrio la lista usando un while")

#
# elapsed = time.clock() - timer
# message = "Recorrer usando indices toma {0:.6f} seconds\n".format(elapsed)
# sys.stderr.write(message)
