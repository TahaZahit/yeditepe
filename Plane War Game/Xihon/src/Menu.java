import java.awt.*;
import java.awt.image.BufferedImage;

public class Menu {

    private int menuOption;
    private boolean chosen;

    //options constant
    private static final int START = 1;
    private static final int HIGHSCORE = 2;
    private static final int EXIT = 3;

    private static BufferedImage bg = Tools.imageLoader("/res/bgs/bg-clear-menu.png");

    //constructor
    public Menu() {
        menuOption = START;
        chosen = false;
    }

    //main functions
    public void update() {
        if (chosen) {
            //process player's choice
            switch (menuOption) {
                case START:
                    GamePanel.gsm.enterState(GameStateManager.GAME);
                    break;
                case HIGHSCORE:
                    GamePanel.gsm.enterState(GameStateManager.HIGHSCORES);
                    break;
                case EXIT:
                    System.out.println("exit game");
                    System.exit(0);
                    break;
                default:
                    System.out.println("menu update function error");
            }

            //reset
            chosen = false;
        }
    }

    public void draw(Graphics2D g) {
        g.drawImage(bg, 0, 0, null);

        g.setColor(Color.GRAY);

        //set Fonts
        Font optionFont = new Font("TimesRoman", Font.BOLD, 75);
        //display options
        g.setFont(optionFont);

        if (menuOption == START)
            g.setColor(Color.WHITE);
        g.drawString("Start", 250, 410);
        g.setColor(Color.GRAY);

        if (menuOption == HIGHSCORE)
            g.setColor(Color.WHITE);
        g.drawString("High Scores", 120, 530);
        g.setColor(Color.GRAY);

        if (menuOption == EXIT)
            g.setColor(Color.WHITE);
        g.drawString("Exit", 270, 650);
        g.setColor(Color.GRAY);
    }

    public void nextChoice() {
        menuOption++;
        //exception
        if (menuOption > EXIT)
            menuOption = START;
    }

    public void previousChoice() {
        menuOption--;
        //exception
        if (menuOption < START)
            menuOption = EXIT;
    }

    public void setChosen() {
        chosen = true;
    }
}