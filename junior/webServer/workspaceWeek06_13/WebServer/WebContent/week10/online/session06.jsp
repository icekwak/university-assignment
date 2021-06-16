<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Session</title>
</head>
<body>
	<p><h4>----- 세션을 삭제하기 전 -----</h4>
	<%
		String user_id = (String)session.getAttribute("userID");
		String user_pw = (String)session.getAttribute("userPW");
		
		out.println("설정된 세션 이름 userID : " + user_id + "<br>");
		out.println("설정된 세션 값 userPW : " + user_pw + "<br>");
		
		if(request.isRequestedSessionIdValid() == true)
			out.println("세션이 유효합니다.");
		else
			out.println("세션이 유효하지 않습니다.");
		
		session.invalidate();
	%>
	<p><h4>----- 세션을 삭제하한 후 -----</h4>
	<%
		if(request.isRequestedSessionIdValid() == true)
			out.println("세션이 유효합니다.");
		else
			out.println("세션이 유효하지 않습니다.");
	%>
</body>
</html>