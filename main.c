#include "header.h"
// Memanggil file header

int main(int argc, char** argv)
{
    // Mulai program
	start = 0;
    glutInit(&argc, argv);
    // glutInit akan menginisialisasi pustaka GLUT dan menegosiasikan sesi dengan sistem window.
    glutInitDisplayMode(GLUT_SINGLE);
    // glutInitDisplayMode menyetel mode tampilan awal.
    // untuk memilih jendela buffer tunggal. Ini adalah default jika GLUT_DOUBLE atau GLUT_SINGLE tidak ditentukan.
    glutInitWindowSize(1200,800);
    glutInitWindowPosition(100,100);
    //  glutInitWindowPosition dan glutInitWindowSize masing-masing mengatur posisi dan ukuran window awal.
    glutCreateWindow("KELOMPOK TENBIR");
    // glutCreateWindow membuat window. Nama akan diberikan ke sistem jendela window nama window.
   	createMenuFirst();
    // membuat menu pertama
	glutMainLoop();
    // glutMainLoop memasuki loop pemrosesan perintah GLUT.
    return 0;
}