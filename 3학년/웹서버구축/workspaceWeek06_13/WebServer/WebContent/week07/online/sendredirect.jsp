<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html charset=EUC-KR">
<title>JSP 예제 sendredirect.jsp</title>
</head>
<body>
	<%
		String URL = "http://search.naver.com/search.naver?where=nexearch";
		String keyword = request.getParameter("word");
		URL += "&" + "query=" + keyword;
		response.sendRedirect(URL);
	%>
</body>
</html>