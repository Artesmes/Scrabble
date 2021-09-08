#include "scrabble.h"

void menu()
{
   int a;
    do
    {
        printf("Bonjour, que voulez-vous faire?\nChoisissez le numero correspondant\n\n1: Commencer une partie\n2: Jouer contre l'ordinateur\n3: Reprendre une partie sauvegardee\n4: Afficher l aide\n5: Afficher le score des joueurs\n6: Credits\n7: Quitter\n");
        scanf("%d",&a);
    }
    while((a<1)||(a>6));

    switch(a)
    {
        case 1: {commencer();
        melangeLaPioche();
        lancer();
        deposePremierMot();
        piocheLettres();
        tour=(1+tour)%nbreJ;
        printf("C'est maintenant au tour de %s de jouer\n",player[tour].pseudo);
        afficheChevalet();

        while(FIN==0)
        {
            deposeMot();
            piocheLettres();
            tour=(1+tour)%nbreJ;
            printf("C'est maintenant au tour de %s de jouer\n",player[tour].pseudo);
            afficheChevalet();
        }
        while((cestLaFin()==0)&&(FIN==1))
        {
            deposeMot();
            tour=(1+tour)%nbreJ;
            printf("C'est maintenant au tour de %s de jouer\n",player[tour].pseudo);
            afficheChevalet();
        }
        leGagnantEst();
        break;}
        case 2:{//jouer contre ordi

        }
        case 3: {reprendre();
        while(FIN==0)
        {
            deposeMot();
            piocheLettres();
            tour=(1+tour)%nbreJ;
            printf("C'est maintenant au tour de %s de jouer\n",player[tour].pseudo);
            afficheChevalet();
        }
        while((cestLaFin()==0)&&(FIN==1))
        {
            deposeMot();
            tour=(1+tour)%nbreJ;
            printf("C'est maintenant au tour de %s de jouer\n",player[tour].pseudo);
            afficheChevalet();
        }
        leGagnantEst();
        break;}
        case 4: {aide();
        menu();
        exit(-1);
        break;}
        case 5: {score();
        menu();
        exit(-1);
        break;}
        case 6: {credits();
        menu();
        exit(-1);
        break;}
        case 7: exit(-1);
    }
}


void commencer()
{
    int *a=0;
    a=&nbreJ;
    char ordinateur[3];

    do
    {   
        printf("Combien de joueurs etes-vous?\n");
        scanf("%d",a);
    }
    while(*a<2 || *a>4);

    /*if(*a==1)
    {   
        printf("Voulez vous ajouter un %dieme joueur qui sera un ordinateur?\n",*a+1);
        scanf("%s",ordinateur);

        if((strcmp(ordinateur,"oui")==0)||(strcmp(ordinateur,"Oui")==0))
        {
            *a=2;
            printf("Vous jouez contre un ordinateur.\n");
        }
    }
    */
    printf("Vous etes %d joueurs\n\n",*a);

    for(int i=0;i<4;i++)
    {
        player[i].existe=0;
    }
    for(int i=0;i<*a;i++)
    {
        t_joueurs *obj;
        obj=&player[i];
        printf("Pseudo du joueur %d : ",i+1);
        scanf("%s",obj->pseudo);
        player[i].existe=1;
    }

    printf("\n");
    for(int i=0;i<*a;i++)
    {
        printf("Le pseudo du joueur n %d est %s.\n\n",i+1,player[i].pseudo);
    }
}

int LettrePoints(char lettre) // retourne le point de la lettre
{  
    if(lettre=='A')
    {
        return 1;
    }
    if(lettre=='B')
    {
        return 3;
    }
    if(lettre=='C')
    {
        return 3;
    }
    if(lettre=='D')
    {
        return 2;
    }
    if(lettre=='E')
    {
        return 1;
    }
    if(lettre=='F')
    {
        return 4;
    }
    if(lettre=='G')
    {
        return 2;
    }
    if(lettre=='H')
    {
        return 4;
    }
    if(lettre=='I')
    {
        return 1;
    }
    if(lettre=='J')
    {
        return 8;
    }
    if(lettre=='K')
    {
        return 10;
    }
    if(lettre=='L')
    {
        return 1;
    }
    if(lettre=='M')
    {
        return 2;
    }
    if(lettre=='N')
    {
        return 1;
    }
    if(lettre=='O')
    {
        return 1;
    }  
    if(lettre=='P')
    {
        return 3;
    }
    if(lettre=='Q')
    {
        return 8;
    }
    if(lettre=='R')
    {
        return 1;
    }
    if(lettre=='S')
    {
        return 1;
    }
    if(lettre=='T')
    {
        return 1;
    }
    if(lettre=='U')
    {
        return 1;
    }
    if(lettre=='V')
    {
        return 4;
    }
    if(lettre=='W')
    {
        return 10;
    }
    if(lettre=='X')
    {
        return 10;
    }
    if(lettre=='Y')
    {
        return 10;
    }
    if(lettre=='Z')
    {
        return 10;
    }
    else
    {
        return 0;
    }
}

void melangeLaPioche()
{   
    int i;
    t_jeton piocheNM[102]; // initialisation de la pioche non mélangée 
    for(i=0;i<9;i++)
    {
        piocheNM[i].lettre='A';
        piocheNM[i].points=1;
    }
    for(i=9;i<11;i++)
    {
        piocheNM[i].lettre='B';
        piocheNM[i].points=3;
    }
    for(i=11;i<13;i++)
    {
        piocheNM[i].lettre='C';
        piocheNM[i].points=3;
    }
    for(i=13;i<16;i++)
    {
        piocheNM[i].lettre='D';
        piocheNM[i].points=2;
    }
    for(i=16;i<31;i++)
    {
        piocheNM[i].lettre='E';
        piocheNM[i].points=1;
    }
    for(i=31;i<33;i++)
    {
        piocheNM[i].lettre='F';
        piocheNM[i].points=4;
    }
    for(i=33;i<35;i++)
    {
        piocheNM[i].lettre='G';
        piocheNM[i].points=2;
    }
    for(i=35;i<37;i++)
    {
        piocheNM[i].lettre='H';
        piocheNM[i].points=4;
    }
    for(i=37;i<45;i++)
    {
        piocheNM[i].lettre='I';
        piocheNM[i].points=1;
    }
    for(i=45;i<46;i++)
    {
        piocheNM[i].lettre='J';
        piocheNM[i].points=8;
    }
    for(i=46;i<47;i++)
    {
        piocheNM[i].lettre='K';
        piocheNM[i].points=10;
    }
    for(i=47;i<52;i++)
    {
        piocheNM[i].lettre='L';
        piocheNM[i].points=1;
    }
    for(i=52;i<55;i++)
    {
        piocheNM[i].lettre='M';
        piocheNM[i].points=2;
    }
    for(i=55;i<61;i++)
    {
        piocheNM[i].lettre='N';
        piocheNM[i].points=1;
    }
    for(i=61;i<67;i++)
    {
        piocheNM[i].lettre='O';
        piocheNM[i].points=1;
    }
    for(i=67;i<69;i++)
    {
        piocheNM[i].lettre='P';
        piocheNM[i].points=3;
    }
    for(i=69;i<70;i++)
    {
        piocheNM[i].lettre='Q';
        piocheNM[i].points=8;
    }
    for(i=70;i<76;i++)
    {
        piocheNM[i].lettre='R';
        piocheNM[i].points=1;
    }
    for(i=76;i<82;i++)
    {
        piocheNM[i].lettre='S';
        piocheNM[i].points=1;
    }
    for(i=82;i<88;i++)
    {
         piocheNM[i].lettre='T';
        piocheNM[i].points=1;
    }
    for(i=88;i<94;i++)
    {
        piocheNM[i].lettre='U';
        piocheNM[i].points=1;
    }
    for(i=94;i<96;i++)
    {
        piocheNM[i].lettre='V';
        piocheNM[i].points=4;
    }
    for(i=96;i<97;i++)
    {
        piocheNM[i].lettre='W';
        piocheNM[i].points=10;
    }
    for(i=97;i<98;i++)
    {
        piocheNM[i].lettre='X';
        piocheNM[i].points=10;
    }
    for(i=98;i<99;i++)
    {
        piocheNM[i].lettre='Y';
        piocheNM[i].points=10;
    }
    for(i=99;i<100;i++)
    {
        piocheNM[i].lettre='Z';
        piocheNM[i].points=10;
    }
    for(i=100;i<102;i++)
    {
        piocheNM[i].lettre='?';
        piocheNM[i].points=0;
    }
    

    int k,p,dernier;
    srand(time(NULL));
    dernier=102;
    for (p=0;p<102;p++)
    {
        k = rand()%dernier;
        pioche[p]=piocheNM[k];
        piocheNM[k]=piocheNM[dernier-1];
        dernier--;
    }
}


void lancer()
{
    for(int i=0;i<nbreJ;i++)
    {
        int k=0;
        printf("%s choisissez vos lettres.\n",player[i].pseudo);
        printf("Les lettres de %s sont : ",player[i].pseudo);
        for(int j=position;j<position+7;j++)
        {
            player[i].jeton[k]=pioche[j];  
            printf("%c",player[i].jeton[k].lettre);
            printf(" ");
            k++;
        }
        printf("\n\n");
        position=position+7;
    }
    srand(time(NULL));
    tour=rand()%nbreJ;
    printf("Tirage aleatoire du joueur qui va commencer la partie:  \n");
    printf("C est %s qui commence\n\n",player[tour].pseudo);
}

char planche[16][16][2] = {
        {"  ","A ","B ","C ","D ","E ","F ","G ","H ","I ","J ","K ","L ","M ","N ","O ",},
        {" 1","* ","  ","  ","& ","  ","  ","  ","* ","  ","  ","  ","& ","  ","  ","* ",},
        {" 2","  ","@ ","  ","  ","  ","$ ","  ","  ","  ","$ ","  ","  ","  ","@ ","  ",},
        {" 3","  ","  ","@ ","  ","  ","  ","& ","  ","& ","  ","  ","  ","@ ","  ","  ",},
        {" 4","& ","  ","  ","@ ","  ","  ","  ","& ","  ","  ","  ","@ ","  ","  ","& ",},
        {" 5","  ","  ","  ","  ","@ ","  ","  ","  ","  ","  ","@ ","  ","  ","  ","  ",},
        {" 6","  ","$ ","  ","  ","  ","$ ","  ","  ","  ","$ ","  ","  ","  ","$ ","  ",},
        {" 7","  ","  ","& ","  ","  ","  ","& ","  ","& ","  ","  ","  ","& ","  ","  ",},
        {" 8","* ","  ","  ","& ","  ","  ","  ","# ","  ","  ","  ","& ","  ","  ","* ",},
        {" 9","  ","  ","& ","  ","  ","  ","& ","  ","& ","  ","  ","  ","& ","  ","  ",},
        {"10","  ","$ ","  ","  ","  ","$ ","  ","  ","  ","$ ","  ","  ","  ","$ ","  ",},
        {"11","  ","  ","  ","  ","@ ","  ","  ","  ","  ","  ","@ ","  ","  ","  ","  ",},
        {"12","& ","  ","  ","@ ","  ","  ","  ","& ","  ","  ","  ","@ ","  ","  ","& ",},
        {"13","  ","  ","@ ","  ","  ","  ","& ","  ","& ","  ","  ","  ","@ ","  ","  ",},
        {"14","  ","@ ","  ","  ","  ","$ ","  ","  ","  ","$ ","  ","  ","  ","@ ","  ",},
        {"15","* ","  ","  ","& ","  ","  ","  ","* ","  ","  ","  ","& ","  ","  ","* ",},
};

void affichePlanche()
{
    int i,j,k;
    for(i=0;i<16;i++)
    {
        for(int i=0; i<16;i++)
        {
            printf("+----");
        }
        puts("+");
        for(j=0;j<16;j++)
        {
            printf("| %c%c ",planche[i][j][0],planche[i][j][1]);
        }
        puts("|");
    }
    for(int i=0; i<16;i++)
    {
        printf("+----");
    }
    puts("+");
}



int verifieMot(char mot[20]) // verifie si le joueur peut jouer ce mot
{   
    
    int L = strlen(mot);
    int i=0;
    t_joueurs piocheStock;
    piocheStock=player[tour];
    for(int k=0;k<L;k++)
    {
        i=0;
        while(i<7)
        {
            if(mot[k]==player[tour].jeton[i].lettre)
            {
                player[tour].jeton[i].lettre =' ';
                break;
            }
            i++;
            
            if(i==7)
            {
                player[tour]=piocheStock;
                printf("Vous ne possedez pas ce mot dans votre chevalet.\n\n");
                return 1;
            }
        }   
    }
    return 0;
}

int verifieMot2(char mot[20],int pause)// retourne 0: tt est bon, retourne 1: possède pas le mot dans le chevalet
{ 
    char mot1[20];
    char mot2[20];
    
    for(int i=0;i<pause;i++)
    {
        mot1[i]=mot[i];
    }
    mot1[pause]='\0';

    int p=0;
    for(int i=pause+1;i<strlen(mot);i++)
    {
        mot2[p]=mot[i];
        p++;
    }
    mot2[p]='\0';
    strcat(mot1,mot2);
    return verifieMot(mot1);
}

void piocheLettres()
{
    char car;
    printf("%s piochez vos lettres.\n",player[tour].pseudo);
    for(int k=0;k<7;k++)
    {
        if(position==20)
        {
            printf("Il n'y a plus de jetons dans la pioche\n");
            FIN=1;

            printf("Voici votre nouvelle pioche :\n");
            for(int k=0;k<7;k++)
            {
                printf("%c ",player[tour].jeton[k].lettre);
            }
            printf("\n \n");
            return;
        }
    
        while(player[tour].jeton[k].lettre==' ')
        {
            player[tour].jeton[k]=pioche[position];
            position++;
        }
    }
    printf("Voici votre nouvelle pioche :\n");
    for(int k=0;k<7;k++)
    {
        printf("%c ",player[tour].jeton[k].lettre);
    }
    printf("\n \n");
}

void changeLettres()
{
    t_joueurs piocheStock;
    piocheStock=player[tour];
    char lettres[20];
    printf("Quelles lettres souhaitez vous changer?\n");
    scanf("%s",lettres);
    for(int i=0;i<strlen(lettres);i++)
    {
        for(int k=0;k<7;k++)
        {
            if(lettres[i]==player[tour].jeton[k].lettre)
            {
                player[tour].jeton[k].lettre=' ';
                break;
            }
            if(k==6)
            {
                printf("Vous ne pouvez pas changer ces lettres. Recommencez\n");
                player[tour]=piocheStock;
                changeLettres();
                return;
            }
        }
    }
}

void deposePremierMot()
{
    int score=0;
    char vh;
    int numL;  
    char pMot[7];
    char approuve[5];
    
    t_joueurs piocheStock;
    piocheStock=player[tour];
    do
    {
        do
        {
            printf("\nRetour au Menu: 0 \nChanger les lettres: 1\nPasser: 2\n\n");
            printf("Quel mot voulez vous poser %s?\n",player[tour].pseudo);
            fflush(stdin);
            scanf("%s",pMot);
            if(strcmp(pMot,"0")==0)
            {
                sauvegarde();
                menu();
                exit(-1);
            }
            if(strcmp(pMot,"1")==0)
            {
                changeLettres();
                piocheLettres();
                tour=(1+tour)%nbreJ;
                deposePremierMot();
                return;
            }
            if(strcmp(pMot,"2")==0)
            {
                tour=(1+tour)%nbreJ;
                deposePremierMot();
                return;
            }
            for(int i=0;i<strlen(pMot);i++)
            {
                if(96<pMot[i]&&pMot[i]<123)
                {
                    pMot[i]=pMot[i]-32;
                }
                if(pMot[i]=='?')
                {
                    char change;
                    printf("Quelle lettre souhaitez vous mettre pour le <?> ?\n");
                    fflush(stdin);
                    scanf("%c",&change);
                    pMot[i]=change;
                    for(int z=0;z<7;z++)
                    {
                        if(player[tour].jeton[z].lettre=='?')
                        {
                            player[tour].jeton[z].lettre=change;
                            break;
                        }
                    }
                }
            }
    
        } 
        while(verifieMot(pMot));

        do
        {
            printf("Les autres joueurs, approuvez vous ce mot? \nOui ou non?\n");
            fflush(stdin);
            scanf("%s",approuve);
        }
        while(strcmp(approuve,"non")!=0 && strcmp(approuve,"Non")!=0 && strcmp(approuve,"oui")!=0 && strcmp(approuve,"Oui")!=0);
        
        if (strcmp(approuve,"non")==0 || strcmp(approuve,"Non")==0)
        {
            puts("Les autres joueurs n'ont pas approuve votre mot. Recherchons dans le dictionnaire l'existance du mot.\n");

            if(verifieDico(pMot,strlen(pMot))==1)
            {
                printf("Le mot existe, le contestataire perd 10 points\n");
                player[(1+tour)%nbreJ].points-=10;
                break;
            }
            else
            {
                printf("Ce mot n'existe pas, votre tour saute.\n");
                player[tour]=piocheStock;
                return;
            }
            
        }
    } 
    while(strcmp(approuve,"non")==0 || strcmp(approuve,"Non")==0);

    do
    {
        printf("Voulez vous le deposer horizontalement (h) ou verticalement (v) ?\n");
        fflush(stdin);
        scanf("%c",&vh);
    } 
    while(vh!='h' && vh!='v');

    do
    {
        printf("Quel est le numero de la lettre allant au centre en partant du debut du mot ?\n");
        fflush(stdin);
        scanf("%d",&numL);
    }
    while(numL>strlen(pMot));
    
    numL--;

    int longueur=strlen(pMot);
    if (vh=='h')
    {
        int i;
        int k=8;
        int j=0;
        for(i=numL;i<longueur;i++)
        {
            planche[8][k][1]=pMot[i];
            k++;
            j++;
        }
        int debut = 8-(longueur-j); 
        for(i=0;i<(longueur-j);i++)
        {
            planche[8][debut][1]=pMot[i];
            debut++;
        }   

        int n=0;
        for(int k=debut;k<(debut+longueur);k++)// calcul le score
        {   
            if(planche[8][k][0]=='&')
            {
                score+= LettrePoints(pMot[n])*2;
            }
            else
            {
            score+=LettrePoints(pMot[n]);
            }
            n++;
            printf("%d\n",score);
        }
    }


    else if (vh=='v')
    {
        int i;
        int k=8;
        int j=0;
        for(i=numL;i<longueur;i++)
        {
            planche[k][8][1]=pMot[i];
            k++;
            j++;
        }
        int debut = 8-(longueur-j); 
        for(i=0;i<(longueur-j);i++)
        {
            planche[debut][8][1]=pMot[i];
            debut++;
        }
        int n=0;
        for(int k=debut;k<(debut+longueur);k++)// calcul le score
        {   
            if(planche[k][8][0]=='&')
            {
                score+= LettrePoints(pMot[n])*2;
            }
            else
            {
                score+=LettrePoints(pMot[n]);
            }
            n++;
        }
    }

    player[tour].points+=score;
    affichePlanche();
    printf("\n");
    
}

void deposeMot(){
    int score=0;
    char vh;
    char lettreL;
    int ligne;  
    char mot[20];
    int colonne;
    int erreur=0;
    char approuve[20];
    t_joueurs piocheStock;
    piocheStock=player[tour];

    do{
        printf("\nRetour au Menu: 0 \nChanger les lettres: 1\nPasser: 2\n");
        if(FIN==1){
            printf("Finir la partie (Les joueurs sont d'accord pour finir cette partie): 3\n");
        }
        printf("\n");
        printf("Quel mot voulez vous poser %s ?\n",player[tour].pseudo);
        fflush(stdin);
        scanf("%s",mot);

        if(strcmp(mot,"0")==0)
        {
            sauvegarde();
            menu();
            exit(-1);
        }
        if(strcmp(mot,"1")==0){
            changeLettres();
            piocheLettres();
            tour=(1+tour)%nbreJ;
            deposeMot();
            return;
        }
        if(strcmp(mot,"2")==0){
            tour=(1+tour)%nbreJ;
            deposeMot();
            return;
        }
        if(strcmp(mot,"3")==0){
            FIN=2;
            return;
        }


        printf("Les autres joueurs, approuvez vous ce mot? oui ou non \n");
        fflush(stdin);
        scanf("%s",approuve);
        if(strcmp(approuve,"non")==0){
            puts("Les autres joueurs n'ont pas approuve votre mot. Recherchons dans le dictionnaire l'existance du mot.\n");

            if(verifieDico(mot,strlen(mot))==1){
                printf("Le mot existe, le contestataire perd 10 points\n");
                player[(1+tour)%nbreJ].points-=10;
                break;
            }
            else{
                printf("Ce mot n'existe pas, votre tour saute.\n");
                player[tour]=piocheStock;
                return;
            }
        }
        
    } while(strcmp(approuve,"non")==0);

    for(int i=0;i<strlen(mot);i++)
    {
        if(96<mot[i]&&mot[i]<123)
        {
            mot[i]=mot[i]-32;
        }

        if(mot[i]=='?')
        {
            char change;
            printf("Quelle lettre souhaitez vous mettre pour le <?> ?\n");
            fflush(stdin);
            scanf("%c",&change);
            mot[i]=change;
            for(int z=0;z<7;z++){
                if(player[tour].jeton[z].lettre=='?'){
                    player[tour].jeton[z].lettre=change;
                    break;
                }
            }
        }
    }

    do
    {
        printf("Voulez vous le deposer horizontalement (h) ou verticalement (v)?\n");
        fflush(stdin);
        scanf("%c",&vh);
    } while(vh!='h' && vh!='v');
    
    printf("Ou voulez vous placer la premiere lettre du mot?\nNumero Colonne (Lettre):\n");
    fflush(stdin);
    scanf("%c",&lettreL);
    colonne = (int)lettreL-64;
    printf("Numero Ligne:\n");
    fflush(stdin);
    scanf("%d",&ligne);
    int longueur=strlen(mot);
    
    int multiplicateur=1;



    if(vh=='h')
    {
        
        int p=0;
        int pause=-1;
        int compteur=0; 
        if(planche[ligne][colonne-1][1]!= ' '){
            printf("vous ne pouvez poser ce mot, il est collé à un autre.\n");
            erreur=5;
        }
        if(planche[ligne][colonne+longueur+1][1]!= ' '){
            printf("vous ne pouvez poser ce mot, il est collé à un autre.\n");
            erreur=5;
        }

        int pause2;
        for(int i=colonne;i<colonne+longueur;i++)
        {

            if(planche[ligne][i][1] == mot[p])
            {
                pause2 = i;
                pause = p;
            }

            if((planche[ligne+1][i][1]!= ' ')&&(i != pause2)){
                printf("vous ne pouvez poser ce mot, il est collé à un autre.\n");
                erreur=5;
                break;
            }
            if((planche[ligne-1][i][1]!= ' ')&&(i != pause2)){
                printf("vous ne pouvez poser ce mot, il est collé à un autre.\n");
                erreur=5;
                break;
            }

            if((planche[ligne][i][1] != mot[p])&&(planche[ligne][i][1] != ' '))
            {
                printf("Vous ne pouvez poser ce mot sur la planche (incompatibilite des mots sur la planche)\n");
                erreur=1;
            }
            p++;
        }
        if(pause==-1){
            printf("vous ne pouvez poser ce mot sur la planche (il n'est relie a aucun mot)\n");;
            erreur=2;
        }

        if ((verifieMot2(mot,pause)==1)){
            erreur=3;
        }

        if ((colonne+longueur)>16){
            printf("Vous êtes sorti des limitations de la planche, recommencez\n");
            erreur=4;
        }

        if(erreur==0)
            {
            int k=0;
            for(int i=colonne;i<colonne+longueur;i++)
            {
                planche[ligne][i][1]=mot[k];
                if(planche[ligne][i][0]=='&')
                {
                    score+= LettrePoints(mot[k])*2;
                }
                else if(planche[ligne][i][0]=='$')
                {
                    score+= LettrePoints(mot[k])*3;
                }
                else if(planche[ligne][i][0]=='@')
                {
                    score+=LettrePoints(mot[k]);
                    multiplicateur*=2 ;
                }
                else if(planche[ligne][i][0]=='*')
                {
                    score+=LettrePoints(mot[k]);
                    multiplicateur*=3;
                }
                else
                {
                    score+=LettrePoints(mot[k]);
                }
                k++;
            }
        } 
    }

    if(vh=='v')
    {
        
        int compteur=0;
        int p=0;
        int pause=-1;

        if(planche[ligne][colonne-1][1]!= ' '){
            printf("vous ne pouvez poser ce mot, il est collé à un autre.\n");
            erreur=5;
        }

        if(planche[ligne][colonne+longueur+1][1]!= ' '){
            printf("vous ne pouvez poser ce mot, il est collé à un autre.\n");
            erreur=5;
        }

        int pause2;
        for(int i=ligne;i<(ligne+longueur);i++)
        {
            if(planche[i][colonne][1] == mot[p])
            {
                pause=p;
                pause2 = i;  
            }

            if((planche[i][colonne+1][1]!= ' ')&&(i != pause2)){
                printf("vous ne pouvez poser ce mot, il est collé à un autre.\n");
                erreur=5;
                break;
            }
            if((planche[i][colonne-1][1]!= ' ')&&(i != pause2)){
                printf("vous ne pouvez poser ce mot, il est collé à un autre.\n");
                erreur=5;
                break;
            }


            if((planche[i][colonne][1] != mot[p])&&(planche[i][colonne][1] != ' '))
            {
                printf("Vous ne pouvez poser ce mot sur la planche (incompatibilite des mots sur la planche)\n");
                erreur=1;
            }
            p++;
        }
        if(pause==-1){
            printf("vous ne pouvez poser ce mot sur la planche (il n'est relie a aucun mot)");;
            erreur=2;
        }
        
        if ((verifieMot2(mot,pause)==1)){
            erreur=3;
        }

        if ((ligne+longueur)>16){
            printf("Vous êtes sorti des limitations de la planche, recommencez\n");
            erreur=4;
        }

        if(erreur==0)
        {
            int k=0;
            for(int i=ligne;i<ligne+longueur;i++)
            {
                planche[i][colonne][1]=mot[k];

                if(planche[i][colonne][0]=='&')
                {
                    score+= LettrePoints(mot[k])*2;
                }
                else if(planche[i][colonne][0]=='$')
                {
                    score+= LettrePoints(mot[k])*3;
                }
                else if(planche[i][colonne][0]=='@')
                {
                    score+=LettrePoints(mot[k]);
                    multiplicateur*=2 ;
                }
                else if(planche[i][colonne][0]=='*')
                {
                    score+=LettrePoints(mot[k]);
                    multiplicateur*=3;
                }
                else
                {
                    score+=LettrePoints(mot[k]);
                }
                k++;
            }
        } 
    }
    if(erreur==0){
        score= multiplicateur*score;
        player[tour].points+=score;
        affichePlanche(); 
    }
    else{
        player[tour]=piocheStock;
        printf("veuillez recommencer\n");
        deposeMot();
    }
}


void afficheChevalet()
{
    printf("\n\n");
    for(int k=0;k<nbreJ;k++)
    {
        printf("Chevalet de %s :\n",player[k].pseudo);

        for (int i=0;i<7;i++)
        {
            printf("%c ",player[k].jeton[i].lettre);
        }
        printf("\n");
        printf("Score: %d", player[k].points);
        printf("\n\n");
    }
}

int verifieDico(char unmot[20], int L)
{
    for(int i=0;i<L;i++)
    {
        unmot[i]+=32;
    }
    char val;
    char val1[2];
    char mot2[50];
    FILE *fic;
    fic =fopen("dico.txt","r");
    if(fic ==NULL)
    {
        printf("Erreur de lecture de fichier");
    }
    else
    {
        while(!feof(fic))
        {
            fscanf(fic,"%c",&val);
            val1[0]=val;
            if(val=='\n')
            {
                if(strcmp(mot2,unmot)==0)
                {
                    fclose(fic);
                    for(int i=0;i<L;i++)
                    {
                        unmot[i]-=32;
                    }
                    return 1;
                }
                mot2[0]='\0';
            }
            else
            {
                strcat(mot2,val1);
            }
        }
        fclose(fic);
        for(int i=0;i<L;i++)
        {
            unmot[i]+=32;
        }
    }
    return 0;
}


void sauvegarde()
{
    FILE *fic=NULL;
    char score;
    fic=fopen("Sauvegarde.txt","w");
    if (fic==NULL)
        {
            printf("Erreur d'ouverture de fichier\n");
        }
    else
    {
        fprintf(fic,"%d ",nbreJ);

        for(int i=0;i<nbreJ;i++)
        {
            fprintf(fic,"%s ",player[i].pseudo);
            fprintf(fic,"%d ",player[i].points);

            for(int j=0;j<7;j++)
            {
                fprintf(fic,"%c ",player[i].jeton[j].lettre);
            }
        }

    for(int i=0;i<16;i++)
    {   
        for(int j=0;j<16;j++)
        {
            fprintf(fic,"%c ",planche[i][j][0]);
            fprintf(fic,"%c ",planche[i][j][1]);
        }
    }
    fprintf(fic,"%d ",position);
    for(int i=0;i<102;i++)
    {
        fprintf(fic,"%c ",pioche[i].lettre);
    }
    fprintf(fic,"%d",tour);
    fclose(fic);
    }
}



void reprendre()
{
    FILE *npt=NULL;
    int Points;
    char Lettre,a,b,Pioche;
    npt=fopen("Sauvegarde.txt","r");
    if(npt==NULL)
    {
        printf("Erreur d ouverture de fichier\n");
    }
    else
    {
        while(!feof(npt))
        {
            fscanf(npt,"%d",&nbreJ);
            printf("%d\n",nbreJ);
            fgetc(npt);
            for(int i=0;i<nbreJ;i++)
            {
                fscanf(npt,"%s",player[i].pseudo);
                fgetc(npt);
                printf("Le pseudo du joueur %d est %s\n",i+1,player[i].pseudo);
                fscanf(npt,"%d",&Points);
                player[i].points=Points;
                fgetc(npt);
                printf("il a %d points\n",player[i].points);
                printf("Voici son chevalet : ");
                for(int j=0;j<7;j++)
                {
                    fscanf(npt,"%c",&Lettre);
                    player[i].jeton[j].lettre=Lettre;
                    fgetc(npt);
                    printf("%c",player[i].jeton[j].lettre);
                }
                printf("\n");
            }
            for(int i=0;i<16;i++)
            {
                for(int j=0;j<16;j++)
                {
                    fscanf(npt,"%c",&a);
                    planche[i][j][0]=a;
                    fgetc(npt);
                    fscanf(npt,"%c",&b);
                    planche[i][j][1]=b;
                    fgetc(npt);
                }
            }
            affichePlanche();
            fscanf(npt,"%d",&position);
            printf("La position dans la pioche est %d\n",position);
            fgetc(npt);
            printf("La pioche est :");
            for(int i=0;i<102;i++)
            {
                fscanf(npt,"%c",&Pioche);
                pioche[i].lettre=Pioche;
                fgetc(npt);
                printf("%c",pioche[i].lettre);
            }
            printf("\n");
            fscanf(npt,"%d",&tour);
            printf("C est au tour de %s de jouer\n",player[tour].pseudo);
        }
        fclose(npt);
    }
}



void aide()
{
    char val;
    FILE *fic=NULL;
    fic=fopen("Aide.txt","r");
    if(fic==NULL)
    {
        printf("Erreur d ouverture de fichier\n");
    }
    else
    {
        while(!feof(fic))
        {
            fscanf(fic,"%c",&val);
            printf("%c",val);
        }
        printf("\n");
        fclose(fic);
    }
}

int cestLaFin()
{
    int cpt=0;
    for(int i=0;i<7;i++)
    {
        if (player[tour].jeton[i].lettre==' ')
        {
            cpt++;
        }
    }
    if(cpt==7)
    {
        printf("C'est la fin de la partie ! GG à tous \n");
        return 1;
    }
    else
    {
        return 0;
    }
}

void leGagnantEst()
{
    printf("Voici le classement final:\n");
    int classement[nbreJ];
    for(int i=0;i<nbreJ;i++)
    {
        classement[i]=i;
    }

    for(int k=0;k<nbreJ;k++)
    {
        for(int j=0;j<nbreJ-1;j++)
        {
            if(player[j].points>player[j+1].points)
            {
                int change;
                change=classement[j];
                classement[j]=classement[j+1];
                classement[j+1]=change;
            }
        }
    }
    for(int i=0;i<nbreJ;i++)
    {
        printf("%d  %s  avec %d points\n",i+1,player[i].pseudo,player[i].points);
    }
}

void score()
{
    int i;
    for(i=0;i<nbreJ;i++)
    {
        printf("Le score de %s est %d",player[i].pseudo,player[i].points);
    }
}

void credits()
{
    printf("Tous droits reserves a Waligora Paul et Lucas Lea.\n\n");
}


int main()
{
    menu();
    return 0;
}