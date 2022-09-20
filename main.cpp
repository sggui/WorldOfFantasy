#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>

const int width = 500; //variável para largura do display
const int height = 700; //variável para altura do display

// teste final GIT + github

int main(void) {

	ALLEGRO_DISPLAY* display = NULL; // definindo ponteiro para display

	if (!al_init()) //inicializa a library allegro.h
		return -1; //erro ao inicializar o allegro

	display = al_create_display(width, height); // definindo tamanho do display

	al_init_primitives_addon(); //inicializa a library primitives.h


	if (!display)
		return -1; //erro ao incializar o display

	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_draw_filled_circle(width / 2, height / 2, 30, al_map_rgb(0, 0, 0));
	al_flip_display();


	while (1);

	al_destroy_display(display);


	return 0;
}