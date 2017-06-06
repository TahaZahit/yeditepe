import java.awt.*;
import java.util.Collections;
import java.util.LinkedList;

public class HighScore {

    private boolean finished;

    public HighScore() {
        finished = false;
    }

    public void update() {
        if (finished) {
            GamePanel.gsm.enterState(GameStateManager.MENU);
            finished = false;
        }
    }

    public void draw(Graphics2D g) {
        g.setColor(Color.BLACK);
        g.fillRect(0, 0, GamePanel.WIDTH, GamePanel.HEIGHT);
        g.setColor(Color.WHITE);

        Font titleFont = new Font("TimesRoman", Font.BOLD, 60);
        Font highFont = new Font("TimesRoman", Font.BOLD, 20);
        g.setFont(titleFont);
        g.drawString("High Scores", 50, 100);

        g.setFont(highFont);

        LinkedList<User> list = User.TopScores(10);

        Collections.sort(list);


        for (int i = 0; i < list.size(); i++)
            g.drawString(list.get(i).get_highscore() + " - " + list.get(i).get_name(), 60, 200 + i * 40);

        g.drawString("press ENTER or SPACE to go back", 100, GamePanel.HEIGHT - 40);
    }

    public void finish() {
        finished = true;
    }
}