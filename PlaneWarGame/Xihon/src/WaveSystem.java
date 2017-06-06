
import java.awt.*;
import java.util.Timer;
import java.util.TimerTask;


public class WaveSystem {
    //field
    private static int wave;
    private boolean spawned;

    public static Timer randomEnemy = new Timer();
    public static TimerTask task = new TimerTask() {

        @Override
        public void run() {
            if (!GamePanel.getPaused()) {

                GamePanel.enemies.add(new Enemy((int) Math.random() * 600 + 60, 1000, Enemy.Jet1));
            }

        }
    };

    public WaveSystem() {
        wave = 1;
        spawned = false;
    }

    public void update() {
        if (!spawned) {
            switch (wave) {
                case 1:
                    randomEnemy.schedule(task, 100, 6000);
                    GamePanel.enemies.add(new Enemy(150, -100, Enemy.Jet0));
                    GamePanel.enemies.add(new Enemy(500, -300, Enemy.Ship0));
                    GamePanel.enemies.add(new Enemy(600, -500, Enemy.Ship0));
                    spawned = true;
                    break;

                case 2:
                    GamePanel.enemies.add(new Enemy(100, -100, Enemy.Jet0));
                    GamePanel.enemies.add(new Enemy(350, -200, Enemy.Jet1));
                    GamePanel.enemies.add(new Enemy(600, -100, Enemy.Jet0));
                    spawned = true;
                    break;

                case 3:
                    GamePanel.enemies.add(new Enemy(100, -100, Enemy.Jet0));
                    GamePanel.enemies.add(new Enemy(250, -100, Enemy.Jet1));
                    GamePanel.enemies.add(new Enemy(550, -100, Enemy.Jet0));
                    spawned = true;
                    break;

                case 4:
                    GamePanel.enemies.add(new Enemy(100, -100, Enemy.Jet0));
                    GamePanel.enemies.add(new Enemy(450, -100, Enemy.Jet1));
                    GamePanel.enemies.add(new Enemy(600, -100, Enemy.Jet0));
                    spawned = true;
                    break;

                case 5:
                    GamePanel.enemies.add(new Enemy(140, -300, Enemy.Jet0));
                    GamePanel.enemies.add(new Enemy(450, -400, Enemy.Jet0));
                    GamePanel.enemies.add(new Enemy(600, -500, Enemy.Jet0));
                    spawned = true;
                    break;

                case 6:
                    GamePanel.enemies.add(new Enemy(150, -500, Enemy.Jet0));
                    GamePanel.enemies.add(new Enemy(500, -500, Enemy.Jet1));
                    GamePanel.enemies.add(new Enemy(600, -500, Enemy.Jet1));
                    GamePanel.enemies.add(new Enemy(150, -300, Enemy.Jet0));
                    GamePanel.enemies.add(new Enemy(500, -300, Enemy.Jet0));
                    GamePanel.enemies.add(new Enemy(600, -300, Enemy.Jet1));
                    GamePanel.enemies.add(new Enemy(140, -100, Enemy.Jet1));
                    GamePanel.enemies.add(new Enemy(450, -200, Enemy.Jet1));
                    GamePanel.enemies.add(new Enemy(600, -100, Enemy.Jet1));
                    spawned = true;
                    break;

                default:
                    System.out.println("unknown wave");
            }
        }

        if (GamePanel.enemies.size() == 0) {
            if (wave < 6) {
                spawned = false;
                wave++;
            }
        }
    }

    public void draw(Graphics2D g) {
        g.setColor(Color.WHITE);
        g.setFont(new Font("timesroman", Font.BOLD, 20));
        g.drawString("SCORE: " + GamePanel.SCORE, 50, 50);
        g.drawString("WAVE: " + wave, 50, 100);
    }

    public int getWave() {
        return wave;
    }
}