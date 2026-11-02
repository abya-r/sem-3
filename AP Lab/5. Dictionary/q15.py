D1 = {
      141152:'Sanjay Jain',
      141153:'Abhinav Agarwal',
      141154:'Abhishek Nigam',
      141155:'Aditya Arora',
      141156:'Aditya Shrivastava',
      141157:'Aditya Thakur',
      141158:'Amit Kumar',
      141159:'Aashi Jain',
      141160:'Deepak Singh',
      141161:'Mahendra Singh',
      141162:'Vijay Kumar',
      141163:'Aditya Pandey',
      141164:'Aditya Kumar',
      141165:'Aditi Bhardwaj',
      141166:'Anup Kumar Nigam',
      141167:'Abhishek Chatterjee',
      141168:'Abhimanyu Singh'
      }
D5 = {
    141152: [78,66,90],
    141153: [88,65,69],
    141154: [77,93,64],
    141155: [88,65,70],
    141156: [77,93,65],
    141157: [88,65,71],
    141158: [77,93,68],
    141159: [88,65,72],
    141160: [77,93,67],
    141161: [88,65,73],
    141162: [77,93,68],
    141163: [88,65,74],
    141164: [77,93,69],
    141165: [88,65,75],
    141166: [77,93,70],
    141167: [88,65,76],
    141168: [77,93,71]
    }

max_avg = -1.0
for enrol, marks in D5.items():
    avg = sum(marks) / len(marks)
    if avg > max_avg:
        max_avg = avg

print(f"Highest Average Mark: {max_avg:.2f}")
for enrol, marks in D5.items():
    avg = sum(marks) / len(marks)
    if avg == max_avg:
        print(enrol, D1[enrol], f"Average: {avg:.2f}")
