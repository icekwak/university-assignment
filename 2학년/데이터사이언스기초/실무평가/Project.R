#문제1
#작업할 폴더 위치
getwd()
setwd("D:/Rfile")
getwd()

#csv파일 불러오기
data = read.csv(file="data.csv",header=T)
team = read.csv(file="team.csv",header=T)
menu = read.csv(file="menu.csv",header=T)

#문제2
t = table(data$"메뉴명"); t
menu_cnt = as.data.frame(t); menu_cnt
colnames(menu_cnt) = c("메뉴명","수량")
menu_new = merge(menu,menu_cnt,by="메뉴명")
menu_new = menu_new[order(menu_new$"수량", decreasing=T),]

#문제3
colnames(team) = c("본부","소속팀")
data_new = merge(data,team,by="소속팀")
data_new = merge(data_new,menu,by="메뉴명")

bon = as.character(data_new$본부); bon
dan = gsub(",","",data_new$단가.원.); dan
dan = as.numeric(dan); dan

temp = tapply(dan,bon,sum); temp
team_sum = as.data.frame(temp)
colnames(team_sum) = "금액.원."