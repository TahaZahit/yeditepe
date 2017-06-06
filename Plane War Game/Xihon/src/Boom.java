import java.awt.Graphics2D;
import java.awt.image.BufferedImage;

import javax.sound.sampled.Clip;

public class Boom extends Entity<Integer> {
	private static BufferedImage b[];
	
	private int index;

	Boom(int x, int y){
		this.x=x;
		this.y=y;
		isLive=true;
		index=0;
		Clip clip = Tools.audioLoader("/res/boom.wav");
		clip.start();

	}
	public static void init(){
		b= new BufferedImage[5];
		b[0]=Tools.boom0.getSubimage(0, 0, 118, 118);
		b[1]=Tools.boom0.getSubimage(118, 0, 118, 118);
		b[2]=Tools.boom0.getSubimage(236, 0, 118, 118);
		b[3]=Tools.boom0.getSubimage(354, 0, 118, 118);
		b[4]=Tools.boom0.getSubimage(472, 0, 118, 118);
	}
	public void update(){
		index++;
		if(index>14) isLive=false;
	}
	public void draw(Graphics2D g){
		g.drawImage(b[index%b.length],x-59,y-59,null);
	}
}
