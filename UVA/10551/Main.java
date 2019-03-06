import java.util.*;
import java.math.*;

class Main{

	static Scanner SS = new Scanner(System.in);

	public static void main(String[] args){

		String m, p;
		BigInteger mm, pp;
		int base;

		while(true){
			base = SS.nextInt();
			if(base==0)
				break;
			// p = SS.nextLine();
			// m = SS.nextLine();
			pp = SS.nextBigInteger(base);
			mm = SS.nextBigInteger(base);


			// p_ = new BigInteger(p, base);
			// m_ = new BigInteger(m, base);

			System.out.println(pp.mod(mm).toString(base));
		}


	}

}