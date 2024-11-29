import random


def randLR() -> str:
    rand = random.randrange(0, 10)
    if rand < 5:
        return 'L'
    else:
        return 'R'

with open('bst.in', 'w') as file:
    n = random.randrange(2, 60)
    file.write(str(n) + '\n')
    file.write(str(random.randrange(-100, 100, 1)) + '\n')
    for i in range(2, n + 1):
        file.write(str(random.randrange(-100, 100, 1)) + " " + str(random.randrange(1, i, 1)) + " " + randLR() + '\n')
    file.close()