#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int choix , i , j , found=0 ;
    char titre[50][20];
    char auteur[50][20];
    float prix[50];
    int quantite[50] ;
    int livre_num = 0 ;
    char recherche[20];
    int total_qua = 0;
    printf("Gestion du stock de livres dans Youcode Librairie \n\n");
    do {
        printf("******************* Menu *********************");
        printf("\nSysteme de Gestion de Stock de Librairie\n");
        printf("1. Ajouter un Livre\n");
        printf("2. Afficher Tous les Livres\n");
        printf("3. Rechercher un Livre\n");
        printf("4. Mettre a Jour la Quantite d'un Livre\n");
        printf("5. Supprimer un Livre\n");
        printf("6. Afficher le Nombre Total de Livres\n");
        printf("7. Quitter\n");
        printf("**********************************************\n\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

    if (choix==1){
       printf("Entrez le titre du livre : ");
       scanf(" %[^\n]", titre[livre_num]);
       printf("Entrez l'auteur du livre : ");
       scanf(" %[^\n]", auteur[livre_num]);
       printf("Entrez le prix du livre : ");
       scanf("%f", &prix[livre_num]);
       printf("Entrez la quantite : ");
       scanf("%d", &quantite[livre_num]);
       livre_num ++;
       printf("Livre ajoute avec succes\n");
    }
    else if (choix==2){
        if (livre_num == 0)
          printf("Aucun livre en stock.\n");

        else{
            for(i=0 ; i<livre_num ; i++){
                printf("Titre : %s \t Auteur : %s \t Prix : %.2f Dh \t Quantite : %d  \n", titre[i], auteur[i], prix[i], quantite[i]);
            }
        }
    }

    else if (choix == 3){
      printf("Entrez le titre du livre a rechercher : ");
      scanf(" %[^\n]", recherche);
      for(i=0;i<livre_num ; i++){
        if(strcmp(titre[i],recherche) == 0){
            printf("Livre trouve :\n");
            printf("Titre : %s \t Auteur : %s \t Prix : %.2f Dh \t Quantite : %d  \n", titre[i], auteur[i], prix[i], quantite[i]);
            found = 1 ;
            break ;
        }
      }
      if(found!=1){
        printf("Livre non trouve.\n");
      }

    }

    else if (choix==4){
        printf("Entrez le titre du livre a mettre a jour : ");
        scanf(" %[^\n]", recherche);
        for(i=0; i<livre_num ; i++){
            if(strcmp(titre[i],recherche)==0){
                printf("Entrez la nouvelle quantite : ");
                scanf("%d", &quantite[i]);
                printf("Quantite mise a jour avec succes.\n");
                found = 1 ;
            }
        }
        if(found!=1){
         printf("Livre non trouve.\n");
        }

    }

    if(choix == 5){
        printf("Entrez le titre du livre a supprimer : ");
        scanf(" %s[^\n]", recherche);
        for(i=0 ; i<livre_num ; i++){
             if(strcmp(titre[i],recherche) == 0) {
                for(j=i;j<livre_num;j++){
                    strcpy(titre[j],titre[j+1]);
                    strcpy (auteur[j], auteur[j+1]);
                    prix[j] = prix[j + 1];
                    quantite[j] = quantite[j+1];
                    found = 1 ;
                }
                livre_num -- ;
                printf("Livre supprime avec succes.\n");
                found = 1;
                break;
             }

        }
        if (found !=1 ) {
        printf("Livre non trouve.\n");
    }
    }


    else if(choix == 6 ){
        for(i=0 ; i<livre_num ; i++){
                total_qua = total_qua + quantite[i] ;
        }
        printf("Nombre total de livres en stock : %d\n", total_qua );
    }


    } while (choix != 7);
    printf("Systeme est Terminer.");
    return 0;
}
