<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
	<%@ page import="java.util.Date" %>
	<%
		request.setCharacterEncoding("euc-kr");
	
		String manager = request.getParameter("manager");
		String name = request.getParameter("name");
		String number = request.getParameter("number");
		String sex = request.getParameter("sex");
		String nationality = request.getParameter("nationality");
		
		out.println("1) ������ : " + manager + "<br>");
		out.println("2) ���� ���ӽð� : " + new java.util.Date() + "<br>");
		out.println("-------------------------------<br>");
		out.println("�л� ���� �Է� ��� <br>");
		out.println("<p></p>");
		out.println("���� : " + name + "<br>");
		out.println("�й� : " + number + "<br>");
		out.println("���� : " + sex + "<br>");
		out.println("���� : " + nationality + "<br>");
		out.println("-------------------------------<br>");
		out.println("�����ϼ̽��ϴ�. <br>");
	%>
</body>
</html>