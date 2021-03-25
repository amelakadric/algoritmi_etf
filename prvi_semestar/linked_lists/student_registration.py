from random import randrange, random

class Student:
    def __init__(self, name, surname, brIn:int, sp, year:int):
        self.name=name
        self.surname=surname
        self.brIn=brIn
        self.sp=sp 
        self.year=year
        self.next=None

    def __repr__(self):
        return self.name

class Lista:
    def __init__(self):
        self.head=None
        self.tail=None
        self.numElem=0
    def __repr__(self):
        cur = self.head
        ispis = []
        while cur is not None:
            ispis.append(cur.name)
            cur = cur.next
        return " -> ".join(ispis)
    
    
def addStudent(lista, element):

    if lista.tail is not None:
        lista.tail.next = element
    else:
        lista.head = element

    lista.tail = element
    lista.numElem += 1


def reach(lista, num: int):
    if (lista is None) or  (num < 0) or  (num >= lista.numElem):
        return None

    i = 0
    cur = lista.head
    while i < num:
        cur = cur.next
        i += 1

    return cur

def duzinaListe(lista):
    return lista.numElem


def removeElement(lista, element):
    if (lista is None) or (element is None):
        return 0
    prev = None
    cur = lista.head
    while cur is not None:
        if cur == element:
            if prev is not None:
                prev.next = cur.next
            else:
                lista.head = cur.next
                if lista.head is None:
                    lista.tail = None
            del cur
            lista.numElem -= 1
            return 1
        else:
            prev = cur
            cur = cur.next
    return 0

def provera(lista):
    if duzinaListe(lista)==0:
        return 0
    else:
        return 1


#-------------MAIN------------------


def dodajStudenta():
    global lista
    print('Unesite ime studenta:')
    name=input()
    print('Unesite prezime studenta:')
    surname=input()
    print('Unesite broj indeksa studenta:')
    brIndeksa=int(input())
    print('Unesite studijski program studenta:')
    studProg=input()
    print('Unesite trenutnu godinu studija studenta:')
    trGodStud=int(input())
    student=Student(name=name, surname=surname, brIn=brIndeksa, sp=studProg, year=trGodStud)
    addStudent(lista, student)
    broj=duzinaListe(lista)
    print('Broj studenata u listi: {}\n'.format(broj))
       

def premestaj():
    global red
    global lista
    while duzinaListe(lista)>0:
        num=randrange(duzinaListe(lista))
        student=reach(lista, num)
        addStudent(red, student)  
        removeElement(lista, student)
        
def upisJednog(a):
    global red
    num=random()
    if 0<=num<=0.5:
        removeElement(red, a)
        print(a.name, a.surname, a.year+1)
    else:
        removeElement(red, a)
        addStudent(red, a) 
        

def upis():
    global red
    brojac=0
    while duzinaListe(red)>0:
        a=red.head
        upisJednog(a)
        brojac+=1
    print('Broj koraka je: {}\n'.format(brojac))


lista=Lista()
red=Lista()


while True:
    print("______MENI______\n"
          "Izaberite opciju\n"
          "1. Ucitaj studenta u listu\n"
          "2. Kreiraj red\n"
          "3. Pokreni upis\n"
          "4. Kraj programa\n")
    try:
        a=int(input())
        if a<0 or a>4:
            print("Unesite ispravnu opciju\n")
            continue
    except:
        print("Unesite broj kao opciju\n")
        continue

    if a==1:
        dodajStudenta()
    elif a==2:
        premestaj()
    elif a == 3:
        upis()
    elif a == 4:
        break
