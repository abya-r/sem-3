D1 = {141152:'Sanjay Jain',
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
D4 = {
    141152: 'Uttar Pradesh',
    141153: 'Uttar Pradesh',
    141154: 'Uttar Pradesh',
    141155: 'Uttar Pradesh',
    141156: 'Himachal Pradesh',
    141157: 'Punjab',
    141158: 'Himachal Pradesh',
    141159: 'Uttar Pradesh',
    141160: 'Uttar Pradesh',
    141161: 'Madhya Pradesh',
    141162: 'Madhya Pradesh',
    141163: 'Bihar',
    141164: 'Uttar Pradesh',
    141165: 'Uttar Pradesh',
    141166: 'Uttar Pradesh',
    141167: 'Maharashtra',
    141168: 'Madhya Pradesh'
    }


state = input("enter state: ")
for enrol, s in D4.items():
    if s==state:
        print(enrol, D1[enrol])
