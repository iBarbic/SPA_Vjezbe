#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

typedef struct _State{
    int vuk;
    int ovca;
    int kupus;
    int brod;

} State;

State* new_game () {
   State *s = (State*)malloc(sizeof(State));
    s->vuk = 0;
    s->ovca = 0;
    s->kupus = 0;
    s->brod = 0;

    return s;
}

void print_state(State *s) {

    if(s->brod == 0) {
        printf("BROD ");
    }
    if (s->vuk == 0) {
        printf("VUK ");
    }
    if (s->ovca == 0) {
        printf("OVCA ");
    }
    if(s->kupus == 0) {
        printf("KUPUS ");
    }
    printf("\t\t\t\t");


    if(s->brod == 1) {
        printf("BROD ");
    }
    if (s->vuk == 1) {
        printf("VUK ");
    }
    if (s->ovca == 1) {
        printf("OVCA ");
    }
    if(s->kupus == 1) {
        printf("KUPUS ");
    }
    printf("\n");
}


int game_over(State *s) {
    if(s->kupus == s->ovca && s->brod != s->kupus) {
        return 1;
    }
    if(s->ovca == s->vuk && s->ovca != s->brod) {
        return 1;
    }
    return 0;
}

int goal_state(State *s) {
    if(s->vuk == 1 && s->ovca == 1 && s->kupus == 1 && s->brod == 1) {
        return 1;
    }
    return 0;
}

int next_state(State trenutno, State *potez) {


    int ns = 0;

    if (trenutno.brod == trenutno.kupus)
	{
		potez[ns].brod = !trenutno.brod;
		potez[ns].kupus = !trenutno.kupus;
		potez[ns].ovca = trenutno.ovca;
		potez[ns].vuk = trenutno.vuk;
		ns++;
	}
	if (trenutno.brod == trenutno.ovca)
	{
		potez[ns].brod = !trenutno.brod;
		potez[ns].kupus = trenutno.kupus;
		potez[ns].ovca = !trenutno.ovca;
		potez[ns].vuk = trenutno.vuk;
		ns++;
	}
	if (trenutno.brod == trenutno.vuk)
	{
		potez[ns].brod = !trenutno.brod;
		potez[ns].kupus = trenutno.kupus;
		potez[ns].ovca = trenutno.ovca;
		potez[ns].vuk = !trenutno.vuk;
		ns++;
	}
	potez[ns].brod = !trenutno.brod;
	potez[ns].kupus = trenutno.kupus;
	potez[ns].ovca = trenutno.ovca;
	potez[ns].vuk = trenutno.vuk;
	ns++;

	return ns;

}


int solve(State s, int dubina)
{

	if (dubina == 0) {
        return 0;
	}
	if (game_over(&s))
		return 0;
	if (goal_state(&s))
	{
		print_state(&s);
		return 1;
	}

    State potez[4];
	int ns = next_state(s, potez);

	for (int i = 0; i < ns; i++)
	{
		if (solve(potez[i], dubina - 1)) {
			print_state(&s);
			return 1;
		}
	}
	return 0;
}


int main() {

    State s;
    s.brod = 0;
    s.kupus = 0;
    s.ovca = 0;
    s.vuk = 0;


    solve(s, 8);



    return 0;


}
