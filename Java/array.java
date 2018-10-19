public class array{

	public static int f(int x) {
		if(x == 10) return 10;
		System.out.println("x: " + x)
		return x+
	}

	public static void main(String[] args){

		int a[] = new int[46];
		a[0] = 1;
		a[1] = 1;

		for (int i = 0; i < 44; i++) {
			a[i+2] = a[i+1] + a[i];
			
		}
		for (int i = 0; i < 46; i++) {
			System.out.println(a[i]);
			
		}
	}
}