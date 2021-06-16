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
		out.println("관리자의 페이지에 오신걸 환영합니다.<p>");
		out.println("<a href=logout.jsp>" + "로그아웃합니다.<a><br>");
	}else
		out.println("로그인 해주세요.<br>");
%>