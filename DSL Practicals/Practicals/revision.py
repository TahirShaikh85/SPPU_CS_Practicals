def removeDuplicate(d):
    lst = []
    for i in d:
        if i not in lst:
            lst.append(i)
    return lst


def intersection(lst1, lst2):  # common elements
    lst3 = []
    for val in lst1:
        if val in lst2:
            lst3.append(val)
    return lst3


def union(lst1, lst2):
    lst3 = lst1.copy()
    for val in lst2:
        lst3.append(val)
    return lst3


def difference(lst1, lst2):
    lst3 = []
    for val in lst1:
        if val not in lst2:
            lst3.append(val)
    return lst3


def symm_diff(lst1, lst2):
    D1 = difference(lst1, lst2)
    D2 = difference(lst1, lst2)
    lst3 = union(D1, D2)
    return lst3

# -----------------------------

# List of students who play either cricket or badminton but not both


def e_C_or_B_notBoth(lst1, lst2):
    lst3 = symm_diff(lst1, lst2)
    print("\nList of students who play either cricket or badminton but not both: ", lst3)
    return len(lst3)

# Number of students who play neither cricket nor badminton


def nCnB(lst1, lst2, lst3):
    lst3 = difference(lst1, union(lst2, lst3))
    print("\nNumber of students who play neither cricket nor badminton: ", lst3)
    return len(lst3)

# Number of students who play cricket and football but not badminton.


def CFnB(lst1, lst2, lst3):
    lst3 = difference(intersection(lst1, lst2), lst3)
    print("\nNumber of students who play cricket and football but not badminton: ", lst3)
    return len(lst3)

# List of students who play both cricket and badminton


def CB(lst1, lst2):
    lst3 = intersection(lst1, lst2)
    print(("\nList of students who play both cricket and badminton: ", lst3))
    return len(lst3)


lst1 = [4, 5, 6, 8]
lst2 = [4, 5, 10, 11]
print(intersection(lst1, lst2))
print(union(lst1, lst2))
print(difference(lst1, lst2))
