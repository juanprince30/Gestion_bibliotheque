#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 100

#ifndef GESTION_CATEGORIE_H
#define GESTION_CATEGORIE_H


int supprimer_saut_categorie(char *chaine, int longueur)
{
char *positionEntree = NULL;

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

void ajouter_categorie(int *nbCategories) {
    char nomNouvelleCategorie[500];

    // Demander ï¿½ l'utilisateur d'entrer le nom de la nouvelle catï¿½gorie
    printf("Entrez le nom de la nouvelle categorie : ");
    fgets(nomNouvelleCategorie,500,stdin);
	supprimer_saut_categorie(nomNouvelleCategorie, 500);

    FILE *fichierCategories = fopen("categories.txt", "r");
    if (fichierCategories == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier des categories.\n");
        exit(1);
    }

    char nomCategorie[50];
    while (fscanf(fichierCategories, "%s", nomCategorie) != EOF) {
        if (strcmp(nomCategorie, nomNouvelleCategorie) == 0) {
            fclose(fichierCategories);
            printf("Cette categorie existe deja!! \n");
            return;
        }
    }

    fclose(fichierCategories);

    
    char nomFichier[500];
    char nomfichierid[500];
    char nomfichierauteur[500];
    char nomfichiertitre[500];
    sprintf(nomFichier, "%s.txt", nomNouvelleCategorie);
    sprintf(nomfichierid, "%s_id.txt", nomNouvelleCategorie);
    sprintf(nomfichierauteur, "%s_auteur.txt", nomNouvelleCategorie);
    sprintf(nomfichiertitre, "%s_titre.txt", nomNouvelleCategorie);

    FILE *fichierCategorie = fopen(nomFichier, "w");
    FILE *fichierid = fopen(nomfichierid, "w");
    FILE *fichierauteur = fopen(nomfichierauteur, "w");
    FILE *fichiertitre = fopen(nomfichiertitre, "w");
    
    if (fichierCategorie == NULL) {
        fprintf(stderr, "Erreur lors de la creation du fichier de la categorie.\n");
        exit(1);
    }
    if (fichierid == NULL) {
        fprintf(stderr, "Erreur lors de la creation du fichier de la categorie.\n");
        exit(1);
    }
    if (fichierauteur == NULL) {
        fprintf(stderr, "Erreur lors de la creation du fichier de la categorie.\n");
        exit(1);
    }
    if (fichiertitre == NULL) {
        fprintf(stderr, "Erreur lors de la creation du fichier de la categorie.\n");
        exit(1);
    }
    fclose(fichierCategorie);
    fclose(fichierid);
    fclose(fichiertitre);
    fclose(fichierauteur);

    fichierCategories = fopen("categories.txt", "a");
    if (fichierCategories == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier des categories.\n");
        exit(1);
    }
    fprintf(fichierCategories, "%s\n", nomNouvelleCategorie);
    fclose(fichierCategories);

    (*nbCategories)++;

    printf("La categorie a ete ajoutee avec succes.\n");
}


void supprimer_categorie(int *nbCategories) {
    char nomCategorieASupprimer[500];
    int indexCategorieASupprimer = -1;

    // Demander ï¿½ l'utilisateur d'entrer le nom de la catï¿½gorie ï¿½ supprimer
    printf("Entrez le nom de la categorie a supprimer : ");
    fgets(nomCategorieASupprimer,500,stdin);
	supprimer_saut_categorie(nomCategorieASupprimer, 500);
	
	char nomCategorieASupprimer_avec_saut[50];
    strcpy(nomCategorieASupprimer_avec_saut, nomCategorieASupprimer);
    strcat(nomCategorieASupprimer_avec_saut, "\n");

    // Rechercher l'index de la catï¿½gorie ï¿½ supprimer dans le fichier des catï¿½gories
    FILE *fichierCategories = fopen("categories.txt", "r");
    if (fichierCategories == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier des categories.\n");
        exit(1);
    }

    char nomCategorie[500];
    int i = 0;
    while ((fgets(nomCategorie, sizeof(nomCategorie), fichierCategories)) != NULL) {
        if (strcmp(nomCategorie, nomCategorieASupprimer_avec_saut) == 0) {
            indexCategorieASupprimer = i;
            break;
        }
        i++;
    }

    fclose(fichierCategories);

    if (indexCategorieASupprimer != -1) {
        
        char nomFichier[60];
        char nomfichierid[60];
        char nomfichierauteur[60];
        char nomfichiertitre[60];
        sprintf(nomFichier, "%s.txt", nomCategorieASupprimer);
        sprintf(nomfichierid, "%s_id.txt", nomCategorieASupprimer);
        sprintf(nomfichierauteur, "%s_auteur.txt", nomCategorieASupprimer);
        sprintf(nomfichiertitre, "%s_titre.txt", nomCategorieASupprimer);

        remove(nomFichier);
		remove(nomfichierid);
		remove(nomfichierauteur);
		remove(nomfichiertitre);

        FILE *fichierTemporaire = fopen("temp.txt", "w");
        if (fichierTemporaire == NULL) {
            fprintf(stderr, "Erreur lors de la creation du fichier temporaire.\n");
            exit(1);
        }

        fichierCategories = fopen("categories.txt", "r");
        if (fichierCategories == NULL) {
            fprintf(stderr, "Erreur lors de l'ouverture du fichier des categories.\n");
            exit(1);
        }

        i = 0;
        while ((fgets(nomCategorie, sizeof(nomCategorie), fichierCategories)) != NULL) {
            if (i != indexCategorieASupprimer) {
                fprintf(fichierTemporaire, "%s", nomCategorie);
            }
            i++;
        }

        fclose(fichierCategories);
        fclose(fichierTemporaire);

        remove("categories.txt");

        rename("temp.txt", "categories.txt");

        (*nbCategories)--;

        printf("La categorie a ete supprimee avec succes.\n");
    } 
	else {
        printf("La categorie n'existe pas.\n");
    }
}


void Afficher_categorie(int nbCategories) {
    FILE *fichierCategories = fopen("categories.txt", "r");
    if (fichierCategories == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier des categories.\n");
        exit(1);
    }

    char nomCategorie[500];
    printf("\nListe des categories :\n");
    while ((fgets(nomCategorie, sizeof(nomCategorie), fichierCategories)) != NULL) {
        printf("%s", nomCategorie);
    }

    fclose(fichierCategories);
}


#endif

