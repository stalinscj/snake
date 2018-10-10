# include <stdio.h>
# include <cstdlib>
# include <time.h>
# include <windows.h>
# include <conio.h>
# include <stdlib.h>


int nivel,cx,cy,largo =3;
bool choco=false;
char op='2',nom[21],opj='2';

void gotoxy(int x, int y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void borrarultimo (int matriz[2][1368])
{
	gotoxy(matriz[0][0],matriz[1][0]);
	printf(" ");
	int i=0;
	for(int j=0;j<largo-1;j++)
	{
		matriz[i][j]=matriz[i][j+1];
		matriz[i+1][j]=matriz[i+1][j+1];
	}
}

void comida (int matriz[2][1368])
{
	int i =0;
	bool posco=false;
	srand(time(NULL));
	
	  do
	  {
	  cx=(rand()%76)+2;
	  cy=(rand()%18)+5;
	  for (int j=0; j<largo; j++)
	  {
			if((matriz[i][j]==cx) && (matriz[i+1][j]==cy))
			{
				posco=true;
			}
			else
			{
				posco=false;
			}
	  }
	  }while(posco);
	  gotoxy(cx,cy);
	  printf("*");	
}

void crecer (int cabx, int caby, int matriz[2][1368]) 
{
	  
			if((cabx==cx) && (caby==cy))
			{
				largo=largo+1;
				comida(matriz);
				gotoxy(67,3);
				printf("Puntos: %d",largo);
			}
}

void fondo (int raya[2][191])
{
	int j,i=0;
	
	system("cls");
	gotoxy(27,0);
	printf("JUEGO DE LA SERPIENTE O SNAKE");
	gotoxy(1,3);
	printf("Jugador: %s",nom);
	switch (op)
	{
		case '1': gotoxy(31,3);
				  printf("Dificultad: INFORMAL");
				  break;
		case '2': gotoxy(31,3);
				  printf("DIFICULTAD: HEROE");
				  break;
		case '3': gotoxy(31,3);
				  printf("Dificultad: LEGENDA");
				  break;
		
	}
	gotoxy(67,3);
	printf("Puntos: %d",largo);
		
	raya[i][0]=1;
	raya[i+1][0]=4;
	gotoxy(1,4);
	printf("%c",201);
	raya[i][1]=78;
	raya[i+1][1]=4;
	gotoxy(78,4);
	printf("%c",187);
	raya[i][2]=1;
	raya[i+1][2]=23;
	gotoxy(1,23);
	printf("%c",200);
	raya[i][3]=78;
	raya[i+1][3]=23;
	gotoxy(78,23);
	printf("%c",188);
	for (j=2;j<78;j++)
	{
		raya[i][j+2]=j;
	    raya[i+1][j+2]=4;
		gotoxy(j,4);
		printf("%c",205);
		raya[i][j+78]=j;
	    raya[i+1][j+78]=23;
		gotoxy(j,23);
		printf("%c",205);
	}
	for (j=5;j<23;j++)
	{
		raya[i][j+151]=1;
	    raya[i+1][j+151]=j;
		gotoxy(1,j);
		printf("%c",186);
		raya[i][j+169]=78;
	    raya[i+1][j+169]=j;
		gotoxy(78,j);
		printf("%c",186);
	}
	
}

void choque (int cabx, int caby, int raya[2][191],int matriz[2][1368])
{
	int j,i=0;
	for (j=0;j<192;j++)
	{
		if ((cabx==raya[i][j]) && (caby==raya[i+1][j]))
		{	
			choco= true;
			Sleep (500);
		}
	}
	for (j=0;j<largo-1;j++)
	{
		if ((cabx==matriz[i][j]) && (caby==matriz[i+1][j]))
		{
			choco= true;
			Sleep (500);
		}
	}
}

void finjuego(int raya[2][191])
{
	fondo(raya);
	gotoxy(28,12);
	printf("puntos obtenidos: %d",largo);
	gotoxy(5,16);
	printf("Pulse 1 para volver al menu principal.");
	gotoxy(5,18);
	printf("Pulse una letra u otro numero para volver a jugar: ");
	getchar ();
	opj=getchar();
}

void menu ()
{
	system("cls");
	gotoxy(22,0);
	printf("BIENVENIDOS AL JUEGO DE LA SERPIENTE");
	gotoxy(1,2);
	printf("1. JUGAR");
	gotoxy(1,4);
	printf("2. INSTRUCCIONES");
	gotoxy(1,6);
	printf("3. SALIR");
	gotoxy(1,8);
	printf("Escoja una opcion: ");
	op=getch();
	system("cls");
}

void dificultad()
{
	system("cls");
	gotoxy(30,0);
	printf("DIFICULTAD");
	gotoxy(1,2);
	printf("1. INFORMAL");
	gotoxy(1,4);
	printf("2. HEROE");
	gotoxy(1,6);
	printf("3. LEYENDA");
	gotoxy(1,8);
	printf("Escoja una opcion: ");
	op=getch();
	system("cls");
	switch (op)
	{
		case '1': nivel=100;
				  break;
		case '2': nivel=50;
				  break;
		case '3': nivel=20;
				  break;
		
	}
	
}

void instrucciones ()
{
	system("cls");
	gotoxy(33,0);
	printf("INSTRUCCIONES");
	gotoxy(1,4);
	printf("Para mover a la serpiente puedes usar las teclas A W D S y el objetivo del");
	gotoxy(1,6);
	printf("juego es comer la mayor cantidad de * sin chocar.");
	gotoxy(1,10); 
	system("pause");	
}

void jugador ()
{
	int longitud,k;
	
	k=0;
	do
	{
		if(k>0) getchar ();
		longitud=0;
		gotoxy(35,0);
		printf("JUGADOR");
		gotoxy(0,4);
		printf("Escribe tu nombre y pulsa ENTER");
		gotoxy(0,6);
		fflush(stdin);
		scanf("%[^\n]s",&nom);
		printf("\n");
		k=1;
		while (nom[k-1]!='\0')
		{
			if(nom[k-1]!='\0')
			{
				longitud=longitud+1;
			}
			k=k+1;
		}
		if(longitud>20)
		{
			printf("El nombre no puede tener mas de 20 letras, incluyendo los espacios\n\n");
			system ("pause");	
		}
		system("cls");
	}while(longitud>20);	
}

int main ()
{
	int cabx,caby,i,j,x,y,matriz[2][1368],raya[2][191];
	char tecla,aux;
	
	system("COLOR a");
	do
	{
		ShowCursor(FALSE);
		do
		{
			menu();
			    
			if (op=='2') instrucciones();
			if (op=='3') break;
					
		}while(op=='2');
		
		if(op=='1')
		{
			dificultad ();
			jugador ();
			do
			{
				largo =3; choco=false; 
				x=15; y=8; i=0;
				//if (opj=='1') jugador ();	
				fondo(raya);
				comida(matriz);
				for(j=0;j<largo;j++)
				{
					matriz[i][j]=x++;
					matriz[i+1][j]=y;
				}
				cabx = matriz[i][largo-1];
				caby = matriz[i+1][largo-1];
				
				aux='d';
				do
				{   
					for (j=0;j<largo;j++)
					{
							gotoxy(matriz[i][j],matriz[i+1][j]);
							printf("*");
					}	
					Sleep (nivel);
					borrarultimo(matriz);
						
					if (kbhit()==1)
					{
						tecla = getch();
						if (tecla==75) tecla='a';
						if (tecla==72) tecla='w';
						if (tecla==77) tecla='d';
						if (tecla==80) tecla='s';
						
						if(tecla=='a' && aux!='d') 
						{
							aux=tecla;
						}
						if(tecla=='d' && aux!='a')
						{ 
							if(aux=='s' || aux=='w') x=x+1;
							aux=tecla;
						}
						if(tecla=='s' && aux!='w')
						{ 
							if(aux=='d') x=x-1;
							aux=tecla;
						}
						if(tecla=='w' && aux!='s')
						{ 
							if(aux=='d') x=x-1;
							aux=tecla;
						}
					}
						crecer(cabx,caby,matriz);
						if (aux=='a') {matriz[i][largo-1]=--x; matriz[i+1][largo-1]=y;}
						if (aux=='s') {matriz[i][largo-1]=x;   matriz[i+1][largo-1]=++y;}
						if (aux=='d') {matriz[i][largo-1]=x++; matriz[i+1][largo-1]=y;}
						if (aux=='w') {matriz[i][largo-1]=x;   matriz[i+1][largo-1]=--y;}
						cabx = matriz[i][largo-1];
						caby = matriz[i+1][largo-1];
						gotoxy(cx,cy);
	  					printf("*");
						choque (cabx,caby,raya,matriz);
						if (choco) 
						{
							system("cls");
							finjuego(raya);
						}
							
				}while(!choco);
			}while(opj!='1');
		}
	}while(op!='3');
	gotoxy(22,8);
	char cad[35]={'!','!','!','H','-','E','-','C','-','H','-','O','-','-','P','O','R','-','-','S','-','T','-','A','-','L','-','I','-','N','!','!','!'}; 
	for (int p=0;p<34;p++)
	{
		printf("%c",cad[p]);
		Sleep(200);
	}
	Sleep(1500);
	return 0;
}
