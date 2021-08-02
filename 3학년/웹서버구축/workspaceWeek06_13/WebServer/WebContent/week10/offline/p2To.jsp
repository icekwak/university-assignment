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
		
		out.println("1) 관리자 : " + manager + "<br>");
		out.println("2) 현재 접속시간 : " + new java.util.Date() + "<br>");
		out.println("-------------------------------<br>");
		out.println("학생 정보 입력 결과 <br>");
		out.println("<p></p>");
		out.println("성명 : " + name + "<br>");
		out.println("학번 : " + number + "<br>");
		out.println("성별 : " + sex + "<br>");
		out.println("국적 : " + nationality + "<br>");
		out.println("-------------------------------<br>");
		out.println("수고하셨습니다. <br>");
	%>
</body>
</html>