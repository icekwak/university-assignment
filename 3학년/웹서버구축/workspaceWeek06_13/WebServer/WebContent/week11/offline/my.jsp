<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%
	Cookie[] cookies = request.getCookies();
	Boolean access_ok = false;
	
	if(cookies != null && cookies.length > 0){
		for(int i=0; i<cookies.length; i++){
			if(cookies[i].getName().equals("member_ok"))
				access_ok = true;
		}
	}
	
	if(access_ok){
		out.println("�������� �������� ���Ű� ȯ���մϴ�.<p>");
		out.println("<a href=logout.jsp>" + "�α׾ƿ��մϴ�.<a><br>");
	}else
		out.println("�α��� ���ּ���.<br>");
%>