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
		
		out.println("<b>[" + user_id + "]<b>님 반갑습니다.<p>");
		out.println("<a href=my.jsp>" + user_id + "님의 관리 페이지로 이동합니다.</a><br>");
		out.println("<a href=logout.jsp>" + "로그아웃합니다.</a><br>");
	}
	else
		out.println("<script>" + "alert('아이디와 패스워드가 다릅니다.');" + "history.back();" + "</script>");
%>