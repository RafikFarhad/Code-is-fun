import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    static Scanner S = new Scanner(System.in);

    public static void main(String args[]){

        String p;
        int t;
        t = S.nextInt();
        BigInteger a, b;
        while(t>0){
            t--;
            a = S.nextBigInteger();
            b = S.nextBigInteger();
            a.sum(b);
            System.out.println(a);
        }
    }
}

}
