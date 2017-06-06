import java.util.Scanner;

public class MasterMind
{
	public static int guess;
    public static Map map = new Map();
    public static Scanner s = new Scanner(System.in);
    
    public static void main(String[] args)
    {
    	long time = System.currentTimeMillis();
    	byte wc;
        for (int i = 0; i < 10000; i++) {
        	
			Player.setNumber(i);
			
			System.out.println("number: "+i);
			guess=1234;
			wc=Player.getCW(guess);
			MasterMind.map.first(wc);
			System.out.println(guess+"\tcurrent:"+(wc>>3)+"\twrong:"+(wc&7));
			
        	 do {
             	guess = map.list[map.count/2];
             	wc=Player.getCW(guess);
             	map.fillList(wc, guess);
             	System.out.println(guess+"\tcurrent:"+(wc>>3)+"\twrong:"+(wc&7));
     		} while (wc>>3!=4);
		}      
        System.out.println("timefor 0 to 9999: "+(System.currentTimeMillis()-time)+" miliseconds");

    }
   

}