a=input()
for i in range(len(a)):
    if str(a[i]).isalpha()&str(a[i+1]).isaplha():
        print(" ",end='')
    print(a[i],end='')
