#include "header.h"

void setCharacter(){
	player[0].checkThread = 1;
	player[0].x = -0.8;
	player[0].y1 = 0.1;
	player[0].y2 = 0.0;
	player[0].health = -1;
	player[0].bulletX = player[0].x;
	player[0].attack = 0;
	player[0].efekKenaDamage = 0;
	player[0].bulletY = player[0].y1-0.1;
	
	player[1].checkThread = 2;
	player[1].x = -0.7;
	player[1].y1 = 0.1;
	player[1].y2 = 0.0;
	player[1].health = -1;
	player[1].bulletX = player[1].x;
	player[1].attack = 0;
	player[1].efekKenaDamage = 0;
	player[1].bulletY = player[1].y1-0.1;
	
	enemy[0].checkThread = 1;
	enemy[0].x = 0.8;
	enemy[0].y1 = 0.1;
	enemy[0].y2 = 0.0;
	enemy[0].health = 1;
	enemy[0].bulletX = enemy[0].x;
	enemy[0].attack = 0;
	enemy[0].bulletY = enemy[0].y1-0.1;
	
	enemy[1].checkThread = 2;
	enemy[1].x = 0.7;
	enemy[1].y1 = 0.2;
	enemy[1].y2 = 0.1;
	enemy[1].health = 1;
	enemy[1].bulletX = enemy[1].x;
	enemy[1].attack = 0;
	enemy[1].bulletY = enemy[1].y1-0.1;
	
	enemy[2].checkThread = 3;
	enemy[2].x = 0.9;
	enemy[2].y1 = 0.3;
	enemy[2].y2 = 0.2;
	enemy[2].health = 1;
	enemy[2].bulletX = enemy[2].x;
	enemy[2].attack = 0;
	enemy[2].bulletY = enemy[2].y1-0.1;

	enemy[3].checkThread = 4;	
	enemy[3].x = 0.6;
	enemy[3].y1 = 0.4;
	enemy[3].y2 = 0.3;
	enemy[3].health = 1;
	enemy[3].bulletX = enemy[3].x;
	enemy[3].attack = 0;
	enemy[3].bulletY = enemy[3].y1-0.1;

	enemyKing.checkThread = 5;	
	enemyKing.x = 0.9;
	enemyKing.y1 = 0.5;
	enemyKing.y2 = 0.3;
	enemyKing.health = 10*100;
	enemyKing.bulletX = enemyKing.x;
	enemyKing.attack = 0;
	enemyKing.bulletY = enemyKing.y1-0.1;
}
// menetapkan setiap karakter kordinat gambar , nyawa ,kordinat peluru dan lain"


void drawCharacterEnemy(void *enemy_ppt){
	Character *enemy = (Character*)enemy_ppt;
		glLineWidth(10);
	if(enemy->health == 1){
		glColor3f(1.0,0,0);
		glBegin(GL_LINES);
			glVertex3f(enemy->x,enemy->y1,0);
			glVertex3f(enemy->x,enemy->y2,0);
		glEnd();
	}
}
// mengambar karakter sesuai kordinat yang sudah di tentukan

void drawCharacterEnemyBos(){
	if(enemyKing.health != 0){
		if (efekMemberiDamage == 1)
		{
			glColor3f(1.0,0,0);
		}else{
			glColor3f(0.1,1,0.8);
		}
		glLineWidth(10);
		glBegin(GL_LINES);
			glVertex3f(enemyKing.x,enemyKing.y1,0);
			glVertex3f(enemyKing.x,enemyKing.y2,0);
		glEnd();
	}
	efekMemberiDamage = 0;
}

void drawCharacterPlayer(void *player_ppt, int i){
	Character *player = (Character*)player_ppt;
	if (i == 1)
	{
		glColor3f(1.0,1.0,0);	
	}else{
		glColor3f(1.0,0,1.0);	
	}
	if (player->efekKenaDamage == 1)
	{
		glColor3f(1,0,0);
	}
	if(player->health > 0){
		glLineWidth(10);
		// jika nyawa player masih 1 maka karakter di gambar
		glBegin(GL_LINES);
			glVertex3f(player->x,player->y1,0);
			glVertex3f(player->x,player->y2,0);
		glEnd();
	}else{
		player->health = 0;
	}
	player->efekKenaDamage = 0;
}
// mengambar karakter sesuai kordinat yang sudah di tentukan

void drawBulletEnemy(void *enemy_ppt){
	Character *enemy = (Character*)enemy_ppt;
	
	if(enemy->health == 1 && enemy->attack == 1){
	int randomInteger = rand();
	 glPointSize(8);
	 if (randomInteger % 3 == 0){
		glColor3f(1.0,0,1.0);
	 }else if(randomInteger % 3 == 1){
		glColor3f(1.0,0,0);
	 }else if(randomInteger % 3 == 2){
		glColor3f(0,1.0,0);
	 }
	 glLineWidth(4);
	glBegin(GL_LINE_LOOP);
		glVertex3f(enemy->bulletX,enemy->bulletY+0.05, 0.0);
		glVertex3f(enemy->bulletX+0.1,enemy->bulletY+0.05, 0.0);
	glEnd();
	}
}

void drawBulletEnemyBos(){	
	if(enemyKing.health != 0 && enemyKing.attack == 1){
	int randomInteger = rand();
	 glPointSize(8);
	 if (randomInteger % 3 == 0){
		glColor3f(1.0,0,1.0);
	 }else if(randomInteger % 3 == 1){
		glColor3f(1.0,0,0);
	 }else if(randomInteger % 3 == 2){
		glColor3f(0,1.0,0);
	 }
	 glLineWidth(10);
	glBegin(GL_LINE_LOOP);
		glVertex3f(enemyKing.bulletX,enemyKing.bulletY+0.05, 0.0);
		glVertex3f(enemyKing.bulletX+0.1,enemyKing.bulletY+0.05, 0.0);
	glEnd();
	}
}
void drawBulletPlayer(void *player_ppt){
	Character *player = (Character*)player_ppt;
	if(player->health > 0 && player->attack == 1){
		glLineWidth(4);
	glBegin(GL_LINE_LOOP);
		glVertex3f(player->bulletX,player->bulletY+0.05, 0.0);
		glVertex3f(player->bulletX+0.1,player->bulletY+0.05, 0.0);
	glEnd();
	}
}
void keyboardCallBack(){
		glutKeyboardFunc(moveFunP1);
		if(playUser == 2){
		glutSpecialFunc(moveFunP2);
		}
	// glutKeyboardFunc menyetel panggilan balik keyboard untuk jendela saat ini. Saat pengguna mengetik di jendela, setiap penekanan tombol yang menghasilkan karakter ASCII akan menghasilkan panggilan balik keyboard.	
}

// mengambar setiap peluru
void loop(){
		keyboardCallBack();
		prosesAttackPlayerWithThread();
   		glutDisplayFunc(displayRender);
    	// glutDisplayFunc menyetel callback tampilan untuk jendela saat ini.
		glutPostRedisplay();
		// glutPostRedisplay menandai winodw saat ini sebagai yang perlu ditampilkan ulang.
	if (enemy[0].health != 0 || enemy[1].health != 0 || enemy[2].health != 0 || enemy[3].health != 0){
		for (int i = 0; i < 4; ++i)
		{
		 pthread_create(&thread[i],NULL,enemy_automatic_enemy,&enemy[i]); 
		}
		// membuat thread dari prosedur musuh 1 sampai 4

		for (int i = 0; i < 4; ++i){
			pthread_join(thread[i],NULL);
			// enemy_automatic_enemy(&enemy[i]);
			printf("\n");
		}
	}	
	// menjalankan thread yang sudah di buat
  	printf("\n\n\n\n");
  	for (int i = 0; i < playUser; ++i)
  	{
		InteractionEnemy(&player[i]);
  	}
  	for (int i = 0; i < playUser; ++i)
  	{
		InteractionPlayer(&player[i]);
	}
	// pemanggil prosedur interaksi
	if(enemy[0].health == 0 && enemy[1].health == 0 && enemy[2].health == 0 && enemy[3].health == 0)
	{
		pthread_create(&threadKing,NULL,enemy_automatic_enemy,&enemyKing); 
		prosesVsBos();
	}
	winOrLose();
	// menentukan menang atau tidak
}

void winOrLose(){
	if(enemy[0].health == 0 && enemy[1].health == 0 && enemy[2].health == 0 && enemy[3].health == 0 && enemyKing.health == 0){
		// Jika musuh 1 sampai 4 nyawa nya habis atau nilai 0 maka menang
			start = 0;
			// start di ulang ke 0 agar balik ke menu
			win = 1;
			// win di beri nilai 1 agar menujukan bahwa menang
			glutTimerFunc(0, createMenuLast, 0);	
			// memanggil menu terakhir
	}else if(player[0].health <= 0 && playUser == 1){
			start = 0;
			win = 0;
			glutTimerFunc(0, createMenuLast, 0);	
	}else if(player[0].health <= 0 &&  player[1].health <= 0 && playUser == 2){
			start = 0;
			win = 0;
			glutTimerFunc(0, createMenuLast, 0);	
	}else{
			glutTimerFunc(0, loop, 0);	
	}
}

void moveFunP1 (char key)
{	
	switch (key){
		case 'w':
		// jika menekan w maka kordinat y1 dan y2 di tambah 0.1 
			if(player[0].y1 <= 0.8){
				// bertambah jika y1 lebih kecil dari 0.8;
				player[0].y1 += 0.1;
				player[0].y2 += 0.1;
				if(player[0].attack == 0){
					// jika tidak menyerang maka nilai kordinat peluru y di samakan dengan kordinat y1 pada player[0]
					player[0].bulletY = player[0].y1-0.1;
				}
			}
			break;

		case 's': 
			if(player[0].y2 >= -0.7){
				player[0].y1 -= 0.1;
				player[0].y2 -= 0.1;
				if(player[0].attack == 0){
					player[0].bulletY = player[0].y1-0.1;
				}
			}
			break;
 
		case 32:
			player[0].attack = 1;
			// melakukan tugas pemrosesan latar belakang atau animasi berkelanjutan saat peristiwa sistem jendela tidak diterima.
			break;

		case 'k':
			player[1].attack = 1;
			// melakukan tugas pemrosesan latar belakang atau animasi berkelanjutan saat peristiwa sistem jendela tidak diterima.
			break;
		default:
         break;
	}
}

void prosesAttackPlayerWithThread(){
	for (int i = 0; i < 2; ++i)
	{
		pthread_create(&thread_player[i],NULL,prosesAttackPlayer,&player[i]);
	}

	for (int i = 0; i < 2; ++i)
	{
		pthread_join(thread_player[i],NULL);
		printf("\n");
	}
}
void prosesAttack(){
	for (int i = 0; i < 4; ++i){
		if(enemy[i].attack == 1){
			bulletAttackEnemy(&enemy[i]);
		}
	}

	if (enemyKing.attack == 1){
			bulletAttackEnemy(&enemyKing);
	}
}

void* prosesAttackPlayer(void* player_ppt){
Character *player = (Character*) player_ppt;
	if (player->attack == 1){
	bulletAttackP(player);
	}
	printf("Thread Player = %d \t",player->checkThread);
}

void moveFunP2 (char key)
{	
	switch (key){
		case GLUT_KEY_UP:
		// jika menekan w maka kordinat y1 dan y2 di tambah 0.1 
			if(player[1].y1 <= 0.8){
				// bertambah jika y1 lebih kecil dari 0.8;
				player[1].y1 += 0.1;
				player[1].y2 += 0.1;
				if(player[1].attack == 0){
					// jika tidak menyerang maka nilai kordinat peluru y di samakan dengan kordinat y1 pada player[1]
					player[1].bulletY = player[1].y1-0.1;
				}
			}
			break;

		case GLUT_KEY_DOWN: 
			if(player[1].y2 >= -0.7){
				player[1].y1 -= 0.1;
				player[1].y2 -= 0.1;
				if(player[1].attack == 0){
					player[1].bulletY = player[1].y1-0.1;
				}
			}
			break;

		default:
         break;
	}
}

void displayRender(){
	glLineWidth(8);
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
		glVertex3f(-1.0,-0.8,0);
		glVertex3f(1.0,-0.8,0);
	glEnd();
	
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
		glVertex3f(-1.0,0.8,0);
		glVertex3f(1.0,0.8,0);
	glEnd();

	for (int i = 0; i < playUser; ++i)
	{
		drawCharacterPlayer(&player[i],i);
		drawBulletPlayer(&player[i]);
	}

	for (int i = 0; i < 4; ++i)
	{
		drawCharacterEnemy(&enemy[i]);
		drawBulletEnemy(&enemy[i]);
	}
	char string[100];
	if(enemy[0].health == 0 && enemy[1].health == 0 && enemy[2].health == 0 && enemy[3].health == 0)
	{
		sprintf(string,"Health King = %d",enemyKing.health);
		RenderString(0.8f, 0.9f, GLUT_BITMAP_TIMES_ROMAN_10, string);		
		drawCharacterEnemyBos(&enemyKing);
		drawBulletEnemyBos(&enemyKing);		
	}
		glColor3f(1,1,1);
		sprintf(string,"Health Player 1 = %d",player[0].health);
		RenderString(-0.9f, 0.9f, GLUT_BITMAP_TIMES_ROMAN_10, string);
	if (playUser == 2)
	{
		sprintf(string,"Health Player 2 = %d",player[1].health);
		RenderString(-0.9f, 0.85f, GLUT_BITMAP_TIMES_ROMAN_10, string);
	}
		glFlush();
	//  mengosongkan semua perintah di buffer ini dan memaksa semua perintah yang tertunda akan segera dijalankan tanpa buffer menunggu penuh.

}



void* enemy_automatic_enemy(void* enemy_ppt){
	Character *enemy = (Character*)enemy_ppt;
	// merandom interger dengan rand();	
		if ((enemy->y1 <= player[0].y1 && enemy->y1 >= player[0].y1-0.05 && player[0].health > 0) ||  (enemy->y1 <= player[1].y1 && enemy->y1 >= player[1].y1-0.05 && player[1].health > 0)){
				// jika nilainya ganjil maka musuh menyerang
					enemy->attack = 1;
					glutIdleFunc(prosesAttack);		
		}else{
		// jika nilai random nya genap makan posisi musuh berjalan
		int randomInteger = rand();
		if(enemy->y1 <= 0.8 && randomInteger%2 == 0){
			// jika nilai genep bergerak ke atas / di tambahkan kordinat nya
				enemy->y1 += 0.006;
				enemy->y2 += 0.006;
				if(enemy->attack == 0){
					enemy->bulletY = enemy->y1-0.1;
				}
			}
		if(enemy->y2 >= -0.7 && randomInteger%2 != 0){
			// jika nilai ganjil bergerak ke bawah / di kurangi kordinat nya
				enemy->y1 -= 0.006;
				enemy->y2 -= 0.006;
				if(enemy->attack == 0){
					enemy->bulletY = enemy->y1-0.1;
				}
		}
		}
		printf("Thread Enemy = %d \t",enemy->checkThread);
}

void* bulletAttackP(void* player_ppt){
	Character *player = (Character*)player_ppt;
	if(player->bulletX <= 1.0 && player->attack == 1){
		player->bulletX += 0.009;
		if(player->bulletX == -0.8){
			player->bulletY = player->y1-0.1;
		}
	}else{
	player->bulletX = -0.8;
	player->bulletY = player->y1-0.1;
	player->attack = 0;		
	}
}


void* bulletAttackEnemy(void* enemy_ppt){
	Character *enemy = (Character*)enemy_ppt;
	if(enemy->bulletX >= -1.0 && enemy->attack == 1){
		enemy->bulletX -= 0.008 ;
		if(enemy->bulletX == 0.8){
			enemy->bulletY = enemy->y1-0.1;
		}
	}else{
		enemy->bulletX = 0.8;
		enemy->bulletY = enemy->y1-0.1;
		enemy->attack = 0;
	}
}


void InteractionEnemy(void *player_ppt){
	Character *player = (Character*)player_ppt;
	for(int i=0 ; i<4;i++){
		if (player->bulletX >= enemy[i].x && player->health > 0 && (player->bulletY  <= enemy[i].y1) && (player->bulletY >= enemy[i].y2)){
			enemy[i].health = 0;
		}
	}
}

void prosesVsBos(){
	pthread_join(threadKing,NULL);
	printf("\n");
	for (int i = 0; i < 2; ++i){
		if (enemyKing.bulletX <= player[i].x && (enemyKing.bulletY <= player[i].y1-0.1) && (enemyKing.bulletY >= player[i].y2-0.1) && (enemyKing.health != 0)){
			player[i].health--;
			player[i].efekKenaDamage = 1;		
		}

		if (player[i].bulletX >= enemyKing.x && player[i].health > 0 && (player[i].bulletY  <= enemyKing.y1) && (player[i].bulletY >= enemyKing.y2) && (enemyKing.health != 0)){
			enemyKing.health--;
			efekMemberiDamage = 1;
		}
	}
}

void InteractionPlayer(void *player_ppt){
	Character *player = (Character*)player_ppt;
	for(int i=0;i<4;i++){
		if (enemy[i].bulletX <= player->x && (enemy[i].bulletY <= player->y1-0.1) && (enemy[i].bulletY >= player->y2-0.1) && (enemy[i].health == 1)){
			player->health--;
			player->efekKenaDamage = 1;		
		}		
	}	
}


void RenderString(float x, float y, void *font, const char* string)
{  
  glRasterPos2f(x, y);
  // untuk menentukan kordinat
  glutBitmapString(font, string);
  // menuliskan sebuah string dan font
}


void menuFun (char key)
{	
	switch (key){
		case 'p':
				pthread_create(&thread_looping,NULL,loop,NULL); 
				// membuat thread untuk proses looping
			    setCharacter();
			    // mentetapkan karakter
			    start = 1;
			    // isi start menjadi 1
			    playUser = 2;
			    player[0].health = 8*100;
			    player[1].health = 8*100;
				pthread_join(thread_looping,NULL);
				// jalankan thread_looping;
			break;
		case 'o':
			pthread_create(&thread_looping,NULL,loop,NULL); 
			// membuat thread untuk proses looping
		    setCharacter();
		    // mentetapkan karakter
		    start = 1;
		    // isi start menjadi 1
		    playUser = 1;
			player[0].health = 8*100;
			pthread_join(thread_looping,NULL);
			// jalankan thread_looping;
		break;
		case 'x':
				exit(0); 
			break;
		default:
         break;
	}
}