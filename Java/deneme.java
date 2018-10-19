import java.util.Scanner;

public class deneme{

	static int matrisCreat(){
		int[][] matris = new int[10][10];
		
		for(int i=0; i<10;i++){
			for(int j=0; j<10; j++){
				if(i == j){
					System.out.print(1 + "  ");
				}
				else{
					System.out.print(0 + "  ");
				}
			}
			System.out.println("");
		}
	}

	public static void main(String[] args) {
		Scanner sabit = new Scanner(System.in);

		matrisCreat()
		
	}
}