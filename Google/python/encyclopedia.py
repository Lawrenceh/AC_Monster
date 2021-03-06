************************************************
Python pass by reference or pass by value myth *
************************************************
It passes by reference, but, because of some immutable nature, you see "pass by value" because of name rebinding.

def spam(eggs):
    eggs.append(1)
    eggs = [2, 3]

ham = [0]
spam(ham)
print(ham) # [0, 1]


********************
*** __import__() ***
********************
It is called and invoked by import statement.

import spam 
results in bytecode:
spam = __import__('spam', globals(), locals(), [], -1)

import spam.ham
results:
spam = __import__('spam.ham', globals(), locals(), [], -1)

from spam.ham import eggs, sausage as saus
results:
_temp = __import__('spam.ham', globals(), locals(), ['eggs', 'sausage'], -1)
eggs = _temp.eggs
saus = _temp.sausage


*****************
str() vs repr() *
*****************

1) str() for user, repr() for debugging developer; str() readable, repr() unambiguous
2) repr() computes the official object representation, while str() computes the informal string representation


import datetime
today = datetime.datetime.now()
 
# Prints readable format for date-time object
print str(today)
 
# prints the official format of date-time object
print repr(today)     

# 2016-02-22 19:32:04.078030
# datetime.datetime(2016, 2, 22, 19, 32, 4, 78030)


*************************
redirect stdout to file *
*************************
import sys
sys.stdout = open('file', 'w')
print 'test'

or

python foo.py > file


****************************************************
display contents of a text file in reverse order ***
****************************************************
for line in reversed(open(...)):
    ....


****************************
virtual methods in Python? *
****************************
Python methods are always virtual in the sense that, Python is duck typing.

However, you might want to use below for defining abstract class:

__meta__ = abc.ABCMeta 
@abc.abstractmethod
def my_abstract_method(self, ...):
    ...


*****
GIL *
*****
Disables us to use extra cores.


**************************
Default argument pitfall *
**************************
def f(x, l = []):
    for i in xrange(x):
        l.append(i * i)
    print(l)

f(2)
f(3, [3,2,1])
f(3) # [0, 1, 0, 1, 4]


**************************
Is monkey patching good? *
**************************
Not good at all. But useful in unit test - mock



************
Decorators *
************

Example 1:

def time_this(original_function):      
    def new_function(*args,**kwargs):
        import datetime                 
        before = datetime.datetime.now()                     
        x = original_function(*args,**kwargs)                
        after = datetime.datetime.now()                      
        print "Elapsed Time = {0}".format(after-before)      
        return x                                             
    return new_function                                   
    
@time_this
def func_a(stuff):
    import time
    time.sleep(3)

func_a(1)



Example 2:

def requires_admin(fn):
    def ret_fn(*args,**kwargs):
        lPermissions = get_permissions(current_user_id())
        if 'administrator' in lPermissions:
            return fn(*args,**kwargs)
        else:
            raise Exception("Not allowed")
    return ret_fn

def requires_logged_in(fn):
    def ret_fn(*args,**kwargs):
        lPermissions = get_permissions(current_user_id())
        if 'logged_in' in lPermissions:
            return fn(*args,**kwargs)
        else:
            raise Exception("Not allowed")
    return ret_fn
    
def requires_premium_member(fn):
    def ret_fn(*args,**kwargs):
        lPermissions = get_permissions(current_user_id())
        if 'premium_member' in lPermissions:
            return fn(*args,**kwargs)
        else:
            raise Exception("Not allowed")
    return ret_fn
    
@requires_admin
def delete_user(iUserId):
   """
   delete the user with the given Id. This function is only accessable to users with administrator permissions
   """

@requires_logged_in 
def new_game():
    """
    any logged in user can start a new game
    """
    
@requires_premium_member
def premium_checkpoint():
   """
   save the game progress, only accessable to premium members
   """





def requires_permission(sPermission):                            
    def decorator(fn):                                            
        def decorated(*args,**kwargs):                            
            lPermissions = get_permissions(current_user_id())     
            if sPermission in lPermissions:                       
                return fn(*args,**kwargs)                         
            raise Exception("permission denied")                  
        return decorated                                          
    return decorator       
    
    
def get_permissions(iUserId): #this is here so that the decorator doesn't throw NameErrors
    return ['logged_in',]

def current_user_id():        #ditto on the NameErrors
    return 1

#and now we can decorate stuff...                                     

@requires_permission('administrator')
def delete_user(iUserId):
   """
   delete the user with the given Id. This function is only accessible to users with administrator permissions
   """

@requires_permission('logged_in')
def new_game():
    """
    any logged in user can start a new game
    """
    
@requires_permission('premium_member')
def premium_checkpoint():
   """
   save the game progress, only accessable to premium members
   """


***************************
Remove duplicates in list *
***************************
from collections import OrderedDict
list(OrderedDict.fromkeys('abracadabra', None)) # from iterable as keys, plus None as default value


*****************************
floating point calculations *
*****************************

    - repr() would print as many as necessary to make eval(repr(f)) == f

    - str() fewer digits printed

 
*********************
xrange() vs range() *
*********************

    - xrange is a seq obj that evaluates lazily (xrange(x).__iter__() is a generator)


******
list *
******

    - Dynamically allocated variable-length arrays, The implementation uses a contiguous array of references to other objects, and keeps a pointer to this array and the arrays length in a list head structure.

    - This makes indexing a list a[i] an operation whose cost is independent of the size of the list or the value of the index.
 

************
dictionary *
************

    - resizable hash tables

    - built-in hash()

    - key must be immutable


****************************
interface spec enforcement *
****************************

    - Python 2.6 adds an abc module that lets you define Abstract Base Classes (ABCs). You can then use isinstance() and issubclass() to check whether an instance or a class implements a particular ABC. The collections module defines a set of useful ABCs such as Iterable, Container, and MutableMapping

    - testing


*******
go-to *
*******

    - raise exception and use try-except to jump


*****
GIL *
*****

    - underlying its just pthread running whatever its callable is specifed: run()

    - interpreter keeps a global variable pointing to the currently running thread structure

    - threads hold the GIL for CPU operations but release it when blocking for I/O

    - CPU-bound threads do have periodic "check"s (Control-C like signals are captured)

    - each check is a certain amount of ticks, and ticks are uninterruptible (say by Control-C)

    - that thread sends periodically checks to OS and let OS decide whether we do context switch or not

 
*****
dis *
*****

    - dissassemble python source code

 
*************
OrderedDict *
*************

    - dict + doubly linked list

 
*****************
closure example *
*****************

    - debugging info, begin & end


*******************************
contextmanager function/class *
*******************************

    - runtime

 
***********************
functools & itertools *
***********************

    - functools.partial

