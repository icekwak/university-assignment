public class FindPath {
	// 0000 = no path
	// 1000 = can go left
	//  100 = can go right
	//   10 = can go up
	//    1 = can go down
	// 문제를 쉽게하기 위해, 1개의 cell 에서는 한 방향으로만 이동이 가능
	public static void main(String[] args) {
		int[][] map1 = { {   0,  100, 0},
						 { 100,   10, 0},
						 {  10,    0, 0}}; // there IS a path from Start to Finish
		int[][] map2 = { {   0, 1000, 0},
						 { 100,   10, 0},
						 {  10,    0, 0}}; // there is NO such a path
		int nROW = 3;
		int nCOL = 3;
		
		int startY = 2, startX = 0;
		int finishY = 0, finishX = 2;
		
		if( findPath(map1, ...) == 1 )
			System.out.println("map1: Found a path!");
		else
			System.out.println("map1: There is no path!");
		
		if( findPath(map2, ...) == 1 )
			System.out.println("map2: Found a path!");
		else
			System.out.println("map2: There is no path!");
		
	}
	...
}