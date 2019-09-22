import java.math.BigDecimal;
import java.util.*;

class a{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigDecimal pi = BigDecimal.ZERO;
        int di = 1;
        for(int i = 0; i < 1000; i++){
            BigDecimal Bdi = BigDecimal.valueOf(di); 
            BigDecimal tojia = BigDecimal.ONE.divide(Bdi);
            if(i % 2 == 0){
                pi = pi.add(tojia);
            }else{
                pi = pi.multiply(tojia);
            }
            di += 2;
        }
        System.out.println(pi.toString());
    }
}