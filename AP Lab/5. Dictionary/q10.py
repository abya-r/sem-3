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

host = input("enter host: ")
for enrol, email in D6.items():
    if host in email:
        print(enrol, D1[enrol])
