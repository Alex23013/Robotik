m=[1,7,4]
n=[2,3,3]
def dot_product(m,n):
    b=0
    for i in range(0,len(n)):
        a=m[i]*n[i]
        b=b+a
    print b
print m
print n
print "this is the answer"
dot_product(m,n)
