<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=EUC-KR">
<title>JSP ���� membervar.jsp</title>
</head>
<body>
	<% int i = 0; %>
	[��������] i = <%= ++i %>
	<p>
	<%! int memi = 0; %>
	[�ҼӺ���] memi = <%= ++memi %>
	
</body>
</html>