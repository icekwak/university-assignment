<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=EUC-KR">
<title>JSP ���� declaration.jsp</title>
</head>
<body>
	<%! double radius = 4.8; %>
	<%!
		public double getArea(double r){
			return r * r * 3.14;
		}
	%>
	�������� <%= radius %>�� ���� ������ <%= getArea(radius) %>�̴�.
</body>
</html>