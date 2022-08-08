#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

struct Alunos{
	int ra;
	char nome[40];
	char endereco[50];
	char telefone[11];
	char cidade[30];
	char uf[2];
};

struct IdxAlunos{
	int cod;
	int end;
};

struct Editoras{
	int cod;
	char nome[40];
	char endereco[50];
	char telefone[11];
	char cidade[30];
	char uf[2];
};

struct IdxEditoras{
	int cod;
	int end;
};

struct Livros{
	int cod;
	char desc[40];
	int codEdit;
	char status[1];
};

struct IdxLivros{
	int cod;
	int end;
};

struct Emprestimo{
	int cod;
	int codRa;
	int codLivro;
	int anoEmp;
	int mesEmp;
	int diaEmp;
	int anoDev;
	int mesDev;
	int diaDev;
	char status[1];
};

struct IdxEmprestimo{
	int cod;
	int end;
};

void leituraAlunos (struct Alunos a1[], int &cont, struct IdxAlunos i1[]){
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++){
        cout << "\n\nRA do Aluno " << (i+1) << ": ";
        cin >> a1[i].ra;
        if (a1[i].ra > 0){
            cout << "Nome: ";
            cin >> a1[i].nome;
            cout << "Endereco: ";
            cin >> a1[i].endereco;
            cout << "Telefone: ";
            cin >> a1[i].telefone;
            cout << "Cidade: ";
            cin >> a1[i].cidade;
            cout << "Estado: ";
            cin >> a1[i].uf;
			i1[i].cod = a1[i].ra;
			i1[i].end = i;
        }
        else saida = 0;
    }
    cont = i-1;
}

void leituraEditoras (struct Editoras e1[], int &cont, struct IdxEditoras i1[]){
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++){
        cout << "\n\nCodigo da Editora " << (i+1) << ": ";
        cin >> e1[i].cod;
        if (e1[i].cod > 0){
            cout << "Nome: ";
            cin >> e1[i].nome;
            cout << "Endereco: ";
            cin >> e1[i].endereco;
            cout << "Telefone: ";
            cin >> e1[i].telefone;
            cout << "Cidade: ";
            cin >> e1[i].cidade;
            cout << "Estado: ";
            cin >> e1[i].uf;
			i1[i].cod = e1[i].cod;
			i1[i].end = i;
        }
        else saida = 0;
    }
    cont = i-1;
}

void leituraLivros (struct Livros l1[], int &cont, struct IdxLivros i1[]){
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++){
        cout << "\n\nCodigo da Editora " << (i+1) << ": ";
        cin >> e1[i].cod;
        if (e1[i].cod > 0){
            cout << "Descrição: ";
            cin >> l1[i].desc;
            cout << "Codigo da Editora: ";
            cin >> l1[i].codEdit;
            cout << "Situação: ";
            cin >> l1[i].status;
			i1[i].cod = l1[i].cod;
			i1[i].end = i;
        }
        else saida = 0;
    }
    cont = i-1;
}



int main (){
	struct Alunos a1[20];
	struct IdxAluno i1[20];
	int contA1;
	
	leituraAlunos(a1,contA1,i1);
	mostrar (a1,contA1,i1);
	getch();
}
