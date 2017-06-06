import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JRadioButton;
import javax.swing.JTextField;

public class FormGui extends JFrame{
	
  	private JTextField boxName; 
  	private JTextField boxSurname; 
  
  	private ButtonGroup bg;
  	private JRadioButton rdSingle; 
  	private JRadioButton rdMarried; 
  	private JRadioButton rdDivorced; 

  	private JCheckBox chkBook; 
  	private JCheckBox chkSports; 
  	private JCheckBox chkCinema;
  	private JCheckBox chkArts; 
	public JButton btnSave; 
  	public JButton btnCancel;
  	public FormGui(){
  		getContentPane().setLayout(null);
  		
  		
  		JLabel label = new JLabel("Name");
  		label.setBounds(79, 31, 27, 14);
  		getContentPane().add(label);
  		getContentPane().add(boxName = new JTextField());
  		boxName.setBounds(116, 28, 184, 20);
  		JLabel label_1 = new JLabel("Surname");
  		label_1.setBounds(64, 56, 42, 14);
  		getContentPane().add(label_1);
  		getContentPane().add(boxSurname = new JTextField());
  		boxSurname.setBounds(116, 53, 184, 20);
  		
  		rdSingle=new JRadioButton("Single");
  		rdSingle.setBounds(79, 84, 65, 23);
  		getContentPane().add(rdSingle);
  		rdMarried=new JRadioButton("Married");
  		rdMarried.setBounds(145, 84, 65, 23);
  		getContentPane().add(rdMarried);
  		rdDivorced=new JRadioButton("Divorced");
  		rdDivorced.setBounds(215, 84, 85, 23);
  		getContentPane().add(rdDivorced);
  		
  		chkBook=new JCheckBox("Book");
  		chkBook.setBounds(76, 123, 49, 23);
  		getContentPane().add(chkBook);
  		chkSports=new JCheckBox("Sports");
  		chkSports.setBounds(127, 123, 57, 23);
  		getContentPane().add(chkSports);
  		chkCinema=new JCheckBox("Cinema");
  		chkCinema.setBounds(189, 123, 61, 23);
  		getContentPane().add(chkCinema);
  		chkArts=new JCheckBox("Arts");
  		chkArts.setBounds(255, 123, 45, 23);
  		getContentPane().add(chkArts);
  		
  		btnSave=new JButton("Save");
  		btnSave.setBounds(89, 176, 72, 23);
  		btnSave.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				boolean[] interests=new boolean[4];
				interests[0]=chkBook.isSelected();
				interests[1]=chkSports.isSelected();
				interests[2]=chkCinema.isSelected();
				interests[3]=chkArts.isSelected();
				person temp = new person(boxName.getText(),boxSurname.getText(),rdSingle.isSelected()?0:rdMarried.isSelected()?1:2,interests);
				gui.pList.add(temp);
				btnCancel.doClick(); 
				
			}
		});
  		getContentPane().add(btnSave);
  		btnCancel=new JButton("Cancel");
  		btnCancel.setBounds(183, 176, 79, 23);
  		btnCancel.addActionListener(e -> this.dispose());
  		
  		rdSingle.setSelected(true);
  		bg= new ButtonGroup();
  		bg.add(rdSingle);
  		bg.add(rdMarried);
  		bg.add(rdDivorced);
  		
  		getContentPane().add(btnCancel);
  		this.setTitle("Add Person");
  		this.setBounds(50,50,400,262); 
  		this.setVisible(true); 
  		
  		
  	}
  	public FormGui(person p){
  		
getContentPane().setLayout(null);
  		
  		
  		JLabel label = new JLabel("Name");
  		label.setBounds(79, 31, 27, 14);
  		getContentPane().add(label);
  		getContentPane().add(boxName = new JTextField());
  		boxName.setBounds(116, 28, 184, 20);
  		JLabel label_1 = new JLabel("Surname");
  		label_1.setBounds(64, 56, 42, 14);
  		getContentPane().add(label_1);
  		getContentPane().add(boxSurname = new JTextField());
  		boxSurname.setBounds(116, 53, 184, 20);
  		
  		rdSingle=new JRadioButton("Single");
  		rdSingle.setBounds(79, 84, 65, 23);
  		getContentPane().add(rdSingle);
  		rdMarried=new JRadioButton("Married");
  		rdMarried.setBounds(145, 84, 65, 23);
  		getContentPane().add(rdMarried);
  		rdDivorced=new JRadioButton("Divorced");
  		rdDivorced.setBounds(215, 84, 85, 23);
  		getContentPane().add(rdDivorced);
  		
  		chkBook=new JCheckBox("Book");
  		chkBook.setBounds(76, 123, 49, 23);
  		getContentPane().add(chkBook);
  		chkSports=new JCheckBox("Sports");
  		chkSports.setBounds(127, 123, 57, 23);
  		getContentPane().add(chkSports);
  		chkCinema=new JCheckBox("Cinema");
  		chkCinema.setBounds(189, 123, 61, 23);
  		getContentPane().add(chkCinema);
  		chkArts=new JCheckBox("Arts");
  		chkArts.setBounds(255, 123, 45, 23);
  		getContentPane().add(chkArts);
  		
  		
  		
  		rdSingle.setSelected(true);
  		bg= new ButtonGroup();
  		bg.add(rdSingle);
  		bg.add(rdMarried);
  		bg.add(rdDivorced);
  		
  		
  		boxName.setText(p.name.toString());
  		boxSurname.setText(p.surname.toString());
  		rdSingle.setSelected(p.meritalStatus==0);
  		rdMarried.setSelected(p.meritalStatus==1);
  		rdDivorced.setSelected(p.meritalStatus==2);
  		
  		this.setTitle("Detail: "+p.name); 

  		this.setBounds(50,50,400,190);  
  		this.setVisible(true); 
  		
 
  		
  	}
}
