class Node:

    def __init__(self, data):
        self.children = []
        self.data = data
        self.parent = None

    def addChild(self, child):
        child.parent = self
        self.children.append(child)

    def getLevel(self):
        level = 0
        p = self.parent
        while p:
            level += 1
            p = p.parent

        return level

    def __repr__(self):
        printSquare(self.data)

    def printTree(self):
        razmak = ' ' * self.getLevel()
        prefiks = razmak + "|__" if self.parent else""
        print(prefiks+self.data)
        if len(self.children) > 0:
            for child in self.children:
                child.printTree()


# class Node:
#     def __init__(self, data):

#         self.children = []
#         self.data = data

#     def __repr__(self):
#         pass


# def makeRoot(kvadrat):
#     root=Node(kvadrat)

#     return


# def newNode(kvadrat):


# def addChild(kvadrat1, kvadrat2):
#     pass


# -----obrada matrice-


def beginning():
    # pravljenje kvadrata

    n = int(input("Unesite dimenziju stranice kvadrata:"))
    skup = [int(x) for x in input(
            "Unesite skup vrednosti: ").split(' ')]

    if len(skup) != (n**2):
        print("Nevalidan skup")
        return
    check = isProgression(skup)
    if check == False:
        print("Nevalidan skup")
        return

    kvadrat = []
    for i in range(n):
        vrsta = []
        kvadrat.append(vrsta)
    # pocetno stanje
    j = 0
    while j < n:
        lista = [int(x) for x in input(
            "Unesite vrednost za {}. vrstu: ".format(j+1)).split(' ')]
        for i in range(len(lista)):
            kvadrat[j].append(lista[i])
        j += 1

    print(kvadrat)
    return kvadrat, skup


def isMagic(matrix, skup):
    n = len(matrix)
    zbir = karakZbir(matrix, skup, n)
    # SUMA PO VRSTAMA
    sveSume = []
    sume = []
    for j in range(0, n):
        sum = 0
        for i in range(n):
            if kvadrat[j][i] == 0:
                break
            else:
                sum += kvadrat[j][i]
            if i == n-1:
                sume.append(sum)

    sumaV = list(set(sume))

    if len(sumaV) == 0:
        pass
        # treba da se unese jos jedna vrednost
    elif len(sumaV) > 1:
        # vise suma, nije magicni
        return 3
    elif len(sumaV) == 1:
        sumaV = sumaV[0]
        sveSume.append(sumaV)

    # SUMA PO KOLONAMA
    sume = []
    for i in range(n):
        sum = 0
        for j in range(n):
            if kvadrat[j][i] == 0:
                break
            else:
                sum += kvadrat[j][i]
            if j == n-1:
                sume.append(sum)

    sumaK = list(set(sume))
    if len(sumaK) == 0:
        pass
        # treba da se unese jos jedna vrednost
    elif len(sumaK) > 1:
        return 3
        # vise suma se naslo
    elif len(sumaK) == 1:
        sumaK = sumaK[0]
        sveSume.append(sumaK)

    # SUMA PO DIJAGONALAMA
    # glavna dijagonala
    sumaD1 = 0
    nula = False
    for j in range(n):
        if kvadrat[j][j] == 0:
            nula = True
            break
        else:
            sumaD1 += kvadrat[j][j]

    if nula == False and sumaD1 != 0:
        sveSume.append(sumaD1)

    # sporedna dijagonala
    sumaD2 = 0
    nula = False
    for j in range(n):
        if kvadrat[j][n-j-1] == 0:
            nula = True
            break
        else:
            sumaD2 += kvadrat[j][n-j-1]

    if nula == False and sumaD2 != 0:
        sume.append(sumaD2)
        sveSume.append(sumaD2)

    # sve sume koje mogu da se nadju su tu, provera jesu li iste
    s = list(set(sveSume))
    if len(s) > 1:
        # naslo se vise suma
        return 3
    elif len(s) == 1:
        s = s[0]
        if s == zbir:
            print(s)
            # nasla se suma i jednaka je zbiru, moze da bude magicni
            return 1
        else:
            # nasla se suma i nije jednaka zbiru
            return 2

    else:
        return 0
        # mora da se doda jos neki clan, moze da bude magicni


def isProgression(skup):
    skup = sorted(skup)
    r = skup[1]-skup[0]
    for i in range(len(skup)-1):
        if (skup[i+1]-skup[i]) != r:
            return False

    return True


def karakZbir(kvadrat, skup, n):
    zbir = 0
    ceo = True
    for i in skup:
        zbir += i
    if zbir % n != 0:
        return 0
    zbir = zbir/n
    return zbir


def ukloniIzSkupa(skup, kvadrat):
    for j in range(len(kvadrat)):
        for i in range(len(kvadrat)):
            if kvadrat[j][i] != 0:
                skup.remove(kvadrat[j][i])
    return skup


# def formiranje(kvadrat, skup):

#     skup = ukloniIzSkupa(skup, kvadrat)
#     for k in skup:
#         skup2 = skup.copy()
#         kv2 = kvadrat.copy()
#         for j in range(len(kvadrat)):
#             for i in range(len(kvadrat)):
#                 if kvadrat[j][i] == 0:
#                     kv2[j][i] = k
#                     r = isMagic(kv2)
#                     if r == 0 or r == 1:
#                         child=Node(kv2)
#                         # addnode
#                         skup2.remove(k)
#                         formiranje(kv2, skup2)

def formiranje(node, skup):

    skup = ukloniIzSkupa(skup, node.data)
    for k in skup:
        skup2 = skup.copy()
        child = node.data.copy()
        for j in range(len node.data)):
            for i in range(len node.data)):
                if node.data[j][i] == 0:
                    child[j][i]=k
                    r=isMagic(child)
                    if r == 0 or r == 1:
                        child=Node(child)
                        node.addChild(child)
                        skup2.remove(k)
                        formiranje(child, skup2)


def printSquare(kvadrat):
    for j in range(len(kvadrat)):
        for i in range(len(kvadrat)):
            print(kvadrat[j][i], end=" ")


def isSolution(kvadrat):
    nula=False
    for j in range(len(kvadrat)):
        for i in range(len(kvadrat)):
            if kvadrat[j][i] == 0:
                nula=True
                break
    return nula


def isPerfect(matrix):
    pass


while True:
    print("______MENI______\n"
          "Izaberite opciju\n"
          "1. Zadavanje pocetnog stanja kvadratu\n"
          "2. Provera da li kvadrat moze biti magican\n"
          "3. Ispis resenja\n"
          "4. Kraj programa\n")

    try:
        b=int(input())
        if b < 0 or b > 4:
            print("Unesite ispravnu opciju\n")
            continue
    except:
        print("Unesite broj kao opciju\n")
        continue

    if b == 1:
        try:
            kvadrat, skup=beginning()
        except TypeError:
            print("Uneli ste prevelik skup. Pokusajte ponovo")
            # ako je duzina skupa veca od kvadrata

    elif b == 2:
        slucaj=isMagic(kvadrat, skup)
        if slucaj == 0:
            print("Pocetno stanje je validirano. (code 0)")
            root=Node(kvadrat)
        elif slucaj == 1:
            print("Pocetno stanje je validirano. (code 1)")
            root=Node(kvadrat)
        elif slucaj == 2:
            print("Pocetno stanje nije validno. (code 2)")
        elif slucaj == 3:
            print("Pocetno stanje nije validno. (code 3)")
    elif b == 3:
        pass
    elif b == 4:
        break
