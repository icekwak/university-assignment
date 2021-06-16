<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
	<h3>학생 정보 입력</h3>
	<form method="post" action="p2From.jsp">
		<div>성명 : <input type="text" name="name"></div>
		<div>학번 : <input type="text" name="number"></div>
		<div>
			성별 : 
			남자 <input type="radio" name="sex" value="남자"> 
			여자 <input type="radio" name="sex" value="여자">
		</div>
		<div>
			<select name="nationality">
				<option value="대한민국" selected>대한민국</option>
				<option value="미국">미국</option>
				<option value="영국">영국</option>
			</select>
		</div>				
		<div><input type="submit" value="보내기"></div>
	</form>
</body>
</html>