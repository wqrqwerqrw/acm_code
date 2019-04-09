import java.util.*;
import java.math.*;

public class test{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String i = in.next();
        BigInteger a = new BigInteger(i, 2);
        System.out.println(a.toString(16));
        in.close();
    }
}