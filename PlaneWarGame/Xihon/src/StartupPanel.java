import javax.swing.*;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class StartupPanel extends JPanel {
	private JButton btnSin;
	private JLabel btnSinLabel;
	private JButton btnSup;
	private JLabel btnSupLabel;
    public SigninPanel _signinPanel;
    public SignupPanel _signupPanel;
    private boolean _init;
    protected User _user;

    public StartupPanel()
    {
    	
    	Draw();
        _init = true;
        _signinPanel.addComponentListener(new ComponentAdapter() {
        	@Override
        	public void componentHidden(ComponentEvent e) {
        		SigninPanel_Hidden(e);
        		_user=_signinPanel._user;
        		if(_user==null){
        			ShowButtons();
        			return;
        		}
        	}
		});
     
        _signupPanel.addComponentListener(new ComponentAdapter() {
        	@Override
			public void componentHidden(ComponentEvent e) { 
            	SignupPanel_Hidden(e);
            	ShowButtons();
            }
        });
        _init = false;
    }

    public void SigninPanel_Hidden(ComponentEvent e) {
        if (_init || this.isVisible()) return;
        _user = _signinPanel._user;
        if (_user!=null) setVisible(false);
    }

    public void SignupPanel_Hidden(ComponentEvent e) {
        if (_init || this.isVisible()) return;
        _user = _signupPanel._user;
        if (_user!=null) setVisible(false);
    }

    public void Draw()
    {
        if (_signinPanel == null)init();
    }
    
    public void init(){
    	_signinPanel = new SigninPanel();
    	_signinPanel.setVisible(false);
    	_signinPanel.setBounds(0,0,700,860);
    	add(_signinPanel);
    	
    	_signupPanel = new SignupPanel();
    	_signupPanel.setVisible(false);
    	_signupPanel.setBounds(0,0,700,860);
    	add(_signupPanel);
    	
    	 this.setLayout(null);
       
         btnSinLabel = new JLabel("Sign in");
         btnSinLabel.setBounds(250, 350, 300, 100);
         btnSinLabel.setFont(new Font("timesroman", Font.BOLD,62));
         btnSinLabel.setForeground(Color.WHITE);
         btnSinLabel.setVisible(true);
         add(btnSinLabel);
        
         
         btnSin= new JButton("Sign in");
         btnSin.setOpaque(false);
         btnSin.setBorderPainted(false);
         btnSin.setFocusPainted(false);
         btnSin.setContentAreaFilled(false);
         btnSin.setIcon(Tools.button0);
         btnSin.setBounds(150, 350, 450, 112);
         btnSin.setVisible(true);
         add(btnSin);
         
         btnSin.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				HideAll();
 				_signinPanel.setVisible(true);
			}
		});
         btnSin.addMouseListener(new MouseAdapter() {
 			@Override
			public void mousePressed(MouseEvent e){
  				btnSin.setIcon(Tools.button1);
  				btnSinLabel.setForeground(Color.GRAY);
  			}
  			@Override
			public void mouseReleased(MouseEvent e){
  				btnSin.setIcon(Tools.button0);
  				btnSinLabel.setForeground(Color.WHITE);
  			}
		}); 
			
		
         btnSupLabel = new JLabel("Sign up");
         btnSupLabel.setBounds(250, 512, 300, 100);
         btnSupLabel.setFont(new Font("timesroman", Font.BOLD,62));
         btnSupLabel.setForeground(Color.WHITE);
         btnSupLabel.setVisible(true);
         add(btnSupLabel);
         
         btnSup= new JButton("Sign up");
         btnSup.setOpaque(false);
         btnSup.setBorderPainted(false);
         btnSup.setFocusPainted(false);
         btnSup.setContentAreaFilled(false);
         btnSup.setIcon(Tools.button0);
         btnSup.setBounds(150, 512, 450, 112);
         btnSup.setVisible(true);
         add(btnSup);
         
         btnSup.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				HideAll();
 				_signupPanel.setVisible(true);
			}
		});
         
         btnSup.addMouseListener(new MouseAdapter() {
 			@Override
			public void mousePressed(MouseEvent e){
  				btnSup.setIcon(Tools.button1);
  				btnSupLabel.setForeground(Color.GRAY);
  			}
  			@Override
			public void mouseReleased(MouseEvent e){
  				btnSup.setIcon(Tools.button0);
  				btnSupLabel.setForeground(Color.WHITE);
  			}
		}); 
			
         JLabel back = new JLabel();
         back.setIcon(Tools.bg_clear);
         back.setBounds(0, 0, GamePanel.WIDTH, GamePanel.HEIGHT);
         back.setVisible(true);
         add(back);
         
         this.requestFocus();
    }
    
    private void HideAll(){
    	_signinPanel.setVisible(false);
    	_signupPanel.setVisible(false);
    	btnSin.setVisible(false);
    	btnSup.setVisible(false);
    }
    
    private void ShowButtons(){
    	_signinPanel.setVisible(false);
    	_signupPanel.setVisible(false);
    	btnSin.setVisible(true);
    	btnSup.setVisible(true);
    }

}
