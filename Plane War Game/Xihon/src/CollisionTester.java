public class CollisionTester{
	CollisionTester(){
	}
	public void update(){
		for (int i = 0; i < GamePanel.bullets.size(); i ++){
			if (!GamePanel.bullets.get(i).isFriendly()){
				int distance = Tools.getDistance(GamePanel.player.getX(), GamePanel.player.getY(),GamePanel.bullets.get(i).getX(),GamePanel.bullets.get(i).getY());
				if (distance <= 30){
					GamePanel.player.hurt();
					GamePanel.bullets.remove(i);
				}
			}
		}
		for (int i = 0; i < GamePanel.powerUps.size(); i ++){
			int distance = Tools.getDistance(GamePanel.player.getX(),GamePanel.player.getY(),GamePanel.powerUps.get(i).getX(),GamePanel.powerUps.get(i).getY());
			if (distance <= 30){
				GamePanel.player.powerUp();
				GamePanel.powerUps.remove(i);
			}
		}
		for (int i = 0; i < GamePanel.enemies.size(); i ++){
			int distance = Tools.getDistance(GamePanel.player.getX(),GamePanel.player.getY(),GamePanel.enemies.get(i).getX(),GamePanel.enemies.get(i).getY());
			if (distance <= 50 && GamePanel.enemies.get(i).getType()!=3){
				GamePanel.player.hurt();
			}
		}
		for (int i = 0; i < GamePanel.bullets.size(); i ++){
			for (int j = 0; j < GamePanel.enemies.size(); j ++){
				if (j != GamePanel.enemies.size() && i != GamePanel.bullets.size()){
					int distance = Tools.getDistance(GamePanel.enemies.get(j).getX(),GamePanel.enemies.get(j).getY(), GamePanel.bullets.get(i).getX(),GamePanel.bullets.get(i).getY());
					if (GamePanel.bullets.get(i).isFriendly() && distance <= 30){
						GamePanel.bullets.remove(i);
						GamePanel.enemies.get(j).hurt();
					}
				}
			}
		}
	}
}