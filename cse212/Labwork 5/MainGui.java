import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

public class MainGui extends JFrame {
	public JButton btnNewForm;
	public JButton btnDisplay;
	
	public MainGui(){
		
		btnNewForm = new JButton("New Form");
		btnDisplay = new JButton("Display Forms");
		
		this.add(btnNewForm);	
		this.add(btnDisplay);
		
		 this.btnDisplay.addActionListener(new ActionListener() {
	 			
	 			private JFrame f;

				@Override
	 			public void actionPerformed(ActionEvent e) {
	 				for (person p : gui.pList) {
	 					f = new FormGui(p);
	 				}
	 				
	 			}
	 		});
		 
  		 this.btnNewForm.addActionListener(new ActionListener() {
			
			private JFrame f;

			@Override
			public void actionPerformed(ActionEvent e) {
				f = new FormGui();
				
			}
		});
		
		
		this.setTitle("Main Menu"); 
  		this.setLayout(new FlowLayout()); 
  		this.setBounds(50,50,500,500); 
  		this.setVisible(true); 
  		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
	}
	
	

}
