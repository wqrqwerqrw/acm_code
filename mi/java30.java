
import java.math.*;
import java.util.*;

public class java30 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BigInteger a = scanner.nextBigInteger();
        String s = a.toString(2);
        while(s.length() < 32){
            s = "0" + s;
        }
        s = new StringBuffer(s).reverse().toString();
        BigInteger b = new BigInteger(s, 2);
        String out = b.toString(10);
        System.out.println(out);
        scanner.close();
    }
}
