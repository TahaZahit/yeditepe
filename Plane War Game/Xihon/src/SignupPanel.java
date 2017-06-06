import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class SignupPanel extends JPanel {
    private JTextField _nameField;
    private JPasswordField _passwordField;
    private JButton _signupButton;
    public User _user = null;
	private JLabel _signupButtonLabel;

    public SignupPanel()
    {
    	 Draw();
        _signupButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (_nameField.getText().length()==0) {
                    JOptionPane.showMessageDialog(null, "Name is missing", "Warning", JOptionPane.WARNING_MESSAGE);
                }
                else{
                    _user = User.RegisterUser(_nameField.getText(), new String(_passwordField.getPassword()));
                    if (_user == null)
                        JOptionPane.showMessageDialog(null, "Name exists. Try Sign-In", "Warning", JOptionPane.WARNING_MESSAGE);
                }
                setVisible(false);
            }
        });
       
    }

    private void Draw()
    {
    	this.setLayout(null);

		_nameField = new JTextField();
		_nameField.setOpaque(false);
		_nameField.setFont(new Font("timesroman", Font.PLAIN, 62));
		_nameField.setForeground(Color.WHITE);
		_nameField.setBounds(165, 350, 410, 95);
		_nameField.setCaretColor(Color.WHITE);
		_nameField.setVisible(true);
		_nameField.setBorder(null);
		add(_nameField);

		JLabel _nameLabel = new JLabel();
		_nameLabel.setIcon(Tools.input0);
		_nameLabel.setBounds(150, 342, 450, 112);
		_nameLabel.setVisible(true);
		add(_nameLabel);

		_passwordField = new JPasswordField();
		_passwordField.setOpaque(false);
		_passwordField.setFont(new Font("timesroman", Font.PLAIN, 62));
		_passwordField.setForeground(Color.WHITE);
		_passwordField.setBounds(165, 512, 410, 95);
		_passwordField.setCaretColor(Color.WHITE);
		_passwordField.setVisible(true);
		_passwordField.setBorder(null);
		add(_passwordField);

		JLabel _passwordLabel = new JLabel();
		_passwordLabel.setIcon(Tools.input0);
		_passwordLabel.setBounds(150, 504, 450, 112);
		_passwordLabel.setVisible(true);
		add(_passwordLabel);

		_signupButtonLabel = new JLabel("Sign up");
		_signupButtonLabel.setBounds(250, 674, 300, 100);
		_signupButtonLabel.setFont(new Font("timesroman", Font.BOLD,62));
		_signupButtonLabel.setForeground(Color.WHITE);
		add(_signupButtonLabel);
		_signupButtonLabel.setVisible(true);

		_signupButton= new JButton("Sign in");
		_signupButton.setOpaque(false);
		_signupButton.setBorderPainted(false);
		_signupButton.setFocusPainted(false);
		_signupButton.setContentAreaFilled(false);
		_signupButton.setIcon(Tools.button0);
		_signupButton.setBounds(150, 674, 450, 112);
		add(_signupButton);
		_signupButton.setVisible(true);
	
		_signupButton.addMouseListener(new MouseAdapter() {
			
			@Override
			public void mousePressed(MouseEvent e){
				_signupButton.setIcon(Tools.button1);
				_signupButtonLabel.setForeground(Color.GRAY);
			}
			@Override
			public void mouseReleased(MouseEvent e){
				_signupButton.setIcon(Tools.button0);
				_signupButtonLabel.setForeground(Color.WHITE);
			}
		}); 

		this.add(_signupButton);
		this.setBounds(0, 0, 700, 860);

		JLabel back = new JLabel();
		back.setIcon(Tools.bg_clear);
		back.setBounds(0, 0, GamePanel.WIDTH, GamePanel.HEIGHT);
		add(back);
		back.setVisible(true);

		this.requestFocus();

    }

}
