<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>JSP ���� : score.jsp</title>
</head>
<body>
	<h2>JavaBean�� �̿��� �л��� �̸�, ������ ����� ��ȸ ����</h2>
	<jsp:useBean id="score" class="javabean.ScoreBean" scope="page"/>
	<hr>
	<h3>�̸��� ������ JavaBean ScoreBean�� ����</h3><p></p>
	�̸� : <%="ȫ�浿" %>,
	���� : <%="78" %><p></p>
	<jsp:setProperty name="score" property="name" value="ȫ�浿"/>
	<jsp:setProperty name="score" property="point" value="78"/>
	<hr>
	<h3>JavaBean ScoreBean�� ����� ������ ��ȸ ���</h3><p></p>
	�̸� : <jsp:getProperty name="score" property="name"/><br>
	���� : <jsp:getProperty name="score" property="point"/><br>
</body>
</html>