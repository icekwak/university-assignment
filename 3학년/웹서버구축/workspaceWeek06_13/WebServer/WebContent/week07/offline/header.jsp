<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>answer4 header.jsp</title>
</head>
<body>
	<%! int num = 1; %>
	<p>이 사이트 방문은 <%= num %>번째 입니다.</p>
	<% num++; %>
</body>
</html>