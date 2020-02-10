// package luogu;

import java.math.BigInteger;
import java.util.*;

/**
 * java1255
 */
public class java1255 {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    BigInteger[] f = new BigInteger[10000];
    f[0] = new BigInteger("0");
    f[1] = new BigInteger("1");
    f[2] = new BigInteger("2");
    for(int i = 3; i < 10000; i++){
      f[i] = f[i-1].add(f[i-2]);
    }
    System.out.println(f[n].toString());
  }
}