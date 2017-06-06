import java.util.ArrayList;

import javax.swing.JFrame; 
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException; 
   
  public class gui extends JFrame 
  { 
	  public static ArrayList<person> pList = new ArrayList<>();
  	public static void main(String[] args) 
  	{ 
  		try {
  			UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (InstantiationException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (UnsupportedLookAndFeelException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
  		 MainGui m = new MainGui(); 
  	} 
   
  } 
  