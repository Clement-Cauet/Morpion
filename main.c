#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NB_GRID 3
#define VIDE	0
#define ROND	1
#define CROIX	2

int game_nul = 0;

typedef struct {
    int grid[NB_GRID][NB_GRID];
	int player;
}
morpion;


int verif_game(morpion morpion) {

	if ((morpion.grid[0][0] == morpion.grid[0][1] && morpion.grid[0][1] == morpion.grid[0][2] && morpion.grid[0][0] != morpion.player && morpion.grid[0][0] != VIDE) ||
		(morpion.grid[1][0] == morpion.grid[1][1] && morpion.grid[1][1] == morpion.grid[1][2] && morpion.grid[1][0] != morpion.player && morpion.grid[1][0] != VIDE) ||
		(morpion.grid[2][0] == morpion.grid[2][1] && morpion.grid[2][1] == morpion.grid[2][2] && morpion.grid[2][0] != morpion.player && morpion.grid[2][0] != VIDE))
		return 1;
	else if ((morpion.grid[0][0] == morpion.grid[1][0] && morpion.grid[1][0] == morpion.grid[2][0] && morpion.grid[0][0] != morpion.player && morpion.grid[0][0] != VIDE) ||
			(morpion.grid[0][1] == morpion.grid[1][1] && morpion.grid[1][1] == morpion.grid[2][1] && morpion.grid[0][1] != morpion.player && morpion.grid[0][1] != VIDE) ||
			(morpion.grid[0][2] == morpion.grid[1][2] && morpion.grid[1][2] == morpion.grid[2][2] && morpion.grid[0][2] != morpion.player && morpion.grid[0][2] != VIDE))
			return 1;
	else if ((morpion.grid[0][0] == morpion.grid[1][1] && morpion.grid[1][1] == morpion.grid[2][2] && morpion.grid[0][0] != morpion.player && morpion.grid[0][0] != VIDE) ||
			(morpion.grid[0][2] == morpion.grid[1][1] && morpion.grid[1][1] == morpion.grid[2][0] && morpion.grid[0][2] != morpion.player && morpion.grid[0][2] != VIDE))
			return 1;
	else if (morpion.grid[0][0] != VIDE && morpion.grid[1][0] != VIDE && morpion.grid[2][0] != VIDE &&
		morpion.grid[1][0] != VIDE && morpion.grid[1][1] != VIDE && morpion.grid[1][2] != VIDE &&
		morpion.grid[2][0] != VIDE && morpion.grid[2][1] != VIDE && morpion.grid[2][2] != VIDE) {
		game_nul = 1;
		return 1;
	}
			
	else 
		return 0;
}

int grid_game(morpion morpion, int coordx, int coordy) {

	printf("+-+-+-+\n");
	for (int i = 0; i < NB_GRID; i++) {
		printf("|");
		for (int j = 0; j < NB_GRID; j++) {
			switch (morpion.grid[j][i])
			{
			case VIDE:
				printf(" |");
				break;
			case ROND:
				printf("O|");
				break;
			case CROIX:
				printf("X|");
				break;
			}
		}
		printf("\n+-+-+-+\n");
	}
	return 1;
}

int main()
{
	morpion morpion;

	morpion.player = ROND;

	int coordx = 0, coordy = 0, numpad, verif_numpad = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			morpion.grid[i][j] = VIDE;
		}
	}

	grid_game(morpion, coordx, coordy);

	while (verif_game(morpion) != 1) {

		if (verif_numpad != 1) {
			while (verif_numpad != 1) {
				printf("Au Joueur %d de jouer\nJouer avec les touches du numpad: ", morpion.player);
				while (scanf("%d", &numpad) != 1) {
					printf("Saisie incorrect");
					return 0;
				}

				switch (numpad)
				{
				case 1:
					coordx = 2;
					coordy = 0;
					if (morpion.grid[coordy][coordx] == VIDE) {
						morpion.grid[coordy][coordx] = morpion.player;
						verif_numpad = 1;
					}
					else {
						verif_numpad = 0;
					}
					break;
				case 2:
					coordx = 2;
					coordy = 1;
					if (morpion.grid[coordy][coordx] == VIDE) {
						morpion.grid[coordy][coordx] = morpion.player;
						verif_numpad = 1;
					}
					else {
						verif_numpad = 0;
					}
					break;
				case 3:
					coordx = 2;
					coordy = 2;
					if (morpion.grid[coordy][coordx] == VIDE) {
						morpion.grid[coordy][coordx] = morpion.player;
						verif_numpad = 1;
					}
					else {
						verif_numpad = 0;
					}
					break;
				case 4:
					coordx = 1;
					coordy = 0;
					if (morpion.grid[coordy][coordx] == VIDE) {
						morpion.grid[coordy][coordx] = morpion.player;
						verif_numpad = 1;
					}
					else {
						verif_numpad = 0;
					}
					break;
				case 5:
					coordx = 1;
					coordy = 1;
					if (morpion.grid[coordy][coordx] == VIDE) {
						morpion.grid[coordy][coordx] = morpion.player;
						verif_numpad = 1;
					}
					else {
						verif_numpad = 0;
					}
					break;
				case 6:
					coordx = 1;
					coordy = 2;
					if (morpion.grid[coordy][coordx] == VIDE) {
						morpion.grid[coordy][coordx] = morpion.player;
						verif_numpad = 1;
					}
					else {
						verif_numpad = 0;
					}
					break;
				case 7:
					coordx = 0;
					coordy = 0;
					if(morpion.grid[coordy][coordx] == VIDE) {
						morpion.grid[coordy][coordx] = morpion.player;
						verif_numpad = 1;
					}
					else {
						verif_numpad = 0;
					}
					break;
				case 8:
					coordx = 0;
					coordy = 1;
					if (morpion.grid[coordy][coordx] == VIDE) {
						morpion.grid[coordy][coordx] = morpion.player;
						verif_numpad = 1;
					}
					else {
						verif_numpad = 0;
					}
					break;
				case 9:
					coordx = 0;
					coordy = 2;
					if (morpion.grid[coordy][coordx] == VIDE) {
						morpion.grid[coordy][coordx] = morpion.player;
						verif_numpad = 1;
					}
					else {
						verif_numpad = 0;
					}
					break;
				default:
					verif_numpad = 0;
					break;
				}
				
			}
		}

		verif_numpad = 0;

		grid_game(morpion, coordx, coordy);

		if (morpion.player == ROND)
			morpion.player = CROIX;
		else
			morpion.player = ROND;
	}
	if (game_nul != 1) {
		if (morpion.player == ROND)
			morpion.player = CROIX;
		else
			morpion.player = ROND;
		printf("\nJoueur %d remporte la victoire\n", morpion.player);
	}
	else
		printf("\nMatch nul\n");
}



