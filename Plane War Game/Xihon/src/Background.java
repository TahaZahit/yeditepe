
import java.awt.*;
import java.awt.image.BufferedImage;

import javax.sound.sampled.Clip;

public class Background{
	private int y1;
	private int y2;
	private int dy;
	private Clip bg = Tools.bgClip;
	
	public Background(){
		y1 = 16640-GamePanel.HEIGHT;
		y2 = 2*16640-GamePanel.HEIGHT;
		dy = -1;
		bg.start();
	}
	public void update(){
		y1 += dy;
		y2 += dy;

		if (y1 <= 0)
			y1 = 16640-GamePanel.HEIGHT;
		if (y2 <= - GamePanel.HEIGHT)
			y2 = 2*16640 - GamePanel.HEIGHT;
		bg.loop(bg.available());
	}
	public void draw(Graphics2D g){
		g.drawImage(Tools.background1, 0, -y1, null);
		g.drawImage(Tools.background2, 0, -y2, null);
	}
}