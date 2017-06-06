import java.awt.*;

public class Enemy extends Entity<Integer> {
    //enums
    public static final int Jet0 = 0;
    public static final int Jet1 = 1;
    public static final int Jet2 = 2;//TODO: Jet2 eklenecek
    public static final int Ship0 = 3;

    private int dx;
    private int distance;
    private long firingTimer;
    private long firingDelay;
    private boolean firing = false;
    private Image enemySprite;

    Enemy(int x, int y, int type) {
        this.x = x;
        this.y = y;
        this.type = type;

        firingTimer = System.nanoTime();
        isLive = true;
        //floating efffect
        dx = 1;
        distance = 0;
        if (type == Jet0) {
            height = 85;
            width = 85;
            speed = 1;
            enemySprite = Tools.imageLoader("/res/Jet0.png");
            firingDelay = 1500;
            HP = 2;
        }

        if (type == Jet1) {
            height = 85;
            width = 85;
            speed = 1;
            enemySprite = Tools.imageLoader("/res/Jet1.png");
            firingDelay = 1200;
            HP = 3;
        }

        if (type == Ship0) {
            height = 200;
            width = 200;
            speed = 0;
            enemySprite = Tools.imageLoader("/res/Ship0.png");
            firingDelay = 1000;
            HP = 4;
        }
    }


    public void update() {
        if (y > GamePanel.HEIGHT) {
            y = (int) (-1 * Math.random() * 500);
            x = (int) (Math.random() * 500 + 100);
        }
        y += speed + 1;
        if (type == Jet0 || type == Jet1) {
            if (y > 0) {
                firing = true;
                //start to float
                x += dx;
                distance -= Tools.abs(dx);
                if (distance <= 0) {
                    dx *= -1;
                    distance = 35;
                }
            }
        }
        if (type == Enemy.Ship0) {
            if (y > 0) {
                firing = true;
            }
        }

        //fire
        if (firing) {
            long elapsed = (System.nanoTime() - firingTimer) / 1000000;
            if (elapsed > firingDelay) {
                firingTimer = System.nanoTime();
                switch (type) {
                    case Enemy.Jet0:
                        GamePanel.bullets.add(new Bullet(180, x, y, false));
                        break;
                    case Enemy.Jet1:
                        GamePanel.bullets.add(new Bullet(165, x, y, false));
                        GamePanel.bullets.add(new Bullet(180, x, y, false));
                        GamePanel.bullets.add(new Bullet(195, x, y, false));
                        break;
                    case Enemy.Ship0:
                        GamePanel.bullets.add(new Bullet(160, x, y, false));
                        GamePanel.bullets.add(new Bullet(170, x, y, false));
                        GamePanel.bullets.add(new Bullet(180, x, y, false));
                        GamePanel.bullets.add(new Bullet(190, x, y, false));
                        GamePanel.bullets.add(new Bullet(200, x, y, false));
                        break;
                    default:
                        System.out.println("unknown enemy type, cannot fire");
                }
            }
        }

        if (HP <= 0) {
            isLive = false;
            GamePanel.booms.add(new Boom(x, y));
            // if type 1 dies, it may drop powerUp
            if (type == Enemy.Jet0) {
                // 1/10 chance
                if ((int) (System.nanoTime() % 10) == 0) {
                    GamePanel.powerUps.add(new PowerUp(180, x, y));
                }
            }

            // if type 2 dies, it may drop powerUp
            if (type == Enemy.Jet1) {
                // 1/2 chance
                if ((int) (System.nanoTime() % 2) == 0) {
                    GamePanel.powerUps.add(new PowerUp(180, x, y));
                }
            }

            // if type 3 dies, it must drop powerUp
            if (type == Enemy.Ship0) {
                GamePanel.powerUps.add(new PowerUp(180, x, y));
            }
            //increase score
            switch (type) {
                case Enemy.Jet0:
                    GamePanel.SCORE += 150;
                    break;
                case Enemy.Jet1:
                    GamePanel.SCORE += 250;
                    break;
                case Enemy.Ship0:
                    GamePanel.SCORE += 500;
                    break;
                default:
                    System.out.println("enemy type not recognized");
            }
        }
    }

    public void draw(Graphics2D g) {
        g.drawImage(enemySprite, x - width / 2, y - height / 2, width, height, null);
    }
}