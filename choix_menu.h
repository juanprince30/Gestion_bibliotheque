#include <stdio.h>
#include <unistd.h>
#include "menu.h"
#include "gestion_livre.h"
#include "gestion_categories.h"
#include "recherche_livre.h"

#define MAX_CATEGORIES 100
#ifndef CHOIX_MENU_H
#define CHOIX_MENU_H

void clean(void)
{
	#ifdef _WIN32
        system("cls");
    #else
       	system("clear");
   	#endif
}

int choix_menu (void)
{
	int choix;
	printf("\n");
	printf(" \t Veuillez Entrer votre choix : \t");
	scanf("%d",&choix); 
	while (choix < 0 || choix > 3 )
	{ 
		printf("\t ERREUR !!!! Veuillez choisir entre les chiffres propose!!! \n");
		printf("\n");
		printf(" \t Veuillez Entrer votre choix : \t");
		scanf("%d",&choix);	
	}
	
	return choix;
}

int choix_menu_livre (void)
{
	int choix;
	printf("\n");
	printf(" \t Veuillez Entrer votre choix : \t");
	scanf("%d",&choix); 
	while (choix < 0 || choix > 4)
	{ 
		printf("\t ERREUR !!!! Veuillez choisir entre les chiffres propose!!! \n");
		printf("\n");
		printf(" \t Veuillez Entrer votre choix : \t");
		scanf("%d",&choix);	
	}
	
	return choix;
}

void redirection_vers_choix_menu (int choix) 
{
	if(choix==1 )
	{
		printf("\n");
		menu_categories();
	}
	else if(choix==2 )
	{
		printf("\n");
		gestion_livres();
	}
	else if(choix==3 )
	{
		printf("\n");
		menu_recherche ();
	}
	else
	{
		printf("\n");
		printf("\t FERMETURE DU PROGRAMME EN COUR...");
		sleep(5);
	}
}

void redirection_vers_la_gestion_des_livres (int choix) 
{
	if(choix==1 )
	{
		const char* categorie;
		printf("\n");
		categorie= dans_quel_categorie_ajout();
		ajouter_livre(categorie);
	}
	else if(choix==2 )
	{
		const char* categorie;
		printf("\n");
		categorie= dans_quel_categorie_supprimer();
		supprimer_livre(categorie);
	}
	else if(choix==3 )
	{
		printf("\n");
		const char* categorie;
		printf("\n");
		categorie= dans_quel_categorie_modifier();
		modifier_livre(categorie);
	}
	else if(choix==4 )
	{
		const char* categorie;
		printf("\n");
		categorie=dans_quel_categorie_information();
		informations_livres(categorie);
		sleep(4);
	}
	else
	{
		printf("\n");
		menu_principal();
		clean();
	}
}

void redirection_vers_la_gestion_des_categories (int choix) 
{
	
    int nbCategories = 0;
	if(choix==1 )
	{
		printf("\n");
		ajouter_categorie( &nbCategories);
	}
	else if(choix==2 )
	{
		printf("\n");
		supprimer_categorie( &nbCategories);
	}
	else if(choix==3 )
	{
		printf("\n");
		Afficher_categorie(nbCategories);
	}
	else
	{
		printf("\n");
		menu_principal();
		clean();
	}
}


void redirection_vers_la_recherche_des_livres (int choix) 
{
	if(choix==1 )
	{
		printf("\n");
		recherche_par_titre();
	}
	else if(choix==2 )
	{
		printf("\n");
		recherche_par_auteur();
	}
	else if(choix==3 )
	{
		const char* categorie;
		printf("\n");
		categorie= recherche_par_categorie();
		afficher_recherche_categorie(categorie);
	}
	else
	{
		printf("\n");
		menu_principal();
	}
}


#endif
