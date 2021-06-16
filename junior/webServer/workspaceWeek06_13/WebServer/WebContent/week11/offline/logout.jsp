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
		for(int i=0; i<cookies.length; i++){
			cookies[i].setMaxAge(0);
			response.addCookie(cookies[i]);
		}
		out.println("<script>" + "alert('로그아웃되었습니다.');" + "location.href='login.jsp'" + "</script>");
	}else
		out.println("로그인 해주세요.<br>");
%>