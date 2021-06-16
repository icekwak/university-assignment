<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>

<%
	request.setCharacterEncoding("euc-kr");

	String name = request.getParameter("name");
	String number = request.getParameter("number");
	String sex = request.getParameter("sex");
	String Nationality = request.getParameter("Nationality");
	
	out.println("<h3>학생 정보 입력 결과</h3>");
	out.println("성명: " + name + "<p></p>");
	out.println("학번: " + number + "<p></p>");
	out.println("성별: " + sex + "<p></p>");
	out.println("국적: " + Nationality + "<p></p>");
%>