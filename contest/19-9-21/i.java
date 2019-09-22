import java.math.BigInteger;
import java.util.Scanner;

class i {
    public static void main(String[] args) {
        int t;
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();
        while (t > 0) {
            t--;
            BigInteger a = sc.nextBigInteger();
            BigInteger b = sc.nextBigInteger();
            BigInteger c = sc.nextBigInteger();
            BigInteger d = sc.nextBigInteger();
            BigInteger out = BigInteger.ZERO;
            out = out.add(a);
            out = out.add(b);
            out = out.add(c);
            out = out.add(d);
            System.out.println(out.toString());
        }
        sc.close();
    }
}