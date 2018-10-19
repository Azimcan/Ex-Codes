public class fibonacci{
	static void dongu(){
		int a = 1;
		int b = 1;
		int c;
		System.out.println(a);
		System.out.println(b);
		for (int i=0; i<10; i++){
			c = a+b;
			a = b;
			b = c;
			System.out.println(c);
		}
	}
	static void dizi(){
		int fib[] = new int [10];
		fib[0] = 1;
		fib[1] = 1;
		for (int i=0; i<8; i++){
			fib[i+2] = fib[i+1] + fib[i];
		}
		for(int i=0; i<10; i++){
			System.out.println(fib[i]);
		}
	}

	static int fib(int n){
		if(n == 0) return 1;
		if(n == 1) return 1;

		return fib(n-1) + fib(n-2);
	}

	public static void main(String[] args){
		//dongu();
		//dizi();
		for (int i=0; i<10 ; i++){
			System.out.println(fib(i));
		}
	}
}