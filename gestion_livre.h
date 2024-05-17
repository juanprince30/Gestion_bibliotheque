#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_LINE_LENGTH 1000
#ifndef GESTION_LIVRE_H
#define GESTION_LIVRE_H

typedef struct 
{
	int ID;
    char titre[500];
    char auteur[500];
    char date_de_publication[500];
    char genre[500];
    float prix;
    int nombre_de_stock;
} Livre;

int supprimer_saut_livre(char *chaine, int longueur)
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

int identifiant(const char* nomCategorie)
{
	int compteur;
	char temp[50];
    strcpy(temp, nomCategorie);
    strcat(temp, "_id.txt");
    
	FILE *fichier;
    char ligne[MAX_LINE_LENGTH];

    fichier = fopen(temp, "r");
	
    if (fichier == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }
    
    compteur=1;
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        compteur++;
    }
    fclose(fichier);
	
	return compteur;
}

const char* dans_quel_categorie_ajout()
{
	char* nomcat = (char*)malloc(500);
	char nomCategorie[500];
	int categorieTrouve=0; 
	
	printf("Veuillez saisi la categorie dans laquelle vous vouliez ajouter le Roman: ");
	fgets(nomcat,500,stdin);
	supprimer_saut_livre(nomcat, 500);

	char temp2[500];
    strcpy(temp2, nomcat);
    strcat(temp2, "\n");
	
	FILE* fichierCategories= fopen("categories.txt", "r");
	if (fichierCategories == NULL)
	{
		fprintf(stderr, "Erreur lors de l'ouverture du fichier des categories.\n");
        exit(1);
    }
    
    while (fgets(nomCategorie, sizeof(nomCategorie), fichierCategories) != NULL) 
	{
        
		if (strcmp(nomCategorie, temp2) == 0) 
		{
			categorieTrouve=1;
            break;
        }
    }
    
	if(categorieTrouve!= 1)
    {
        printf("ERREUR!! \n La categorie entree n'exite pas!! Veuillez vous assurer que la categorie souhaite soit cree d'abord avant d'y ajouter un Roman\n");
		free(nomcat);
		nomcat=NULL;
		return "0";
	}
	else
	{
			printf("Vous avez choisit la categorie %s \n", nomcat);
			printf("Ouverture en cours... \n");
			sleep(4);
            return nomcat;
            
	}
	fclose(fichierCategories);
	
}

const char* dans_quel_categorie_information()
{
	char* nomcat = (char*)malloc(500);
	char nomCategorie[500];
	int categorieTrouve=0; 
	
	printf("Veuillez saisi la categorie ou vous voulez voir les Romans: ");
	fgets(nomcat,500,stdin);
	supprimer_saut_livre(nomcat, 500);
	
	char temp2[500];
    strcpy(temp2, nomcat);
    strcat(temp2, "\n");
	
	FILE* fichierCategories= fopen("categories.txt", "r");
	if (fichierCategories == NULL)
	{
		fprintf(stderr, "Erreur lors de l'ouverture du fichier des categories.\n");
        exit(1);
    }
    
    while (fgets(nomCategorie, sizeof(nomCategorie), fichierCategories) != NULL) 
	{
        
		if (strcmp(nomCategorie, temp2) == 0) 
		{
			categorieTrouve=1;
            break;
        }
    }
    
	if(categorieTrouve!= 1)
    {
        printf("ERREUR!! \n La categorie entree n'exite pas!! Veuillez vous assurer que la categorie souhaite soit cree d'abord avant d'afficher les informations des Roman\n");
		free(nomcat);
		nomcat=NULL;
		return "0";
	}
	else
	{
			printf("Vous avez choisit la categorie %s \n", nomcat);
			printf("Ouverture en cours... \n");
			sleep(4);
            return nomcat;
            
	}
	fclose(fichierCategories);
	
}

const char* dans_quel_categorie_supprimer()
{
	char* nomcat = (char*)malloc(500);
	char nomCategorie[500];
	int categorieTrouve=0; 
	
	printf("Veuillez saisi la categorie dans laquelle vous voulez suprprimer le Roman: ");
	fgets(nomcat,500,stdin);
	supprimer_saut_livre(nomcat, 500);
	
	char temp2[500];
    strcpy(temp2, nomcat);
    strcat(temp2, "\n");
	
	FILE* fichierCategories= fopen("categories.txt", "r");
	if (fichierCategories == NULL)
	{
		fprintf(stderr, "Erreur lors de l'ouverture du fichier des categories.\n");
        exit(1);
    }
    
    while (fgets(nomCategorie, sizeof(nomCategorie), fichierCategories) != NULL) 
	{
        
		if (strcmp(nomCategorie, temp2) == 0) 
		{
			categorieTrouve=1;
            break;
        }
    }
    
	if(categorieTrouve!= 1)
    {
        printf("ERREUR!! \n La categorie entree n'exite pas!! Veuillez vous assurer que la categorie souhaite soit cree d'abord avant de vouloir supprimer un Roman\n");
		free(nomcat);
		nomcat=NULL;
		return "0";
	}
	else
	{
			printf("Vous avez choisit la categorie %s \n", nomcat);
			printf("Ouverture en cours... \n");
			sleep(4);
            return nomcat;
            
	}
	fclose(fichierCategories);
	
}

const char* dans_quel_categorie_modifier()
{
	char* nomcat = (char*)malloc(500);
	char nomCategorie[500];
	int categorieTrouve=0; 
	
	printf("Veuillez saisi la categorie dans laquelle vous voulez modifier les informations d'un roman: ");
	fgets(nomcat,500,stdin);
	supprimer_saut_livre(nomcat, 500);
	
	char temp2[500];
    strcpy(temp2, nomcat);
    strcat(temp2, "\n");
	
	FILE* fichierCategories= fopen("categories.txt", "r");
	if (fichierCategories == NULL)
	{
		fprintf(stderr, "Erreur lors de l'ouverture du fichier des categories.\n");
        exit(1);
    }
    
    while (fgets(nomCategorie, sizeof(nomCategorie), fichierCategories) != NULL) 
	{
        
		if (strcmp(nomCategorie, temp2) == 0) 
		{
			categorieTrouve=1;
            break;
        }
    }
    
	if(categorieTrouve!= 1)
    {
        printf("ERREUR!! \n La categorie entree n'exite pas!! Veuillez vous assurer que la categorie souhaite soit cree d'abord avant de vouloir modifier les informations d'un Roman\n");
		free(nomcat);
		nomcat=NULL;
		return "0";
	}
	else
	{
			printf("Vous avez choisit la categorie %s \n", nomcat);
			printf("Ouverture en cours... \n");
			sleep(4);
            return nomcat;
            
	}
	fclose(fichierCategories);
	
}

int ajouter_livre(const char* nomCategorie) 
{
	if (nomCategorie== "0")
    {
    	return 0;
	}
	
	else
	{
    	Livre ajout;
    	
    	ajout.ID=identifiant(nomCategorie);
    	printf("\t Veuillez entrer le titre du livre :\t");
		supprimer_saut_livre(ajout.titre, 500);
    	printf("\t Veuillez entrer le nom de l'auteur du livre :\t");
		supprimer_saut_livre(ajout.auteur, 500);
    	printf("\t Entrer la date de publication :\t");
		supprimer_saut_livre(ajout.date_de_publication, 500);
    	printf("\t Veuillez entrer le genre du livre :\t");
		supprimer_saut_livre(ajout.genre, 500);
    	printf("\t Veuillez entrer le prix du livre :\t");
    	scanf("%f", &ajout.prix);
    	printf("\t Veuillez entrer le nombre en stock :\t");
    	scanf("%d", &ajout.nombre_de_stock);

    	FILE *fichier, *fichierauteur, *fichiertitre, *fichierid;
    	char temp[50];
    	strcpy(temp, nomCategorie);
    	strcat(temp, ".txt");
    	
		fichier = fopen(temp, "a");
		if (fichier == NULL) 
		{
        	fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
        	return 1;
    	}
    	
    	char temp3[50];
    	strcpy(temp3, nomCategorie);
    	strcat(temp3, "_auteur.txt");
    	fichierauteur = fopen(temp3, "a");
		if (fichierauteur == NULL) 
		{
        	fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
        	return 1;
    	}
    	
    	char temp2[50];
    	strcpy(temp2, nomCategorie);
    	strcat(temp2, "_titre.txt");
    	fichiertitre = fopen(temp2, "a");
		if (fichiertitre == NULL) 
		{
        	fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
        	return 1;
    	}
    	
    	char temp1[50];
    	strcpy(temp1, nomCategorie);
    	strcat(temp1, "_id.txt");
		fichierid = fopen(temp1, "a");
		if (fichierid == NULL) 
		{
        	fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
        	return 1;
    	}
    	
    	fprintf(fichier, "ID: %d\t  Titre: %s\t  Auteur:%s\t Date Publication: %s\t Genre: %s\t Prix: %f FCFA\t Stock: %d ",ajout.ID, ajout.titre, ajout.auteur, ajout.date_de_publication, ajout.genre, ajout.prix, ajout.nombre_de_stock);
    	fprintf(fichier, "\n");

		fprintf(fichierauteur,"%s", ajout.auteur);
		fprintf(fichierauteur, "\n");
		
		fprintf(fichiertitre, "%s", ajout.titre);
		fprintf(fichiertitre, "\n");
		
		fprintf(fichierid, "%d",ajout.ID);
		fprintf(fichierid, "\n");
		
		fclose(fichierauteur);
		fclose(fichiertitre);
		fclose(fichierid);
    	fclose(fichier);
		
    	printf("\t L'enregistrement du livre a ete effectue avec succes.\n");
    	return 0;
	}
}


int informations_livres(const char* nomCategorie) 
{
    if (nomCategorie== "0")
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

int nombre_ligne(const char* nomCategorie)
{
	
	int compteur ;
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
    
    compteur=0;
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        compteur++;
    }
    fclose(fichier);
	
	return compteur;
}

int mettre_a_jour(const char* nomCategorie)
{
	int ligne_total, ligne_supprimer, numeroligne, nl;
	char ligne[MAX_LINE_LENGTH];
	char ligne_cut[MAX_LINE_LENGTH-7];
	ligne_total =nombre_ligne(nomCategorie);
	
	char temp[50];
    strcpy(temp, nomCategorie);
    strcat(temp, ".txt");
    char temp1[50];
    strcpy(temp1, nomCategorie);
    strcat(temp1, "_id.txt");
	
	FILE *fichier, *fichiersortie , *fichierid, *fichieridsortie;
	
	fichier = fopen(temp, "r");
    if (fichier == NULL) 
	{
        fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }
    
    fichiersortie = fopen("temp.txt", "w");
    if (fichier == NULL) {
    	fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
    	return 1;
    }
    
    fichierid = fopen(temp1, "r");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
    	return 1;
    }
    
    fichieridsortie = fopen("tempid.txt", "w");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }
    
    int i,j,g;
    char l[MAX_LINE_LENGTH];
    g= 1;
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
    	for (i = 7, j = 0; i < MAX_LINE_LENGTH; i++, j++) 
		{
        	ligne_cut[j] = ligne[i];
    	}
    	fprintf(fichiersortie, "ID: %d\t  ", g);  
		fputs(ligne_cut, fichiersortie);
		g++;
    }
    
    for (i=0; i<ligne_total; i++)
    {
       		fprintf(fichieridsortie,"%d\n", i+1);
	}
	
    
	fclose(fichier);
    fclose(fichierid);
    fclose(fichiersortie);
    fclose(fichieridsortie);
    
    remove(temp);
    remove(temp1);
    rename("temp.txt", temp);
    rename("tempid.txt", temp1);	
	
	return 0;
}

int supprimer_livre(const char* nomCategorie)
{
	if (nomCategorie== "0")
    {
    	return 0;
	}
	
	else
	{
		int ligne_total, ligne_supprimer, numeroligne, nl;
		char ligne[MAX_LINE_LENGTH];
		ligne_total =nombre_ligne(nomCategorie);
	
		printf("Quel est l'identifiant du livre que vous voulez supprimer: ");
		scanf("%d",&ligne_supprimer);
		while(ligne_supprimer<0 || ligne_supprimer> ligne_total)
		{
			printf("Veuillez vous assurer de rentrer un identifiant de roman valide pour cette categorie !!!\n");
			printf("Quel est l'identifiant du livre que vous voulez supprimer: ");
			scanf("%d",&ligne_supprimer);
		}
	
		char temp[50];
    	strcpy(temp, nomCategorie);
    	strcat(temp, ".txt");
    	char temp1[50];
    	strcpy(temp1, nomCategorie);
    	strcat(temp1, "_id.txt");
	
		FILE *fichier, *fichiersortie , *fichierid, *fichieridsortie;
	
		fichier = fopen(temp, "r");
    	if (fichier == NULL) {
    	    fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
    	    return 1;
    	}
    
    	fichiersortie = fopen("temp.txt", "w");
    	if (fichier == NULL) {
    	    fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
    	    return 1;
    	}
    
    	fichierid = fopen(temp1, "r");
    	if (fichier == NULL) {
    	    fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
    	    return 1;
    	}
    
    	fichieridsortie = fopen("tempid.txt", "w");
    	if (fichier == NULL) {
    	    fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
    	    return 1;
    	}
    
    	numeroligne=0;
    	while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
    	    numeroligne++;
    	    if (numeroligne != ligne_supprimer) {
    	        fputs(ligne, fichiersortie);
    	    }
    	}
    	
    	nl=0;
    	while (fgets(ligne, sizeof(ligne), fichierid) != NULL) {
    	    nl++;
    	    if (nl != ligne_supprimer) {
    	        fputs(ligne, fichieridsortie);
    	    }
    	}
    
    	fclose(fichier);
    	fclose(fichierid);
    	fclose(fichiersortie);
    	fclose(fichieridsortie);
    
    	remove(temp);
    	remove(temp1);
    	rename("temp.txt", temp);
    	rename("tempid.txt", temp1);
    	mettre_a_jour(nomCategorie);
    	
    	FILE *fichierauteur, *fichiertitre, *fichiersortietitre, *fichiersortieauteur;
    	
    	char temp3[50];
    	strcpy(temp3, nomCategorie);
    	strcat(temp3, "_auteur.txt");
    	fichierauteur = fopen(temp3, "r");
		if (fichierauteur == NULL) 
		{
        	fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
        	return 1;
    	}
    	
    	char temp2[50];
    	strcpy(temp2, nomCategorie);
    	strcat(temp2, "_titre.txt");
    	fichiertitre = fopen(temp2, "r");
		if (fichiertitre == NULL) 
		{
        	fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
        	return 1;
    	}
    	
    	fichiersortieauteur = fopen("temp.txt", "w");
    	if (fichier == NULL) {
    	    fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
    	    return 1;
    	}
    	
    	fichiersortietitre = fopen("tempo.txt", "w");
    	if (fichier == NULL) {
    	    fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
    	    return 1;
    	}
    	int nombre1=0;
    	while (fgets(ligne, sizeof(ligne), fichiertitre) != NULL) {
    	    nombre1++;
    	    if (nombre1 != ligne_supprimer) {
    	        fputs(ligne, fichiersortietitre);
    	    }
    	}
    	
    	int nombre2=0;
    	while (fgets(ligne, sizeof(ligne), fichierauteur) != NULL) {
    	    nombre2++;
    	    if (nombre2 != ligne_supprimer) {
    	        fputs(ligne, fichiersortieauteur);
    	    }
    	}
    	
    	fclose(fichiertitre);
    	fclose(fichierauteur);
    	fclose(fichiersortieauteur);
    	fclose(fichiersortietitre);
    
    	remove(temp2);
    	remove(temp3);
    	rename("temp.txt", temp3);
    	rename("tempo.txt", temp2);
    
    	printf("Le Roman a ete supprimer avec succes \n");
    
    	return 0;
	}
}
 
 int modifier_livre(const char* nomCategorie)
 {
 	if (nomCategorie== "0")
    {
    	return 0;
	}

	else
	{
	
		int ligne_total, ligne_modifier, numeroligne;
		char ligne[MAX_LINE_LENGTH];
		char titre[50];
		char auteur[50];
		ligne_total =nombre_ligne(nomCategorie);
	
		printf("Quel est l'identifiant du livre que vous voulez modifier: ");
		scanf("%d",&ligne_modifier);
		while(ligne_modifier<0 || ligne_modifier> ligne_total)
		{
			printf("Veuillez vous assurer de rentrer un identifiant de roman valide pour cette categorie !!!\n");
			printf("Quel est l'identifiant du livre que vous voulez supprimer: ");
			scanf("%d",&ligne_modifier);
		}
	
		char temp[50];
    	strcpy(temp, nomCategorie);
    	strcat(temp, ".txt");
	
		FILE * fichier, *fichiersortie;
	
		fichier = fopen(temp, "r");
    	if (fichier == NULL) {
    	    fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
    	    return 1;
    	}
    
    	fichiersortie = fopen("temp.txt", "w");
    	if (fichier == NULL) {
    	    fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
    	    return 1;
    	}
    
    	numeroligne=0;
    	while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
    	    numeroligne++;
    	    if (numeroligne != ligne_modifier) {
    	        fputs(ligne, fichiersortie);
    	    }
    	    else
    	    {
    	    	Livre modif;
	
    			modif.ID=ligne_modifier;
    			printf("\t Veuillez entrer le titre du livre :\t");
    			fgets(modif.titre, 500, stdin);
				supprimer_saut_livre(modif.titre, 500);
    			printf("\t Veuillez entrer le nom de l'auteur du livre :\t");
				supprimer_saut_livre(modif.auteur, 500);
    			printf("\t Entrer la date de publication :\t");
				supprimer_saut_livre(modif.date_de_publication, 500);
    			printf("\t Veuillez entrer le genre du livre :\t");
				supprimer_saut_livre(modif.genre, 500);
    			printf("\t Veuillez entrer le prix du livre :\t");
    			scanf("%f", &modif.prix);
    			printf("\t Veuillez entrer le nombre en stock :\t");
    			scanf("%d", &modif.nombre_de_stock);
	
    			fprintf(fichiersortie, "ID: %d\t  Titre: %s\t  Auteur:%s\t Date Publication: %s\t Genre: %s\t Prix: %f FCFA\t Stock: %d ",modif.ID, modif.titre, modif.auteur, modif.date_de_publication, modif.genre, modif.prix, modif.nombre_de_stock);
    			fprintf(fichiersortie, "\n");
    			int i;
    			for (i=0; i< 50; i++)
    			{
    				auteur[i]= modif.auteur[i];
    				titre[i]= modif.titre[i];
				}
    			

			}
    	}
    
    	fclose(fichier);
    	fclose(fichiersortie);
    
    	remove(temp);
    	rename("temp.txt", temp);
    	
    	FILE *fichierauteur, *fichiertitre, *fichiersortietitre, *fichiersortieauteur;
    	
    	char temp3[50];
    	strcpy(temp3, nomCategorie);
    	strcat(temp3, "_auteur.txt");
    	fichierauteur = fopen(temp3, "r");
		if (fichierauteur == NULL) 
		{
        	fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
        	return 1;
    	}
    	
    	char temp2[50];
    	strcpy(temp2, nomCategorie);
    	strcat(temp2, "_titre.txt");
    	fichiertitre = fopen(temp2, "r");
		if (fichiertitre == NULL) 
		{
        	fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
        	return 1;
    	}
    	
    	fichiersortieauteur = fopen("temp.txt", "w");
    	if (fichier == NULL) {
    	    fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
    	    return 1;
    	}
    	
    	fichiersortietitre = fopen("tempo.txt", "w");
    	if (fichier == NULL) {
    	    fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
    	    return 1;
    	}
    	int nombre1=0;
    	while (fgets(ligne, sizeof(ligne), fichiertitre) != NULL) {
    	    nombre1++;
    	    if (nombre1 != ligne_modifier) {
    	        fputs(ligne, fichiersortietitre);
    	    }
    	    else
    	    {
    	    	fprintf(fichiersortietitre, "%s", titre);
				fprintf(fichiersortietitre, "\n");
			}
    	}
    	
    	int nombre2=0;
    	while (fgets(ligne, sizeof(ligne), fichierauteur) != NULL) {
    	    nombre2++;
    	    if (nombre2 != ligne_modifier) {
    	        fputs(ligne, fichiersortieauteur);
    	    }
    	    else
    	    {
    	    	fprintf(fichiersortieauteur, "%s", auteur);
				fprintf(fichiersortieauteur, "\n");
			}
    	}
    	
    	fclose(fichiertitre);
    	fclose(fichierauteur);
    	fclose(fichiersortieauteur);
    	fclose(fichiersortietitre);
    
    	remove(temp2);
    	remove(temp3);
    	rename("temp.txt", temp3);
    	rename("tempo.txt", temp2);
	
    	printf("Le Roman a ete modifier avec succes \n");
    
		return 0;
	}
 }



#endif

