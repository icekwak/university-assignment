<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
	<%
		request.setCharacterEncoding("euc-kr");
	
		String name = request.getParameter("name");
		String number = request.getParameter("number");
		String sex = request.getParameter("sex");
		String nationality = request.getParameter("nationality");
		
		out.println("<h3>�л� ���� �Է� ���</h3>");
		out.println("���� : " + name + "<br>");
		out.println("�й� : " + number + "<br>");
		out.println("���� : " + sex + "<br>");
		out.println("���� : " + nationality + "<br>");
	%>
</body>
</html>