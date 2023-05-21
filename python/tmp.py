def generator(n):
    for i in range(n):
        yield (i)


d = generator(4)

print(next(d, 3))


def abc(x):
    ...


abc(3)
