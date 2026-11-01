er = (210, 211, 212, 213, 214, 215)
name = ("A", "B", "C", "D", "E", "F")
pcme = ((10, 15, 12, 9), (16, 8, 15, 18), (14, 15, 10, 13), (19, 17, 16, 14), (10, 12, 15, 17), (15, 15, 12, 11))



max = 0.0
for i in range(len(er)):
    avg = sum(pcme[i])/len(pcme[i])
    if avg>max:
        max = avg
        ind = i
print("Details of student who has scored highest average marks: ")
print("Erno.:", er[ind])
print("Name:", name[ind])



highest_avg = 0.0
for i in pcme:
    avg = (i[0]+i[1]+i[2]+i[3])/4
    if avg>highest_avg:
        highest_avg = avg
        item = i
ind = pcme.index(item)
print("Details of student who has scored highest average marks: ")
print("Erno.:", er[pcme.index(item)])
print("Name:", name[pcme.index(item)])
