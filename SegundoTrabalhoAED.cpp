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
	int status;
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
	int status;
};

struct IdxEditoras{
	int cod;
	int end;
};

struct Livros{
	int cod;
	char desc[40];
	int codEdit;
	int status;
	char statusEmp[1];
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
	int status;
	char statusEmp[1];
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
			a1.status = 0;
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
			e1.status = 0;
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
			l1.status = 0;
        }
        else saida = 0;
    }
    cont = i-1;
}

void inclusaoAlunos (struct Alunos a1[], struct IdxAlunos i1[], int &cont){
    cont++;
    cout << "RA: ";
    cin >> a1[cont].ra;
    cout << "Nome: ";
    cin >> a1[cont].nome;
    cout << "Endereço: ";
    cin >> a1[cont].endereco;
    cout << "Telefone: ";
    cin >> a1[cont].telefone;
    cout << "Cidade: ";
    cin >> a1[cont].cidade;
    cout << "Estado: ";
    cin >> a1[cont].uf;
    a1.status = 0;
    // inclusao na area de indices
    int i;
    for (i = cont - 1; i1[i].cod > cod; i--){
        i1[i+1].cod = i1[i].cod;
        i1[i+1].end = i1[i].end;
    }
    i1[i+1].cod = cod;
    i1[i+1].end = cont;
    cout << "\n\nInclusao realizada com Sucesso";
}

void inclusaoEditoras (struct Editoras e1[], struct IdxEditoras i1[], int &cont){
    cont++;
    cout << "Codigo: ";
    cin >> e1[cont].cod;
    cout << "Nome: ";
    cin >> e1[cont].nome;
    cout << "Endereço: ";
    cin >> e1[cont].endereco;
    cout << "Telefone: ";
    cin >> e1[cont].telefone;
    cout << "Cidade: ";
    cin >> e1[cont].cidade;
    cout << "Estado: ";
    cin >> e1[cont].uf;
    e1.status = 0;
    int i;
    for (i = cont - 1; i1[i].cod > cod; i--){
        i1[i+1].cod = i1[i].cod;
        i1[i+1].end = i1[i].end;
    }
    i1[i+1].cod = cod;
    i1[i+1].end = cont;
    cout << "\n\nInclusao realizada com Sucesso";
}

void inclusaoLivros (struct Livros l1[], struct IdxLivros i1[], int &cont){
    cont++;
    cout << "Codigo: ";
    cin >> a1[cont].cod;
    cout << "Descricao: ";
    cin >> a1[cont].desc;
    cout << "Codigo da Editora: ";
    cin >> a1[cont].codEdit;
    cout << "Status: ";
    cin >> a1[cont].status;
    l1.status = 0;
    int i;
    for (i = cont - 1; i1[i].cod > cod; i--){
        i1[i+1].cod = i1[i].cod;
        i1[i+1].end = i1[i].end;
    }
    i1[i+1].cod = cod;
    i1[i+1].end = cont;
    cout << "\n\nInclusao realizada com Sucesso";
}

void exclusaoLivros (struct IdxLivros idx[], struct Livros l1[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2){
        if (cod > idx[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idx[m].end;
    if ((cod == idx[m].cod) && l1[i].status == 0){
        l1[i].status = 1;
        cout << "\n\n Livro Excluido com Sucesso";
    }
    else
        cout << "Livro nao cadastrado!";
    getch();
}

void exclusaoAlunos (struct IdxAlunos idx[], struct Alunos a1[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2){
        if (cod > idx[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idx[m].end;
    if ((cod == idx[m].cod) && a1[i].status == 0){
        a1[i].status = 1;
        cout << "\n\n Aluno Excluido com Sucesso";
    }
    else
        cout << "Aluno nao cadastrado !";
    getch();
}

void exclusaoEditoras (struct indice idx[], struct Editora e1[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
        if (cod > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idx[m].end;
    if ((cod == idx[m].cod) && e1[i].status == 0){
        e1[i].status = 1;
        cout << "\n\n Editora excluida com Sucesso";
    }
    else
        cout << "Editora nao cadastrado";
    getch();
}

void buscaaleat (struct indice idx[], struct clientes cli[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
        if (cod > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idx[m].ender;
    if ((cod == idx[m].codigo) && cli[i].status == 0){
        cli[i].status = 1;
        cout << "\n\n Cliente Excluido com Sucesso";
    }
    else
        cout << "Cliente nao cadastrado";
    getch();
}



int main (){
	struct Alunos a1[20];
	struct IdxAluno i1[20];
	int contA1;
	
	leituraAlunos(a1,contA1,i1);
	mostrar (a1,contA1,i1);
	getch();
}
