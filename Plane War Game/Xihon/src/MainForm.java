import javax.swing.*;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;

public class MainForm extends JFrame {
    private StartupPanel _startupPanel;
    private GamePanel _gamePanel;
    public static User _user;

    MainForm() {
        init();
        _gamePanel = new GamePanel();
        _gamePanel.setVisible(false);
        add(_gamePanel);
        setBounds(0, 0, 700, 860);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
        setLocationRelativeTo(null);
        setVisible(true);
    }

    private void init() {

        _startupPanel = new StartupPanel();
        _startupPanel.setVisible(true);
        _startupPanel.setBounds(0, 0, 700, 860);
        add(_startupPanel);

        _startupPanel._signinPanel.addComponentListener(new ComponentAdapter() {
            @Override
            public void componentHidden(ComponentEvent e) {
                if (_startupPanel._signinPanel._user != null) {
                    _startupPanel.setVisible(false);
                    _user = _startupPanel._user;
                    StartGame();
                }
            }
        });
    }

    private void StartGame() {
        _gamePanel.set_currentUser(_user);
        _gamePanel.setBounds(0, 0, GamePanel.WIDTH, GamePanel.HEIGHT);
        _gamePanel.setVisible(true);
        _gamePanel.requestFocus();
    }
}
