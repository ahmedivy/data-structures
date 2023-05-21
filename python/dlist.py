from ll import LinkedList


def tmp():
    l = list()


def main(list):
    l = list()
    l.append(1)
    l.append(2)
    l.append(3)
    l.insert(0, 5)
    del l[-2]
    print(l)


if __name__ == "__main__":
    main(list)
    print("=================")
    main(LinkedList)
