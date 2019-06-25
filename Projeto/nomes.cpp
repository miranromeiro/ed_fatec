/*
 * Brincando com listas din√¢micas
 *
 * Um pequeno mimo para voc√™s, queridos alunos, avan√ßarem nesta dif√≠cil jornada.
 *
 * 
 * Monitor: Andr√© R√©
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 24/05/2019
 */
 #include <iostream>
 #include <stdlib.h>
 #include <fstream>

using namespace std;

typedef struct {
    string nome;
    int idade;
    string cpf;
    string curso;
    int opcao_curso;
    bool ins_efetivada;
    
}ELEMENTO;

 typedef struct NO{
 	ELEMENTO aluno; // chama a struct Elemento
 	struct NO* proximo; //cria uma struct do tipo "ponteiro de NO", chamada proximo, que aponta para NO, q chama a aluno
 }*LISTA;



 LISTA inicializar(LISTA lista_de_candidados){ //funÁ„o que inicializa a lista de candidatos
  lista_de_candidados = new NO; // passando a struct como valor do par‚metro
 	lista_de_candidados->proximo = NULL; // seta o valor de proximo como nulo
 	return lista_de_candidados;
 }

 LISTA cadastrar_candidato(LISTA lista_de_candidados){ //cadastra um novo candidato na struct elemento
 	
 	bool efetivado = false;
	ofstream myfile;
  	myfile.open ("alunos.txt");
	       
     ELEMENTO novo_candidato;
     cout << "Digite o nome do vestibulando " << endl;
     cin >> novo_candidato.nome;
     myfile << novo_candidato.nome << "\n";
     cout << "Digite a idade do vestibulando " << endl;
     cin >> novo_candidato.idade;
     myfile << novo_candidato.idade << "\n";
     cout << "Digite o CPF do vestibulando " << endl;
     cin >> novo_candidato.cpf;
     myfile << novo_candidato.cpf << "\n";
     cout << "Digite a opcao de curso(1- Sistemas 2- Gestao) " << endl;
     cin >> novo_candidato.opcao_curso;
	 
	 if(novo_candidato.opcao_curso == 1){
     	novo_candidato.curso = "Sistemas para Internet";
	 }else if(novo_candidato.opcao_curso == 2){
	 	novo_candidato.curso = "Gestao Empresarial";
	 };
	 
     myfile << novo_candidato.opcao_curso << "\n";
     LISTA aux = new NO; //cria uma variavel que armazena a struct NO
     
  	 aux->aluno = novo_candidato; //atribui a novo_candidato, os valores q foram inputados na struct aluno.
  	 aux->proximo  = lista_de_candidados; //passa o ponteiro "proximo" como par‚metro
     lista_de_candidados = aux; // o ponteiro proximo aponta pra um novo "aux"
     
     myfile.close();
     if(1){
     	bool efetivado = true;
	 }
     
     return lista_de_candidados;
 }
 
 //LISTA editar_cadastro(candidato){
 //	 cout << "Informe o n˙mero de inscriÁ„o do candidato" << endl;
//	 cin >>	
 //}
 
 void mostrar_inscritos(LISTA lista_de_candidados){
    LISTA no = lista_de_candidados;
 	while(no != NULL){
        if (no->proximo != NULL) {
            cout <<"Candidato: " << no->aluno.nome << "\n ";
            cout <<"Idade: " << no->aluno.idade << "\n ";
            cout <<"CPF: " << no->aluno.cpf << "\n ";
            cout <<"Curso: " << no->aluno.curso << "\n ";
            cout << "-------------------------------- \n";
        }

 		no = no->proximo;
 	}
 	cout << endl;
 }

 int numero_de_inscritos(LISTA lista_de_candidados){
     LISTA lista_local = lista_de_candidados;
 	int cont = 0;
 	while(lista_local != NULL){
 		lista_local = lista_local->proximo;
        cont++;
 	}
 	return (cont - 1);
 }

 void destruir(LISTA lista_de_candidados){
    if(lista_de_candidados->proximo != NULL ) {
        LISTA noProximo = lista_de_candidados;
        while(noProximo->proximo != NULL){
            cout << "| " << noProximo->aluno.nome;
            cout << " - " << noProximo->aluno.idade << endl;
            lista_de_candidados = noProximo->proximo;
            noProximo->proximo = NULL;
            delete noProximo;
            noProximo = lista_de_candidados;
     	}
      delete lista_de_candidados;
    }
 }

 int buscarFila(LISTA lista_de_candidados, string candidato){
     LISTA noProximo = lista_de_candidados;
     int cont = numero_de_inscritos(lista_de_candidados);
     while(noProximo != NULL){
         if (candidato == noProximo->aluno.nome) {
             return cont;
         }
         cont--;
         noProximo = noProximo->proximo;
     }
     return cont;
 }

 int main(){
     LISTA lista_de_candidados;
     char escolha = 'x';
     ELEMENTO candidado;
     lista_de_candidados = inicializar(lista_de_candidados);
     do {
           cout << "\n********************************\n";
           cout << "Digite uma letra\n\n";
           cout << "i \t Cadastrar candidato\n";
           cout << "c \t Editar cadastro\n";
           cout << "a \t Validar inscricao\n";
           cout << "e \t Encontrar candidato \n";
           cout << "p \t Listar Candidatos \n";
           cout << "q \t Encerrar .\n\n\n";
           cin >> escolha;
           if(escolha == 'i' || escolha == 'I'){
               lista_de_candidados = cadastrar_candidato(lista_de_candidados);
           }
          // if(escolha == 'c' || escolha 'C'){
           //	   lista_de_candidatos = editar_cadastro();
		  // }
           if(escolha == 'a' || escolha == 'A'){
              cout << "Lamento, funcionalidade n√£o implementada" << endl;
           }
           if(escolha == 'e' || escolha == 'E'){
               string candidato_procurado;
               cout << " Digite o nome do cliente procurado : " << endl;
               cin >> candidato_procurado;
               cout << "O candidato "<< candidato_procurado ;
               cout << " encontra-se na posicao "<< buscarFila(lista_de_candidados, candidato_procurado);
               cout << " da fila" << endl;
           }
           if(escolha == 'p' || escolha == 'P'){
               cout << "Candidatos inscritos: " << numero_de_inscritos(lista_de_candidados) << endl;
               cout << "================================" << endl;
               cout << endl;
               mostrar_inscritos(lista_de_candidados);
           }
       } while( escolha != 'q');

     destruir(lista_de_candidados);
     return 0;
 }
