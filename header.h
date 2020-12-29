#include <GL/freeglut.h>
#include <GL/gl.h>
// Library openGL
#include <pthread.h>
// Library thread
#include <string.h>
// Library String

typedef struct {
	GLfloat x,y1,y2,attack,bulletX,bulletY;
	// x,y1,y2 adalah kordinat posisi Character
	// attack untuk menandakan menyerang atau tidak
	// bulletX, bulley Y untuk kordinat peluru pada setiap karakter
	GLint health,checkThread,efekKenaDamage;
	// untuk nyawa pada setiap karakter
}Character;
// Dibungkus dengan nama Character

Character player[2];
Character enemy[4];
Character enemyKing;
// Membuat karakter dan musuh dari bungkusan di Charachter

int start,playUser;
int win,efekMemberiDamage,efekKenaDamage[2];
// lalu ada variabel mulai dan menang
pthread_t thread[5],threadKing,thread_player[3];
// membuat variabel thread untuk musuh
pthread_t thread_looping;
// membuat variabel thread untuk setiap looping
pthread_mutex_t lock;
void moveFunP1 (char key);
void moveFunP2 (char key);
// Prosedur untuk memindahkan karakter
void drawCharacterPlayer(void *player_ppt, int i);
// Prosedur untuk mengambar karakter
void setCharacter();
// Untuk menetapkan karakter
void drawBullet(void *enemy_ppt);
// Untuk mengambar peluru
void loop();
// untuk proses looping
void InteractionPlayer();
// untuk interaksi serangan musuh ke player
void InteractionEnemy(void *enemy_ppt);
// untuk interaksi serangan player ke musuh
void displayRender();
// untuk merender layar
void* enemy_automatic_enemy(void* enemy_ppt);
// untuk mengerakan atau menembak otomatis pada musuh
void prosesAttack();
void* bulletAttackP(void* player_ppt);
void* prosesAttackPlayer(void* player_ppt);
// untuk mengerakan peluru player
void* bulletAttackEnemy(void* enemy_ppt);
// untuk mengerakan peluru musuh
void menuFun (char key);
// untuk menentukan mulai bermain atau berhenti
void createMenuFirst();
// membuat menu pertama
void createMenuLast();
// membuat menu kedua
void RenderString(float x, float y, void *font, const char* string);
// untuk merender string