<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html charset=EUC-KR">
<title>JSP ���� autoflush.jsp</title>
</head>
<body>
	<%@ page autoFlush="false" buffer="1kb" %>
	<h2>���� autoFlush = <%= out.isAutoFlush() %></h2><p>
	<%
		for(int i=1; i<25; i++){
			out.println("���� ��� ���� ũ��(out.getRemaining()) : " + out.getRemaining() + "<br>");
			if(out.getRemaining() < 50){
				out.println("<br>");
				out.flush();
			}
		}
	%>
	<hr>
	�ʱ� ��� ���� ũ�� : <%= out.getBufferSize() %> byte<br>
	���� ��� ���� ũ�� : <%= out.getRemaining() %> byte
</body>
</html>