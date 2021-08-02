<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>JSP 예제 : score.jsp</title>
</head>
<body>
	<h2>JavaBean를 이용한 학생의 이름, 성적의 저장과 조회 예제</h2>
	<jsp:useBean id="score" class="javabean.ScoreBean" scope="page"/>
	<hr>
	<h3>이름과 성적을 JavaBean ScoreBean에 저장</h3><p></p>
	이름 : <%="홍길동" %>,
	성적 : <%="78" %><p></p>
	<jsp:setProperty name="score" property="name" value="홍길동"/>
	<jsp:setProperty name="score" property="point" value="78"/>
	<hr>
	<h3>JavaBean ScoreBean에 저장된 정보를 조회 출력</h3><p></p>
	이름 : <jsp:getProperty name="score" property="name"/><br>
	성적 : <jsp:getProperty name="score" property="point"/><br>
</body>
</html>