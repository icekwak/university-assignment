<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%
	request.setCharacterEncoding("euc-kr");

	String id= "kim";
	String pw = "1234";
	
	String user_id = request.getParameter("userid");
	String user_pw = request.getParameter("userpw");
	
	if((id.equals(user_id)) && (pw.equals(user_pw))){
		Cookie my = new Cookie("member_ok", user_id);
		response.addCookie(my);
		
		out.println("<b>[" + user_id + "]<b>�� �ݰ����ϴ�.<p>");
		out.println("<a href=my.jsp>" + user_id + "���� ���� �������� �̵��մϴ�.</a><br>");
		out.println("<a href=logout.jsp>" + "�α׾ƿ��մϴ�.</a><br>");
	}
	else
		out.println("<script>" + "alert('���̵�� �н����尡 �ٸ��ϴ�.');" + "history.back();" + "</script>");
%>