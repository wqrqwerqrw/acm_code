package test;

import java.util.*;
import java.math.*;

public class test{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger a = in.nextBigInteger();
        System.out.println(a.toString(3));
        in.close();
    }
}