#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_LINE_LENGTH 1000
#ifndef RECHERCHE_LIVRE_H
#define RECHERCHE_LIVRE_H

int supprimer_saut_recherche(char *chaine, int longueur)
{
char *positionEntree = NULL;
// On lit le texte saisi au clavier
	if (fgets(chaine, longueur, stdin) != NULL) // Pas d'erreur desaisie ?
	{
		positionEntree = strchr(chaine, '\n'); // On recherchel'"Entrée"
		if (positionEntree != NULL) // Si on a trouvé le retour àla ligne
		{
			*positionEntree = '\0'; // On remplace ce caractère par\0
		}
	return 1; // On renvoie 1 si la fonction s'est déroulée sans erreur
	}
	else
	{
		return 0; // On renvoie 0 s'il y a eu une erreur
	}
}

int afficher_recherche(const char* nomCategorie, int id)
{
	FILE *fichier;
    char ligne[MAX_LINE_LENGTH];

    fichier = fopen(nomCategorie, "r");

    if (fichier == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }
	int nombreligne =0;
	printf("Listes des ROMANS Trouve: \n");
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
		nombreligne++;
		if (nombreligne== id){
			printf("%s", ligne);
		}
	}
    fclose(fichier);

    return 0;
}

void recherche_par_titre()
{
	char nomCategorie[500];
	char nomcat[500];
    int identifiant_recherche[50];
    char categorie_recherche[50][50];
    char cat[50][50];
    int trouve =0;
	int i;
	
	
	printf("Veuillez saisi le titre du Roman que vous rechercher: ");
	fgets(nomcat,500,stdin);
	supprimer_saut_recherche(nomcat, 500);
	
	FILE *fichierCategories = fopen("categories.txt", "r");
    if (fichierCategories == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier des catï¿½gories.\n");
        exit(1);
    }
	
	i= 0;
    while (fgets(nomCategorie, sizeof(nomCategorie), fichierCategories) != NULL) {
        
        nomCategorie[strcspn(nomCategorie, "\n")] = 0;
		char temp[50];
    	strcpy(temp, nomCategorie);
    	strcat(temp, ".txt");
        
        char nomFichier[50];
        snprintf(nomFichier, sizeof(nomFichier), "%s_titre.txt", nomCategorie);

        FILE *fichier = fopen(nomFichier, "r");
        if (fichier == NULL) {
            fprintf(stderr, "Erreur lors de l'ouverture du fichier %s.\n", nomFichier);
            continue; 
        }
		
        char ligne[MAX_LINE_LENGTH];
        int numeroLigne = 0;
        while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
            numeroLigne++;
            if (strstr(ligne, nomcat) != NULL) {
                i++;
                identifiant_recherche[i-1]=numeroLigne;
                strcpy(categorie_recherche[i-1], temp);
                strcpy(cat[i-1],nomCategorie);
                trouve =1;
            }
        }
		
        fclose(fichier);
    }
    
    if(trouve== 1)
    {
    	int j;
    	for(j=0; j<i; j++)
    	{
    		printf("Dans la Categorie %s : \t",cat[j]);
			afficher_recherche(categorie_recherche[j], identifiant_recherche[j]);
		}

	}
	else
	{
		printf("Desole!! Nous n'avons pas pu trouve de titre correspondant a votre recherche\n");
	}
    
    fclose(fichierCategories);
    
	
}

void recherche_par_auteur()
{
	char nomCategorie[500];
	char nomcat[500];
    int identifiant_recherche[50];
    char categorie_recherche[50][50];
    char cat[50][50];
    int trouve=0;
	int i;
	
	
	printf("Veuillez saisi le Nom de l'auteur du Roman que vous rechercher: ");
	fgets(nomcat,500,stdin);
	supprimer_saut_recherche(nomcat, 500);
	
	FILE *fichierCategories = fopen("categories.txt", "r");
    if (fichierCategories == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier des catï¿½gories.\n");
        exit(1);
    }
	
	i= 0;
    while (fgets(nomCategorie, sizeof(nomCategorie), fichierCategories) != NULL) {
        
        nomCategorie[strcspn(nomCategorie, "\n")] = 0;
		char temp[50];
    	strcpy(temp, nomCategorie);
    	strcat(temp, ".txt");
        
        char nomFichier[50];
        snprintf(nomFichier, sizeof(nomFichier), "%s_auteur.txt", nomCategorie);

        FILE *fichier = fopen(nomFichier, "r");
        if (fichier == NULL) {
            fprintf(stderr, "Erreur lors de l'ouverture du fichier %s.\n", nomFichier);
            continue; 
        }
		
        char ligne[MAX_LINE_LENGTH];
        int numeroLigne = 0;
        while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
            numeroLigne++;
            if (strstr(ligne, nomcat) != NULL) {
                i++;
                identifiant_recherche[i-1]=numeroLigne;
                strcpy(categorie_recherche[i-1], temp);
                strcpy(cat[i-1], nomCategorie);
                trouve=1;
            }
        }
		
        fclose(fichier);
    }
    if(trouve== 1)
    {
    	int j;
    	for(j=0; j<i; j++)
    	{
    		printf("Dans la Categorie %s : \t",cat[j]);
			afficher_recherche(categorie_recherche[j], identifiant_recherche[j]);
		}

	}
	else
	{
		printf("Desoler!! Nous n'avons pas pu trouve un auteur correspondant a votre recherche\n");
	}

    fclose(fichierCategories);
    
	
}


const char* recherche_par_categorie()
{
	char* nomcat = (char*)malloc(500);
	char nomCategorie[500];
	int categorieTrouve=0; 
	
	printf("Veuillez saisi la categorie que vous rechercher: ");
	fgets(nomcat,500,stdin);
	supprimer_saut_recherche(nomcat, 500);
	
	FILE* fichierCategories= fopen("categories.txt", "r");
	if (fichierCategories == NULL)
	{
		fprintf(stderr, "Erreur lors de l'ouverture du fichier des categories.\n");
        exit(1);
    }
    
    while (fscanf(fichierCategories, "%s", nomCategorie) != EOF) 
	{
        if (strcmp(nomCategorie, nomcat) == 0) 
		{
			categorieTrouve=1;
            break;
        }
    }
    
	if(categorieTrouve!= 1)
    {
        printf("Nous n'avons pas trouver de categorie correspondant a votre recherche\n");
		free(nomcat);
		nomcat=NULL;
		return "0";
	}
	else
	{
			printf("Categorie %s Trouve\n", nomcat);
			printf("Ouverture en cours... \n");
			sleep(4);
            return nomcat;
            
	}
	fclose(fichierCategories);	
	
}

int afficher_recherche_categorie(const char* nomCategorie) 
{
    if(nomCategorie== "0")
    {
    	return 0;
	}
	else
	{
		char temp[50];
    	strcpy(temp, nomCategorie);
    	strcat(temp, ".txt");
    
		FILE *fichier;
    	char ligne[MAX_LINE_LENGTH];

    	fichier = fopen(temp, "r");

    	if (fichier == NULL) {
    	    fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
    	    return 1;
    	}
	
		printf("Listes des ROMANS: \n");
    	while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
    	    printf("%s", ligne);
    	}

    	fclose(fichier);

    	return 0;	
	}
}

#endif
