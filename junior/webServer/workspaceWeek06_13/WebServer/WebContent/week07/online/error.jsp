<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html charset=EUC-KR">
<title>JSP ���� error.jsp</title>
</head>
<body>
	<%@ page isErrorPage="true" %>
	<% response.setStatus(response.SC_OK); %> <%-- http 500 error �ذ��� --%>
	<h1>����ó�� ������</h1>
	���� ���ڿ�[exception.toString()] : <%= exception.toString() %><br>
	���� �޼���[exception.getMessage()] : <%= exception.getMessage() %><br>
</body>
</html>