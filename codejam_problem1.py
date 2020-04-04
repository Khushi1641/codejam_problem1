
import numpy as np
import array as a
test=int(input())
ans=a.array('i',[])
mat=[]
row_count=0
col_count=0
flag=0

count_r=0
count_c=0
for r in range(test):
  size=int(input())
  for i in range(size):
    rowi=input()
    row_i=rowi.split(' ')
    for j in range(len(row_i)):
      count_r=row_i.count(row_i[j])
      if count_r>1:
        flag=1
    if flag==1:
      row_count=row_count+1
      flag=0
    else:
      flag=0

    mat.append(row_i)
  d_sum=0
  for j in range(size):
    d_sum=d_sum+int(mat[j][j])
  mat_c=np.rot90(mat)

  for i in range(size):
    col=mat_c[i].tolist()
    for j in range(size):
      count_c=col.count(col[j])
      if count_c>1:
        flag=1
    if flag==1:
      col_count=col_count+1
      flag=0
    else:
      flag=0
  ans=np.append(ans,d_sum)
  ans=np.append(ans,row_count)
  ans=np.append(ans,col_count)
  mat=[]
  row_count=0
  col_count=0
ind=0
cas=1
while cas<=test:
    print('Case #{0}: {1} {2} {3}'.format(cas,ans[ind],ans[ind+1],ans[ind+2]))
    ind+=3
    cas+=1