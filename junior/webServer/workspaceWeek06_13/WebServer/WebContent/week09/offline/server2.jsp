<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>

<%
	request.setCharacterEncoding("euc-kr");

	String id = request.getParameter("id");
	String pw = request.getParameter("pw");
	
	if(id.equals("나관리") && pw.equals("1234")){
		out.println("이름: " + id + "<p></p>");
		out.println("클라이언트 IP: " + request.getRemoteAddr() + "<p></p>");
		out.println("요청 정보 길이: " + request.getContentLength() + "<p></p>");
		out.println("요청 정보 전송방식: " + request.getMethod() + "<p></p>");
		out.println("요청 URI: " + request.getRequestURI() + "<p></p>");
		out.println("서버 이름: " + request.getServerName() + "<p></p>");
		out.println("서버 포트: " + request.getServerPort() + "<p></p>");
	}
	else
		out.println("[" + id + "]님은 관리자가 아닙니다.");
%>