#a = [ 1,5,7,8,3.14, 4, 5 ]
#a = [ 1,[2,3],4,5,6 ]
#a = [ 1,2,[3,4,5],[6,7] ]
#a = [ [[[[(1,2,3)]]]] ]
a = [[[(1,2,3),(4,5)]]]

def printList(a):
    for i in a:
        if type(i)==tuple or type(i)==list:
                printList(i)
        else:
            print(i, end=" ")
printList(a)
