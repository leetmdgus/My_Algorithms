## 삽입 정렬 (Insertion Sort)



+ 삽입 정렬을 이용해 정렬 문제를 풀기위해 문제를 다음과 같이 정의한다. 

![image-20220406182714171](C:\ALGORITHMS\Divide and Conquer\image-20220406182714171.png)





+ 의사코드

```
INSERTION-SORT(A)
for j = 2 to A.length
	key = A[j]
	//A[j]를 정렬된 배열 A[1, ... , j-1]에 삽입한다.
	i = j-1
	while i > 0 그리고 A[i] > key
    	A[i+1] = A[i]
    	i = i - 1
    A[i+1] = key
```





