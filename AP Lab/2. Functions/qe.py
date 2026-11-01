def do_twice(f):
    f()
    f()
def print_spam():
    print('spam')
do_twice(print_spam)



def do_twice(f, val):
    f(val)
    f(val)
def print_arg(arg):
    print(arg)
do_twice(print_arg, 'hello')



def print_2ice(s):
    print(s)
    print(s)
print_2ice('spam')



def do_twice(f, val):
    f(val)
    f(val)
def print_2ice(s):
    print(s)
    print(s)
do_twice(print_2ice, 'spam')