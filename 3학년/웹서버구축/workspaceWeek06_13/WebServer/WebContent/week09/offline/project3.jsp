<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
  
<%@ page import="java.util.Date"%>
<%
	out.println("<p>�� �������� 5�ʸ��� ���ΰ�ħ �˴ϴ�.</p>");
	response.setIntHeader("Refresh", 5);
	out.println(new java.util.Date());
%>