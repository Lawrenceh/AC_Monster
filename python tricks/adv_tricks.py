# reduce
print reduce(lambda(a, b), c: (a + [c], b) if c > 60 else (a, b + [c]), [49, 58, 76, 82, 88, 90], ([], []))

def reduce(function, iterable, initializer=None):
    it = iter(iterable)
    if initializer is None:
        try:
            initializer = next(it)
        except StopIteration:
            raise TypeError('reduce() of empty sequence with no initial value')
    accum_value = initializer
    for x in it:
        accum_value = function(accum_value, x)
    return accum_value

# sum on lists
print sum([[1, 2, 3], [4, 5], [6, 7, 8]], [])
reduce(list.__add__, [[1, 2, 3], [4, 5], [6, 7, 8]], [])

print sorted(set(range(2,n+1)).difference(set((p * f) for p in range(2,int(n**0.5) + 2) for f in range(2,(n/p)+1))))
