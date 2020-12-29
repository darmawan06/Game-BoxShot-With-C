#include "header.h"

void createMenuFirst(){
	glLineWidth(2);
	// mengatur ukuran line/garis
	glClearColor(0.0,0.0,0.0,0.0);
	// memberiskan warna menjadi hitam
	glClear(GL_COLOR_BUFFER_BIT);
	// Menunjukkan buffer yang saat ini diaktifkan untuk penulisan warna.
	glColor3f(1.0,1.0,1.0);
	// Mengatur warna dengan 3 kordinat nilai float

	glBegin(GL_LINES);
		glVertex3f(-1.0,-0.8,0);
		glVertex3f(1.0,-0.8,0);
	glEnd();
	// mengambar line kiri	
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
		glVertex3f(-1.0,0.8,0);
		glVertex3f(1.0,0.8,0);
	glEnd();
	// mengambar line kanan	
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
		glVertex3f(-0.8,-0.8,0);
		glVertex3f(-0.8,0.8,0);
	glEnd();
	// mengambar line atas	
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
		glVertex3f(0.8,-0.8,0);
		glVertex3f(0.8,0.8,0);
	glEnd();
	// mengambar line bawah	
	glColor3f(1,1,0);
	RenderString(-0.5f, 0.6f, GLUT_BITMAP_TIMES_ROMAN_24, "WELLCOME TO GAME TENBIR BETA v0.1");
	// untuk merender string sesuai kordinat , font text dan kata kata
	glColor3f(1,1,1);
	RenderString(-0.7f, 0.1f, GLUT_BITMAP_TIMES_ROMAN_24, "O untuk mulai permainan 1 Player");
	RenderString(-0.7f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "P untuk mulai permainan 2 Player");
	RenderString(-0.7f, -0.1f, GLUT_BITMAP_TIMES_ROMAN_24, "X untuk menghentikan permainan");


	glColor3f(1,0.3,1);

	RenderString(0.3f, -0.1f, GLUT_BITMAP_TIMES_ROMAN_10, "Basuki Rahmat Firmansyah (1901092)");
	RenderString(0.3f, -0.2f, GLUT_BITMAP_TIMES_ROMAN_10, "Bimantoro A.R (1900303)");
	RenderString(0.3f, -0.3f, GLUT_BITMAP_TIMES_ROMAN_10, "Dikdik Darmawan (1901002)");
	RenderString(0.3f, -0.4f, GLUT_BITMAP_TIMES_ROMAN_10, "Mochamad Rizky Farhan Auliya (1902943)");
	RenderString(0.3f, -0.5f, GLUT_BITMAP_TIMES_ROMAN_10, "Fawwaz Kausar (1907912)");
	glutKeyboardFunc(menuFun);
	// glutKeyboardFunc menyetel panggilan balik keyboard untuk jendela saat ini. Saat pengguna mengetik di jendela, setiap penekanan tombol yang menghasilkan karakter ASCII akan menghasilkan panggilan balik keyboard.
	glFlush();
	//  mengosongkan semua perintah di buffer ini dan memaksa semua perintah yang tertunda akan segera dijalankan tanpa buffer menunggu penuh.
}

