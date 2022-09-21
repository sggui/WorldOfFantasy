#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/events.h>
#include<allegro5/keyboard.h>

//variáveis de altura e largura
const int width = 800; 
const int height = 600;


int main(void) {

	// variáveis para loop e alterar a posição do eixo Y do círculo
	bool done = false;
	float altera_y = 0;
	float altera_x = 0;

	//Objetos Allegro
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_FONT* font = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;

	//inicializa a library allegro.h
	if (!al_init())
		return -1; //erro ao inicializar o allegro


	// definindo tamanho do display
	display = al_create_display(width, height);

	
	// Addons Allegro
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();

	//erro ao incializar o display
	if (!display)
		return -1;

	// definição event_queue
	event_queue = al_create_event_queue();

	// registrando os eventos na fila
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_register_event_source(event_queue, al_get_display_event_source(display));


	// definição de fonte
	font = al_load_font("Game of Squids.ttf", 20, 0);


	while (!done) 
	{
		// ev = esperando um evento acontecer para rodar algo
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}

		// quando a tecla for pressionada, faça:
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			// pressionando a tela UP, faça:
			if (ev.keyboard.keycode == ALLEGRO_KEY_UP)
			{
				altera_y = altera_y - 10;
			}

			// pressionando a tela DOWN, faça:
			if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN)
			{
				altera_y = altera_y + 10;
			}

			// pressionando a tela RIGHT, faça:
			if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT)
			{
				altera_x = altera_x + 600;
			}
		}
		// quando a tecla for solta, faça:
		if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT)
			{
				altera_x = altera_x - 600;
			}
		}

		//muda a cor do background para branco
		al_clear_to_color(al_map_rgb(255, 255, 255));

		// cria o circulo preenchido
		al_draw_filled_circle(40 + altera_x , height / 2 + altera_y, 30, al_map_rgb(0, 0, 0));

		// inserção de texto na tela
		al_draw_text(font, al_map_rgb(0, 0, 255), width / 2, height / 2 + 100, ALLEGRO_ALIGN_CENTER, "World Of Fantasy!");

		// exibe o circulo no display
		al_flip_display(); 
	}

	// destroindo os processos rodando para liberar memória
	al_destroy_display(display);
	al_destroy_font(font);
	al_destroy_event_queue(event_queue);


	return 0;
}