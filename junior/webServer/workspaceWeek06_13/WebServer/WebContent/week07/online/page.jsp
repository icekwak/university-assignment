<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html charset=EUC-KR">
<title>JSP ���� page.jsp</title>
</head>
<body>
	<%@ page info="���� ��üpage : page �ڱ� �ڽ��� ��ü" %>
	<%= this.getServletInfo() %><p>
	<%= ((org.apache.jasper.runtime.HttpJspBase) (page)).getServletInfo() %>
</body>
</html>