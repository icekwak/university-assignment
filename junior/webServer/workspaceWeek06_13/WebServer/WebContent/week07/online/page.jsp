<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html charset=EUC-KR">
<title>JSP 예제 page.jsp</title>
</head>
<body>
	<%@ page info="내장 객체page : page 자기 자신의 객체" %>
	<%= this.getServletInfo() %><p>
	<%= ((org.apache.jasper.runtime.HttpJspBase) (page)).getServletInfo() %>
</body>
</html>