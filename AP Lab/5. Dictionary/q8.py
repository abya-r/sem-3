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
D2 = {
    141152: 'Jhansi',
    141153: 'Kanpur',
    141154: 'Lucknow',
    141155: 'Agra',
    141156: 'Shimla',
    141157: 'Chandigarh',
    141158: 'Mandi',
    141159: 'Kanpur',
    141160: 'Mathura',
    141161: 'Guna',
    141162: 'Bhopal',
    141163: 'Patna',
    141164: 'Gorakhpur',
    141165: 'Lucknow',
    141166: 'Kanpur',
    141167: 'Nagpur',
    141168: 'Bhopal'
    }
D3 = {
    141152: 9856687466,
    141153: 9856777466,
    141154: 8946687466,
    141155: 7756687412,
    141156: 9956687413,
    141157: 8856687414,
    141158: 7156687415,
    141159: 9156687416,
    141160: 9956687417,
    141161: 6656687418,
    141162: 9856687419,
    141163: 9856687420,
    141164: 9856687421,
    141165: 3356687422,
    141166: 9856687423,
    141167: 8836687424,
    141168: 9856687425
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
D6 = {
    141152: 'SanjayJain@gmail.com',
    141153: 'AbhinavAgarwal@gmail.com',
    141154: 'AbhishekNigam@gmail.com',
    141155: 'AdityaArora@gmail.com',
    141156: 'AdityaShrivastava@gmail.com',
    141157: 'AdityaThakur@gmail.com',
    141158: 'Amitkumar@gmail.com',
    141159: 'AashiJain@gmail.com',
    141160: 'DeepakSingh@gmail.com',
    141161: 'MahendraSingh@gmail.com',
    141162: 'VijayKumar@gmail.com',
    141163: 'AdityaPandey@gmail.com',
    141164: 'AdityaKumar@gmail.com',
    141165: 'AditiBhardwaj@gmail.com',
    141166: 'AnupKumarNigam@gmail.com',
    141167: 'AbhishekChatterjee@gmail.com',
    141168: 'AbhimanyuSingh@gmail.com'
    }

#8a

erno = int(input("enter enrolment number: "))
if erno in D1:
    print(f"Name: {D1[erno]}")
    print(f"Email: {D6[erno]}")
else:
    print(f"enrolment no. {erno} not found!")

#8b

email = input("enter email: ")
for enrol, em in D6.items():
    if em == email:
        print(f"Name: {D1[enrol]}")
        print(f"Erno: {enrol}")
#else:
#    print(f"student with email {email} not found!")

#8c

mob = int(input("enter mobile no.: "))
for enrol, m in D3.items():
    if m == mob:
        print(f"Name: {D1[enrol]}")
        print(f"City: {D2[enrol]}")
        break

# 8d

town = input("enter hometown: ")
for enrol, t in D2.items():
    if t==town:
        print(f"{enrol} {D1[enrol]}")

    
