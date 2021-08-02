#절댓값 함수
abs(10)
abs(-10)
#로그함수 함수
log(2,base = 3)
#밑이 2인 로그함수 함수
log2(5)
#상용로그함수 함수
log10(2)
#팩토리얼 함수
factorial(4)
#조합 함수
choose(6,2)
#제곱근 함수
sqrt(4)
#소숫점 n자리로 반올림하는 함수
round(5.45,digits=1)
#바닥정수 함수(작거나 같은 정수)
floor(5)
#지붕정수 함수(크거나 같은 정수)
ceiling(5)
#소숫점 이하는 잘라서 버리는 함수
trunc(5.36)


x = c(NA,NaN,Inf,-Inf)
#무한대가 있으면 True를 반환하는 함수
is.infinite(x)
#결측값이 있으면 True를 반환하는 함수(NaN도 True로 인식)
is.na(x)
#수학적으로 정의되지 않은 Not a Number있으면 True를 반환하는 함수
is.nan(x)


y = c(1:10)
#누적합 함수
cumsum(y)
#누적곱 함수
cumprod(y)
#누적최댓값 함수
cummax(y)
#누적최솟값 함수
cummin(y)
#관측값에서 직전 관측값을 뺀 차분을 구하는 함수
z = c(1,5,9)
diff(z)


a = c(1,2,3,4,5)
b = c(1,3,5)
c = c(1,3,5)
#합집합 함수
union(a,b)
#교집합 함수
intersect(a,b)
#차집합 함수
setdiff(a,b)
#같은지 확인하는 함수
setequal(a,b)
setequal(b,c)
#동일한 원소가 있는지 확인하는 함수
is.element(a,b)
is.element(b,a)