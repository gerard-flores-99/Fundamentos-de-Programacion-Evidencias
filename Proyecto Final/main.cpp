#include <iostream>
#include <allegro.h>

using namespace std;

void pintar_nave(float cx,float cy, BITMAP *buffer); //Prototipo de la nave
void mover_nave(float &cx, float &cy, float &vx, float &vy);  //Simulaci�n de la ca�da libre

int main(){
    allegro_init();  //Inicia el entorno de Allegro
    install_keyboard();  //Hace el llamado a la funci�n del teclado, dispositivo de entrada
    set_color_depth(32);  //Formato de 32 pixeles o 32 bits
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,740,500,0,0);  //Define el tama�o de la pantalla donde se va a abrir el programa
    BITMAP *buffer = create_bitmap(740,500);  //Los BITMAPS son im�genes que se mostraran en la pantalla
                                              //El buffer es donde se van a est�r agregando todas las im�genes del juego
    float cx,cy;  //Variables para dibujar la nave, cx y cy son el centro de la nave
    float vx,vy; //Variables para la velocidad de ca�da

    cx=100; cy=100;

    while(!key[KEY_ESC]){  //Condicionamos que mientras no se presiones la tecla ESC, el juego seguira corriendo, como teclas de seguridad
        clear_to_color(buffer,0x000000);  //Hacemos que el buffer tenga un determinado color
        pintar_nave(cx,cy,buffer);
        blit(buffer,screen,0,0,0,0,740,500);  //Imprime el buffer en coordenadas determinadas junto con las coordenadas en la pantalla
        mover_nave(cx,cy,vx,vy);

        rest(20);  //Hace que el programa no ejecute todo r�pidamente y espere, al llegar a este punto, 20 ms

    }

    return 0;
}
END_OF_MAIN(); //Especif�ca el fin de la funci�n main

void pintar_nave(float cx,float cy, BITMAP *buffer){  //Funci�n para poder imprimir el dise�o de la nave en el buffer
    float nav[22] =
    {cx-20,cy+20, cx-20,cy+10, cx-20,cy, cx-10,cy-10, cx,cy-15, cx+10,cy-10,
    cx+10,cy, cx+20,cy+10, cx+20,cy+20, cx-10,cy, cx+10,cy};

    for(int i=0;i<=14;i+=2){
        line(buffer,nav[i],nav[i+1],nav[i+2],nav[i+3],0x1854E5);
        if(i==14) line(buffer,nav[i+4],nav[i+5],nav[i+6],nav[i+7],0x1854E5);
    }
}
void mover_nave(float &cx, float &cy, float &vx, float &vy){ //Simulaci�n de la ca�da libre
    float ax, ay;
    ax = 0;
    ay = 0.05;  //Aceleraci�n constante de la gravedad

    vx += ax;
    vy += ay;  //Aplicaci�n de la gravedad sobre la nave, cambios de la velocidad

    cx += vx;
    cy += vy;  //Cambio de posici�n de la nave con la gravedad

}


