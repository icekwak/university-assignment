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
		
		out.println("<h3>학생 정보 입력 결과</h3>");
		out.println("성명 : " + name + "<br>");
		out.println("학번 : " + number + "<br>");
		out.println("성별 : " + sex + "<br>");
		out.println("국적 : " + nationality + "<br>");
	%>
</body>
</html>