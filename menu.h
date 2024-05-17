#include <stdio.h>
#include <unistd.h>
#ifndef MENU_H
#define MENU_H

void menu_principal(void)
{
    printf("_______________________________________________________________________________________________\n");
    printf("|               BIENVENUE DANS LE SYSTEME DE GESTION DE LA BIBLIOTHEQUE                       |\n");
    printf("_______________________________________________________________________________________________\n");
    printf("|                 Veuillez choisir l'action que vous voulez executer:                         |\n");
    printf("|                                                                                             |\n");
    printf("|                              1- GESTION DES CATEGORIES                                      |\n");
    printf("|                              2- GESTION DES LIVRES                                          |\n");
    printf("|                              3- RECHERCHER DES LIVRES                                       |\n");
    printf("|                              0- QUITER LE PROGRAMME                                         |\n");
    printf("|                                                                                             |\n");
    printf("_______________________________________________________________________________________________\n");

}

void menu_categories(void)
{
    printf("_______________________________________________________________________________________________\n");
    printf("|                                 GESTTION DES CATEGORIOES                                    |\n");
    printf("_______________________________________________________________________________________________\n");
    printf("|                 Veuillez choisir l'action que vous voulez executer:                         |\n");
    printf("|                                                                                             |\n");
    printf("|                              1- AJOUTER UNE CATEGORIE                                       |\n");
    printf("|                              2- SUPPRIMER UNE CATEGORIE                                     |\n");
    printf("|                              3- AFFICHER LES CATEGORIES                                     |\n");
    printf("|                              0- ALLER AU MENU PRINCIPAL                                     |\n");
    printf("|                                                                                             |\n");
    printf("_______________________________________________________________________________________________\n");

}

void gestion_livres (void)
{
    printf("_______________________________________________________________________________________________\n");
    printf("|                                 GESTTION DES LIVRES                                         |\n");
    printf("_______________________________________________________________________________________________\n");
    printf("|                 Veuillez choisir l'action que vous voulez executer:                         |\n");
    printf("|                                                                                             |\n");
    printf("|                              1- AJOUTER UN LIVRE                                            |\n");
    printf("|                              2- SUPPRIMER UN LIVRE                                          |\n");
    printf("|                              3- MODIFIER UN LIVRE                                           |\n");
    printf("|                              4- AFFICHER LES INFORMATIONS DES LIVRES                        |\n");
    printf("|                              0- ALLER AU MENU PRINCIPAL                                     |\n");
    printf("|                                                                                             |\n");
    printf("_______________________________________________________________________________________________\n");

}

void menu_recherche(void)
{
    printf("_______________________________________________________________________________________________\n");
    printf("|                                 RECHERCHE DE LIVRES                                         |\n");
    printf("_______________________________________________________________________________________________\n");
    printf("|                 Veuillez choisir l'action que vous voulez executer:                         |\n");
    printf("|                                                                                             |\n");
    printf("|                              1- RECHERCHER PAR LE TITRE DU LIVRE                            |\n");
    printf("|                              2- RECHERCHER PAR L'AUTEUR DU LIVRE                            |\n");
    printf("|                              3- RECHERCHER PAR LA CATEGORIE DU LIVRE                        |\n");
    printf("|                              0- ALLER AU MENU PRINCIPAL                                     |\n");
    printf("|                                                                                             |\n");
    printf("_______________________________________________________________________________________________\n");

}
#endif
