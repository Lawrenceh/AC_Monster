# boolean indices
print ("a is odd", "a is even")[a % 2 == 0]

my_list = [1, 7, 11, 8, 13, 2]
[("odd", "even")[i % 2 == 0] for i in my_list]

# dict.get()
numbers = {1: 'one', 2:'two', 3:'three'}
print numbers.get(1, 'Number not defined')

my_string = "I want to get the counts for each letter in this sentence"
counts = {}

for letter in my_string:
    # no need to use has_key() judgement
    counts[letter] = counts.get(letter, 0) + 1
print counts

# enumerate counting start
a = ['two', 'three', 'four']
for i, word in enumerate(a, 2):
    print i, word

# list comprehension
d = ['a', 'b', 'c', 'd']
[a + b + c for a in d for b in d for c in d]

# string formatting
def roundTo(n, dp):
    s = "%%.%df" % dp
    return s % n

print roundTo(3.1415927, 3)
# tricky way of formatting
"{0:.3f}".format(n)
"{0:.{1}f}".format(n, dp)

# sorting by attributes
my_list.sort(key = lambda x: x.score)
# sorting by values
sorted_keys = sorted(my_dict.keys(), key=lambda x: my_dict[x])
for k in sorted_keys:
    print my_dict[k]
# tricky way of sorting by values
for k, v in sorted(my_dict.items(), key=lambda (k,v): v):
    print k, v

# zipping and rezipping lists
for i, j in zip(list1, list2):
    print i, j
# use zip to rotate 90 degrees
# (a, 1), (b, 2), (c, 3) -> (a, b, c), (1, 2, 3)
rows = [line.rstrip().split('\t') for line in file(filename)]
columns = zip(*rows)

# if/else and/or expressions in Python
if n < 0:
    result = 'n is negative'
else:
    result = 'n is positive'

result = n < 0 and 'n is negative' or 'n is positive'
result = test and true_result or false_result

# lambda functions
out = lambda *x: " ".join(map(str, x))
out(3, 4, "test", 2)

# swap elements in a list
def swap(a, x, y):
    a[x] = (a[x], a[y])
    a[y] = a[x][0]
    a[x] = a[x][1]

swap = lambda a, x, y: (lambda f = a.__setitem__: (f(x, (a[x], a[y])), f(y, a[x][0]), f(x, a[x][1])))()
swap(list, 1, 3) # indices

# print strings
print "Spam" + " eggs" + " and" + " spam"               # DON'T DO THIS
print " ".join(["Spam","eggs","and","spam"])            # Much faster/more
print "%s %s %s %s" % ("Spam", "eggs", "and", "spam")   # Also a pythonic way of
                                                        # doing it - very fast



