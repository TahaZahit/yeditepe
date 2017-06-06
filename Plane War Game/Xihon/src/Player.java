import java.awt.*;
import java.awt.image.BufferedImage;

public class Player extends Entity<Integer> {

    private boolean movingUp;
    private boolean movingDown;
    private boolean movingLeft;
    private boolean movingRight;

    private BufferedImage playerSprite[] = new BufferedImage[2];

    private long firingTimer;
    private long firingDelay;
    private boolean firing;
    private boolean godMode;

    private final int HPMax;
    private final int maxPower;
    public int power;

    Player(int x, int y) {
        this.x = x;
        this.y = y;

        speed = 3;
        height = 90;
        width = 90;

        movingUp = false;
        movingDown = false;
        movingLeft = false;
        movingRight = false;

        playerSprite[0] = Tools.imageLoader("/res/player1.png");
        playerSprite[1] = Tools.imageLoader("/res/player1_god.png");

        firingTimer = System.nanoTime();
        firingDelay = 300;
        firing = false;

        isLive = true;
        HPMax = 12;
        HP = HPMax;

        power = 1;
        maxPower = 5;

        godMode = false;
    }

    public void update() {
        if (HP <= 0) {
            isLive = false;
            GamePanel.gsm.enterState(GameStateManager.GAMEOVER);
        }

        if (movingUp && y - height / 2 > 0) y -= speed;
        if (movingLeft && x - width / 2 > 0) x -= speed;
        if (movingDown && y + height / 2 < GamePanel.HEIGHT) y += speed;
        if (movingRight && x + width / 2 < GamePanel.WIDTH) x += speed;


        if (firing) {
            long elapsed = (System.nanoTime() - firingTimer) / 1000000;
            if (elapsed > firingDelay) {
                firingTimer = System.nanoTime();
                switch (power) {
                    case 1:
                        GamePanel.bullets.add(new Bullet(0, x, y, true));
                        break;
                    case 2:
                        GamePanel.bullets.add(new Bullet(5, x, y, true));
                        GamePanel.bullets.add(new Bullet(355, x, y, true));
                        break;
                    case 3:
                        GamePanel.bullets.add(new Bullet(10, x, y, true));
                        GamePanel.bullets.add(new Bullet(0, x, y, true));
                        GamePanel.bullets.add(new Bullet(350, x, y, true));
                        break;
                    case 4:
                        GamePanel.bullets.add(new Bullet(10, x, y, true));
                        GamePanel.bullets.add(new Bullet(5, x, y, true));
                        GamePanel.bullets.add(new Bullet(355, x, y, true));
                        GamePanel.bullets.add(new Bullet(350, x, y, true));
                        break;
                    case 5:
                        GamePanel.bullets.add(new Bullet(15, x, y, true));
                        GamePanel.bullets.add(new Bullet(8, x, y, true));
                        GamePanel.bullets.add(new Bullet(0, x, y, true));
                        GamePanel.bullets.add(new Bullet(352, x, y, true));
                        GamePanel.bullets.add(new Bullet(345, x, y, true));
                        break;
                    default:
                        System.out.println("Player's Power system error");
                }
            }
        }
    }

    public void draw(Graphics2D g) {
        if (!godMode)
            g.drawImage(playerSprite[0], x - width / 2, y - height / 2, width, height, null);
        else
            g.drawImage(playerSprite[1], x - width / 2, y - height / 2, width, height, null);

        //draw hp box
        int hpBar = 250;
        g.setColor(Color.GRAY);
        g.fillRect(40, 800, hpBar, 20);

        //draw hp
        g.setColor(Color.GREEN);
        g.fillRect(40, 800, HP * hpBar / HPMax, 20);

        //draw name
        g.setColor(Color.WHITE);
        g.setFont(new Font("timesroman", Font.BOLD, 20));
        g.drawString(MainForm._user.get_name(), 40, 790);

    }

    public void setFiring(boolean bool) {
        firing = bool;
    }

    public void powerUp() {
        if (power < maxPower)
            power++;
    }

    public void setGodMode() {
        godMode = !godMode;
        if (godMode) {
            height = 100;
            width = 150;
        } else {
            height = 90;
            width = 90;
        }
    }

    @Override
    public void hurt() {
        if (!godMode)
            HP--;
    }

    public void setFiringDelay(int value) {
        firingDelay = value;
    }

    public void setMovingUp(boolean bool) {
        movingUp = bool;
    }

    public void setMovingDown(boolean bool) {
        movingDown = bool;
    }

    public void setMovingLeft(boolean bool) {
        movingLeft = bool;
    }

    public void setMovingRight(boolean bool) {
        movingRight = bool;
    }

}