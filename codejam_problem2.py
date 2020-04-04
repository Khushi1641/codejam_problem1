test=int(input())
s=[]
for i in range(test):
  s1=input()
  s.append(s1)
for i in range(test):
    y=0
    st=list(s[i])
    while y<(len(st)-1):
        z=int(st[y])-int(st[y+1])
        if z>0:
            w=1
            while w!=(z+1):
                st.insert(y+w,')')
                w=w+1
        elif z<0:
            w=1
            while w!=(abs(z)+1):
                st.insert(y+w,'(')
                w=w+1
        y=y+abs(z)
        y=y+1
    a=int(st[0])
    b=int(st[-1])
    while a!=0:
        st.insert(0,'(')
        a=a-1
    while b!=0:
        st.append(')')
        b=b-1
    s[i]="".join(st)
for i in range(len(s)):
    print("case #"+str(i+1)+": "+s[i])