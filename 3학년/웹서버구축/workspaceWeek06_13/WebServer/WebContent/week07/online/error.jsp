<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html charset=EUC-KR">
<title>JSP 예제 error.jsp</title>
</head>
<body>
	<%@ page isErrorPage="true" %>
	<% response.setStatus(response.SC_OK); %> <%-- http 500 error 해결방법 --%>
	<h1>예외처리 페이지</h1>
	오류 문자열[exception.toString()] : <%= exception.toString() %><br>
	오류 메세지[exception.getMessage()] : <%= exception.getMessage() %><br>
</body>
</html>