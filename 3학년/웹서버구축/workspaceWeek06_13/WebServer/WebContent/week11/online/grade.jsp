<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>JSP ���� : grade.jsp</title>
</head>
<body>
	<h2>JavaBean�� �̿��� �л��� ������ ���� ���� ó�� ����</h2>
	<%request.setCharacterEncoding("euc-kr"); %>
	<jsp:useBean id="score" class="javabean.GradeBean" scope="page"/>
	<hr>
	<h3>������ ���޹��� �̸��� ������ JavaBean GradeBean�� ����</h3>
	�̸� : <%=request.getParameter("name") %>,
	���� : <%=request.getParameter("point") %><p></p>
	<jsp:setProperty name="score" property="name" param="name"/>
	<jsp:setProperty name="score" property="point" param="point"/>
	<hr>
	<h3>JavaBean GradeBean�� ����� ������ ��ȸ ���</h3>
	�̸� : <jsp:getProperty name="score" property="name"/><br>
	���� : <jsp:getProperty name="score" property="point"/><br>
	��� : <jsp:getProperty name="score" property="grade"/><br>
</body>
</html>