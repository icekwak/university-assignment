<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
	<h3>�л� ���� �Է�</h3>
	<form method="post" action="p2From.jsp">
		<div>���� : <input type="text" name="name"></div>
		<div>�й� : <input type="text" name="number"></div>
		<div>
			���� : 
			���� <input type="radio" name="sex" value="����"> 
			���� <input type="radio" name="sex" value="����">
		</div>
		<div>
			<select name="nationality">
				<option value="���ѹα�" selected>���ѹα�</option>
				<option value="�̱�">�̱�</option>
				<option value="����">����</option>
			</select>
		</div>				
		<div><input type="submit" value="������"></div>
	</form>
</body>
</html>