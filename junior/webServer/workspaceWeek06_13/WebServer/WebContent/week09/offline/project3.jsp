<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
  
<%@ page import="java.util.Date"%>
<%
	out.println("<p>이 페이지는 5초마다 새로고침 됩니다.</p>");
	response.setIntHeader("Refresh", 5);
	out.println(new java.util.Date());
%>