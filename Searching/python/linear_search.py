def LinearSearch(lys, element):
    for i in range (len(lys)):
        if lys[i] == element:
            return("Found")
    return("Not found")


l=[1,2,3,4,5,6]
print(LinearSearch(l,5))
