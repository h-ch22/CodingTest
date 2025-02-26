import java.util.*;
public class Main {
    public static void main(String[] args) {
           Scanner scn1 = new Scanner(System.in);
            
            int n = scn1.nextInt();
            
            int remainder = n%5;
            int quotient = n/5;
            int output = 0;
            
            if(remainder == 1){
                quotient -= 1;
                output = quotient +2;
                
            }else if(remainder == 2 && n != 7){
                quotient -= 2;
                output = quotient + 4;
                
            }else if(remainder == 3){
                output = quotient +1;
                
            }else if(remainder == 4 && n != 4){
                quotient -= 1;
                output = quotient + 3;
                
            }else if(remainder ==0){
                output = quotient;
            }
            
            if(n == 4 || n == 7){
                output = -1;
            }
            
            System.out.println(output);
 
    }
 
}