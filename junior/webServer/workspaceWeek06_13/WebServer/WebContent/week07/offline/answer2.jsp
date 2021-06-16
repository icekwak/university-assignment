<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Scripting tag</title>
</head>
<body>
	<%!
		public String makeItLower(String str){
			String s = str.toLowerCase();
		return s;
		}
	%>
	<%
		out.println(makeItLower("Hello World")+"<br>");
	    out.println("Hello World".toUpperCase());
	%>
</body>
</html>