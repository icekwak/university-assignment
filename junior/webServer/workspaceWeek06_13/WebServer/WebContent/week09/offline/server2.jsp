<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>

<%
	request.setCharacterEncoding("euc-kr");

	String id = request.getParameter("id");
	String pw = request.getParameter("pw");
	
	if(id.equals("������") && pw.equals("1234")){
		out.println("�̸�: " + id + "<p></p>");
		out.println("Ŭ���̾�Ʈ IP: " + request.getRemoteAddr() + "<p></p>");
		out.println("��û ���� ����: " + request.getContentLength() + "<p></p>");
		out.println("��û ���� ���۹��: " + request.getMethod() + "<p></p>");
		out.println("��û URI: " + request.getRequestURI() + "<p></p>");
		out.println("���� �̸�: " + request.getServerName() + "<p></p>");
		out.println("���� ��Ʈ: " + request.getServerPort() + "<p></p>");
	}
	else
		out.println("[" + id + "]���� �����ڰ� �ƴմϴ�.");
%>