#include <stdio.h>
#include <unistd.h>
#include "menu.h"
#include "choix_menu.h"



int main (void)
{
	int chx;
	int ch;
	
	do
	{
	
		menu_principal();
		chx=choix_menu();
		clean();
		redirection_vers_choix_menu (chx);
	
	
		if (chx==1)
		{
			ch= choix_menu();
			clean();
			redirection_vers_la_gestion_des_categories(ch);
				
		}
		else if(chx==2)
		{
			ch=choix_menu_livre();
			clean();
			redirection_vers_la_gestion_des_livres(ch);
			
		}
		else if(chx==3)
		{
			ch=choix_menu();
			clean();
			redirection_vers_la_recherche_des_livres(ch);

		}
		else
		{
			goto end;
		}
	}
	while (chx!=0);
	
	end:
	return 0;
}
