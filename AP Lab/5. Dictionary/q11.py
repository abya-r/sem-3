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
providers = {
             94: 'BSNL',
             98: 'Airtel',
             89: 'Idea',
             77: 'Reliance',
             97: 'Idea',
             99: 'Vodafone',
             79: 'Docomo'
             }

prov = input("input provider: ")

num = []
for no, provider in providers.items():
    if provider == prov:
        num.append(no)

for enrol, number in D3.items():
    prefix = int(str(number)[:2])
    if prefix in num:
        print(enrol, D1[enrol])
