<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>

<%
	request.setCharacterEncoding("euc-kr");

	String id = request.getParameter("id");
	String pw = request.getParameter("pw");
	
	out.println("���̵�: " + id + "<p></p>");
	out.println("��й�ȣ: " + pw + "<p></p>");
%>