import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class SigninPanel extends JPanel {
    private JTextField _nameField;
    private JPasswordField _passwordField;
    private JLabel _signinButtonLabel;
    private JButton _signinButton;
    protected User _user = null;

    SigninPanel() {
        Draw();
        _signinButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (_nameField.getText().length() == 0) {
                    JOptionPane.showMessageDialog(null, "Name is missing", "Warning", JOptionPane.WARNING_MESSAGE);
                } else {
                    _user = User.Login(_nameField.getText(), new String(_passwordField.getPassword()));
                    if (_user == null)
                        JOptionPane.showMessageDialog(null, "Name does not exists. Try Sign-Up.", "Warning", JOptionPane.WARNING_MESSAGE);
                }
                setVisible(false);
            }
        });
    }

    private void Draw() {
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

        _signinButtonLabel = new JLabel("Sign in");
        _signinButtonLabel.setBounds(250, 674, 300, 100);
        _signinButtonLabel.setFont(new Font("timesroman", Font.BOLD, 62));
        _signinButtonLabel.setForeground(Color.WHITE);
        _signinButtonLabel.setVisible(true);
        add(_signinButtonLabel);

        _signinButton = new JButton("Sign in");
        _signinButton.setOpaque(false);
        _signinButton.setBorderPainted(false);
        _signinButton.setFocusPainted(false);
        _signinButton.setContentAreaFilled(false);
        _signinButton.setIcon(Tools.button0);
        _signinButton.setBounds(150, 674, 450, 112);
        _signinButton.setVisible(true);
        add(_signinButton);

        _signinButton.addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                _signinButton.setIcon(Tools.button1);
                _signinButtonLabel.setForeground(Color.GRAY);
            }

            @Override
            public void mouseReleased(MouseEvent e) {
                _signinButton.setIcon(Tools.button0);
                _signinButtonLabel.setForeground(Color.WHITE);
            }
        });

        JLabel back = new JLabel();
        back.setIcon(Tools.bg_clear);
        back.setBounds(0, 0, GamePanel.WIDTH, GamePanel.HEIGHT);
        back.setVisible(true);
        add(back);

        this.requestFocus();
    }
}
