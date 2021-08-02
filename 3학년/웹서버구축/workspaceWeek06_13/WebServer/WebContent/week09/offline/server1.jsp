<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>

<%
	request.setCharacterEncoding("euc-kr");

	String id = request.getParameter("id");
	String pw = request.getParameter("pw");
	
	out.println("아이디: " + id + "<p></p>");
	out.println("비밀번호: " + pw + "<p></p>");
%>