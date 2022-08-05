#include <iostream>
#include <locale.h>
#include <cstring>

using namespace std;

char alfabeto[30] = "abcdefghijklmnopqrstuvwxyz";

void substituicao(){
	char* palavra = new char;
	int i=0, j=0;
	
	cout<<"\n\nDigite a palavra que deseja criptografar, desde que tenha no máximo 30 caracteres: ";
	cin>>palavra;
	for(i=0; i<30;i++){
		for(j=0; j<=25;j++){
			if(palavra[i]==alfabeto[j]){
				if(palavra[i] == 'z'){
					palavra[i] = 'a';
			}
				palavra[i] = alfabeto[j+1];
				break;
			}
		}
	}
	cout<<"\nA palavra substituida é: "<<palavra;	
}

void dessubstituicao(){
char* palavra = new char;
	int i=0, j=0;
	
	cout<<"\n\nDigite a palavra que deseja descriptografar, desde que tenha no máximo 30 caracteres: ";
	cin>>palavra;
	for(i=0; i<30;i++){
		for(j=0; j<=25;j++){
			if(palavra[i]==alfabeto[j]){
				if(palavra[i] == 'z'){
					palavra[i] = 'a';
			}
				palavra[i] = alfabeto[j-1];
				break;
			}
		}
	}
	cout<<"\nA palavra substituida é: "<<palavra;		
}

void transposicao(){
	
	int i=0, cont=0;
	char aux;
	char* palavra = new char;
	cout<<"\n\nDigite a palavra que deseja criptografar com transposição, desde que tenha no máximo 30 caracteres: ";
	cin>>palavra;
	
	for(i=0; i<=strlen(palavra); i++){		
		if(cont%2==0){
			aux = palavra[i];
			palavra[i] = palavra[i+1];
			palavra[i+1] = aux;
		}
		cont++;
	}
	
	cout<<"\nA palavra substituida é: "<<palavra;	
	
}

void destransposicao(){
	int i=0, cont=0;
	char aux;
	char* palavra = new char;
	cout<<"\n\nDigite a palavra que deseja criptografar com transposição, desde que tenha no máximo 30 caracteres: ";
	cin>>palavra;
	
	for(i=0; i<=strlen(palavra); i++){		
		if(cont%2==0){
			aux = palavra[i+1];
			palavra[i+1] = palavra[i];
			palavra[i] = aux;
		}
		cont++;
	}
	
	cout<<"\nA palavra substituida é: "<<palavra;	
}

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int p=0;
	
	do{
	cout<<"\n\n          Menu"<<"\n\n1 - Criptografia por substituição\n2 - Descriptografia por substituição"<<
	"\n3 - Criptografia por substituição\n4 - Descriptografia por substituição\n"<<
	"5 - Sair do programa"<<"\n\nDigite a opção desejada: ";
	cin>>p;
	switch(p){
		case 1:
			
			substituicao();
			break;
		
		case 2:
			dessubstituicao();
			break;
		
		case 3:
			transposicao();
			break;
			
		case 4:
			destransposicao();
			break;
			
		case 5:
			p=5;
			break;
			
		default:
			cout<<"\n\nOpção inválida, selecione outra.";
			
	}
	}
	while(p!=5);
	
	return 0;
}