<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>

<%
	request.setCharacterEncoding("euc-kr");

	String name = request.getParameter("name");
	String number = request.getParameter("number");
	String sex = request.getParameter("sex");
	String Nationality = request.getParameter("Nationality");
	
	out.println("<h3>�л� ���� �Է� ���</h3>");
	out.println("����: " + name + "<p></p>");
	out.println("�й�: " + number + "<p></p>");
	out.println("����: " + sex + "<p></p>");
	out.println("����: " + Nationality + "<p></p>");
%>