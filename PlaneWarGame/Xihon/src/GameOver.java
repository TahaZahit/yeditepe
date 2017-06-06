import java.awt.*;

public class GameOver {
    private boolean finished;

    public GameOver() {
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
        g.setFont(new Font("timesroman", Font.BOLD, 72));
        g.drawString("GAME OVER", 105, 150);
        g.setFont(new Font("timesroman", Font.BOLD, 40));
        g.drawString("SCORE: " + GamePanel.SCORE, 240, 400);


        g.setFont(new Font("TimesRoman", Font.BOLD, 20));
        //g.drawString("press ENTER or SPACE to go back", 100, GamePanel.HEIGHT - 40);

    }

    public void finish() {
        finished = true;
    }
}
