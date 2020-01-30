import java.math.BigInteger;
import java.util.*;

class f{
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        BigInteger bigint[] = new BigInteger [160];
        bigint[1] = new BigInteger("4");
        bigint[2] = new BigInteger("14");
        for(int i = 3; i < 155; i++){
            bigint[i] = bigint[i-1].multiply(BigInteger.valueOf(4)).subtract(bigint[i-2]);
        }
        int t;
        t = cin.nextInt();
        while(t>0){
            t = t-1;
            BigInteger n;
            n = cin.nextBigInteger();
            for (int i = 1; i < 150; i++) {
                if (bigint[i].compareTo(n) == 1 || bigint[i].compareTo(n) == 0) {
                    System.out.println(bigint[i].toString());
                    break;
                }
            }
        }
    }
}