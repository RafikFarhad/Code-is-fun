import java.math.BigInteger;
import java.util.Scanner;


class Main{

    public static void main(String args[]){


    	Scanner SS = new Scanner(System.in);
    	int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103};

    	BigInteger a, b, zero = new BigInteger("0"), one = new BigInteger("1");
    	int i, j;
    	for(j=0; j<20; j++){

    		a = SS.nextBigInteger();
    		b = one;
    		
    		for(i=0; ; i++)
    		{
    			b = b.multiply(new BigInteger(Integer.toString(prime[i])) );
    			//System.out.println(b);
    			if(b.compareTo(a)==1)
    				break;
    		}
    		b = b.divide(new BigInteger(Integer.toString(prime[i])) );
    		System.out.println(b);

    	}
    }

}
