// package luogu;

import java.math.BigInteger;
import java.util.Scanner;

/**
 * java1604
 */
public class java1604 {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int B = sc.nextInt();
    BigInteger a = sc.nextBigInteger(B);
    BigInteger b = sc.nextBigInteger(B);
    System.out.println(a.add(b).toString(B).toUpperCase());
  }
}