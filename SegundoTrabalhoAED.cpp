#include <iostream>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
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

struct Emprestimos{
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

struct IdxEmprestimos{
	int cod;
	int end;
};

void mainMenu (){
	system("cls");
	cout << "\n\nMenu";
	cout << "\n0 - Sair";
	cout << "\n1 - Alunos";
	cout << "\n2 - Livros";
	cout << "\n3 - Editoras";
	cout << "\n4 - Empréstimos";
}

string buscarEditoras (struct Editoras e1[], struct IdxEditoras i1[], int cont, int cod){
	int i = 0, f = cont, x = 0;
    int m = (i + f) / 2;
    while (x == 0){
    for (; f >= i && cod != i1[m].cod; m = (i + f) / 2){
        if (cod > i1[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = i1[m].end;
    if ((cod == i1[m].cod)){
		return(e1[i].nome);
    }
    else{
    	return("Não encontrado");
	}
	}
}

string buscarAlunos (struct Alunos a1[], struct IdxAlunos i1[], int cont, int cod){
	int i = 0, f = cont, x = 0;
    int m = (i + f) / 2;
    while (x == 0){
    for (; f >= i && cod != i1[m].cod; m = (i + f) / 2){
        if (cod > i1[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = i1[m].end;
    if ((cod == i1[m].cod)){
		return(a1[i].nome);
    }
    else{
    	return("Não encontrado");
	}
	}
}

string buscarLivrosDisponiveis (struct Livros l1[], struct IdxLivros i1[], int cont, int cod){
	int i = 0, f = cont, x = 0;
    int m = (i + f) / 2;
    while (x == 0){
    for (; f >= i && cod != i1[m].cod; m = (i + f) / 2){
        if (cod > i1[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = i1[m].end;
    if (cod == i1[m].cod && strcmp(l1[i].statusEmp,"D") == 0){
    	strcpy(l1[i].statusEmp,"E");
		return(l1[i].desc);
    }
    else{
    	cout << "\nNão encontrado. Digite Novamente: ";
    	cin >> cod;
	}
	}
}

void buscarLivrosEmprestados (struct Livros l1[], struct IdxLivros i1[], int cont, int cod){
	int i = 0, f = cont, x = 0;
    int m = (i + f) / 2;
    for (; f >= i && cod != i1[m].cod; m = (i + f) / 2){
        if (cod > i1[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = i1[m].end;
    if (cod == i1[m].cod && strcmp(l1[i].statusEmp,"E") == 0){
    	strcpy(l1[i].statusEmp,"D");
    }
    else{
    	cout << "\nO livro já foi devolvido" << endl;
	}
}

string buscarLivros (struct Livros l1[], struct IdxLivros i1[], int cont, int cod){
	int i = 0, f = cont, x = 0;
    int m = (i + f) / 2;
    while (x == 0){
    for (; f >= i && cod != i1[m].cod; m = (i + f) / 2){
        if (cod > i1[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = i1[m].end;
    if (cod == i1[m].cod){
		return(l1[i].desc);
    }
    else{
		return("Não encontrado");
	}
	}
}

void leituraIdxAlunos (struct IdxAlunos idx[], int cont){
    for (int i = 0; i < cont; i++){
        cout << "\n\nCodigo do Indice do Aluno " << (i+1) << ": ";
        cin >> idx[i].cod;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx[i].end;
    }
}

void leituraAlunos (struct Alunos a1[], struct IdxAlunos i1[], int &cont){
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++){
        cout << "\n\nRA do Aluno " << (i+1) << ": ";
        cin >> a1[i].ra;fflush(stdin);
        if (a1[i].ra > 0){
            cout << "Nome: ";
            cin.getline(a1[i].nome,41);fflush(stdin);
            cout << "Endereco: ";
            cin.getline(a1[i].endereco,51);fflush(stdin);
            cout << "Telefone: ";
            cin.getline(a1[i].telefone,13);fflush(stdin);
            cout << "Cidade: ";
            cin.getline(a1[i].cidade,31);fflush(stdin);
            cout << "Estado: ";
            cin.getline(a1[i].uf,3);fflush(stdin);   

			a1[i].status = 0;
        }
        else saida = 0;
    }
    cont = i-1;
    leituraIdxAlunos(i1,cont);
}

void leituraIdxEditoras (struct IdxEditoras idx[], int cont){
    for (int i = 0; i < cont; i++){
        cout << "\n\nCodigo do Indice da Editora " << (i+1) << ": ";
        cin >> idx[i].cod;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx[i].end;
    }
}

void leituraEditoras (struct Editoras e1[], struct IdxEditoras i1[], int &cont){
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++){
        cout << "\n\nCodigo da Editora " << (i+1) << ": ";
        cin >> e1[i].cod;fflush(stdin);
        if (e1[i].cod > 0){
            cout << "Nome: ";
            cin.getline(e1[i].nome,41);fflush(stdin);
            cout << "Endereco: ";
            cin.getline(e1[i].endereco,51);fflush(stdin);
            cout << "Telefone: ";
            cin.getline(e1[i].telefone,13);fflush(stdin);
            cout << "Cidade: ";
            cin.getline(e1[i].cidade,31);fflush(stdin);
            cout << "Estado: ";
            cin.getline(e1[i].uf,3);fflush(stdin);

			e1[i].status = 0;
        }
        else saida = 0;
    }
    cont = i-1;
    leituraIdxEditoras(i1,cont);
}

void leituraIdxLivros (struct IdxLivros idx[], int cont){
    for (int i = 0; i < cont; i++){
        cout << "\n\nCodigo do Indice do Livro " << (i+1) << ": ";
        cin >> idx[i].cod;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx[i].end;
    }
}

void leituraLivros (struct Livros l1[], struct IdxLivros i1[], int &cont, struct Editoras e1[],struct IdxEditoras ie1[], int contEdit){
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++){
        cout << "\n\nCodigo do Livro " << (i+1) << ": ";
        cin >> l1[i].cod;fflush(stdin);
        if (l1[i].cod > 0){
            cout << "Descrição: ";
            cin.getline(l1[i].desc,41);fflush(stdin);
            cout << "Codigo da Editora: ";
            cin >> l1[i].codEdit;fflush(stdin);
    		cout << "Nome da Editora: " << buscarEditoras(e1,ie1, contEdit, l1[i].codEdit) << endl;
			strcpy(l1[i].statusEmp,"D");
			l1[i].status = 0;
        }
        else saida = 0;
    }
    cont = i-1;
    leituraIdxLivros(i1,cont);
}

void incluirAlunos (struct Alunos a1[], struct IdxAlunos i1[], int &cont, int cod){
	int i = 0, f = cont, x = 0;
    int m = (i + f) / 2;
    while (x == 0){
    for (; f >= i && cod != i1[m].cod; m = (i + f) / 2){
        if (cod > i1[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }

    if ((cod == i1[m].cod)){
        cout << "\nAluno já existe";
        cout << "\nRA: ";
    	cin >> cod;
    }
    else{
    	x = 1 ;
	}
}

	a1[cont].ra = cod;fflush(stdin);
    cout << "Nome: ";
    cin.getline(a1[cont].nome,41);fflush(stdin);
    cout << "Endereço: ";
    cin.getline(a1[cont].endereco,51);fflush(stdin);
    cout << "Telefone: ";
    cin.getline(a1[cont].telefone,13);fflush(stdin);
    cout << "Cidade: ";
    cin.getline(a1[cont].cidade,31);fflush(stdin);
    cout << "Estado: ";
    cin.getline(a1[cont].uf,3);fflush(stdin);
    a1[cont].status = 0;
    // inclusao na area de indices
    if(cont == 0){
	i1[0].cod = cod;
    i1[0].end = cont;
	}
	else{
    for (i = cont - 1; i1[i].cod > cod && i >= 0; i--){
        i1[i+1].cod = i1[i].cod;
        i1[i+1].end = i1[i].end;
    }
    i1[i+1].cod = cod;
    i1[i+1].end = cont;
}
    cout << "\n\nInclusao realizada com Sucesso";
    cont++;
    getch();
}

void incluirEditoras (struct Editoras e1[], struct IdxEditoras i1[], int &cont, int cod){
	int i = 0, f = cont, x = 0;
    int m = (i + f) / 2;
    while (x == 0){
    for (; f >= i && cod != i1[m].cod; m = (i + f) / 2){
        if (cod > i1[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }

    if ((cod == i1[m].cod)){
        cout << "\nEditora já existe";
        cout << "\nCódigo: ";
    	cin >> cod;
    }
    else{
    	x = 1 ;
	}
}

	e1[cont].cod = cod;fflush(stdin);
    cout << "Nome: ";
    cin.getline(e1[cont].nome,41);fflush(stdin);
    cout << "Endereço: ";
    cin.getline(e1[cont].endereco,51);fflush(stdin);
    cout << "Telefone: ";
    cin.getline(e1[cont].telefone,13);fflush(stdin);
    cout << "Cidade: ";
    cin.getline(e1[cont].cidade,31);fflush(stdin);
    cout << "Estado: ";
    cin.getline(e1[cont].uf,3);fflush(stdin);
    e1[cont].status = 0;
    // inclusao na area de indices
    if(cont == 0){
	i1[0].cod = cod;
    i1[0].end = cont;
	}
	else{
    for (i = cont - 1; i1[i].cod > cod && i >= 0; i--){
        i1[i+1].cod = i1[i].cod;
        i1[i+1].end = i1[i].end;
    }
    i1[i+1].cod = cod;
    i1[i+1].end = cont;
}
    cout << "\n\nInclusao realizada com Sucesso";
    cont++;
    getch();
}

void incluirLivros (struct Livros l1[], struct IdxLivros i1[], int &cont, int cod, struct Editoras e1[],struct IdxEditoras ie1[], int contEdit){
	int i = 0, f = cont, x = 0;
    int m = (i + f) / 2;
    while (x == 0){
    for (; f >= i && cod != i1[m].cod; m = (i + f) / 2){
        if (cod > i1[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    if ((cod == i1[m].cod)){
        cout << "\nLivro já existe";
        cout << "\nCódigo: ";
    	cin >> cod;
    }
    else{
    	x = 1 ;
	}
}
    // inclusao na area de indices

	l1[cont].cod = cod;fflush(stdin);
    cout << "Descricao: ";
    cin.getline(l1[cont].desc,41);fflush(stdin);
    cout << "Codigo da Editora: ";
    cin >> l1[cont].codEdit;fflush(stdin);
    cout << "Nome da Editora: " << buscarEditoras(e1,ie1, contEdit, l1[i].codEdit) << endl;
	strcpy(l1[cont].statusEmp,"D");
    l1[cont].status = 0;
    
    if(cont == 0){
	i1[0].cod = cod;
    i1[0].end = cont;
	}
	else{
    for (i = cont - 1; i1[i].cod > cod && i >= 0; i--){
        i1[i+1].cod = i1[i].cod;
        i1[i+1].end = i1[i].end;
    }
    i1[i+1].cod = cod;
    i1[i+1].end = cont;
}
    cout << "\n\nInclusao realizada com Sucesso";
    cont++;
    getch();
}

void excluirLivros (struct IdxLivros idx[], struct Livros l1[], int &cont, int cod){
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
    
}

void excluirAlunos (struct IdxAlunos idx[], struct Alunos a1[], int &cont, int cod){
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
    
}

void excluirEditoras (struct IdxEditoras idx[], struct Editoras e1[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2){
        if (cod > idx[m].cod)
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
        cout << "Editora nao cadastrada";
    
}

void mostrarAlunos(struct Alunos a1[], struct IdxAlunos i1[], int cont){
	int m;
	cout << "\n\nAlunos" << endl;
	for(int i=0;i<cont;i++){
		m=i1[i].end;
		if(a1[m].status==0){
		cout << "\nRA:" << a1[m].ra << endl;
		cout << "Nome:" << a1[m].nome << endl;
		cout << "Endereço:" << a1[m].endereco << endl;
		cout << "Telefone:" << a1[m].telefone << endl;
		cout << "Cidade:" << a1[m].cidade << endl;
		cout << "Estado:" << a1[m].uf << endl;		
	}
}
getch();
}

void mostrarLivros(struct Livros l1[], struct IdxLivros i1[], int cont, struct Editoras e1[],struct IdxEditoras ie1[], int contEdit){
	int m;
	cout << "\n\nLivros" << endl;
	for(int i=0;i<cont;i++){
		m=i1[i].end;
		if(l1[m].status==0){
		cout << "\nCódigo:" << l1[m].cod << endl;
		cout << "Descrição:" << l1[m].desc << endl;
		cout << "Editora:" << buscarEditoras(e1,ie1,contEdit,l1[m].codEdit) << endl;
		cout << "Situação:" << l1[m].statusEmp << endl;	
	}
}
getch();
}

void mostrarEditoras(struct Editoras e1[], struct IdxEditoras i1[], int cont){
	int m;
	cout << "\n\nEditoras" << endl;
	for(int i=0;i<cont;i++){
		m=i1[i].end;
		if(e1[m].status==0){
		cout << "\nCódigo:" << e1[m].cod << endl;
		cout << "Nome:" << e1[m].nome << endl;
		cout << "Endereço:" << e1[m].endereco << endl;
		cout << "Telefone:" << e1[m].telefone << endl;
		cout << "Cidade:" << e1[m].cidade << endl;
		cout << "Estado:" << e1[m].uf << endl;		
	}
}
getch();
}

void emprestarLivros(struct Emprestimos e1[],struct IdxEmprestimos i1[], int &cont, int cod, struct Livros l1[], struct IdxLivros il1[], int contL, struct Alunos a1[], struct IdxAlunos ia1[], int contA){
	int codLivro, codAluno;
	int i = 0, f = cont, x = 0;
    int m = (i + f) / 2;
    while (x == 0){
    for (; f >= i && cod != i1[m].cod; m = (i + f) / 2){
        if (cod > i1[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    if ((cod == i1[m].cod)){
        cout << "\n\n Empréstimo já existe";
        cout << "Código: ";
    	cin >> cod;
    }
    else{
    	x = 1 ;
	}
}
    // inclusao na area de indices

		e1[cont].cod = cod;
		cout << "RA do aluno: ";
		cin >> codAluno;
		e1[cont].codRa = codAluno;
		cout << "Nome: " << buscarAlunos(a1,ia1,contA,codAluno) << endl;
		cout << "Código do livro: ";
		cin >> codLivro; 
		e1[cont].codLivro = codLivro;
		cout << "Descrição: " << buscarLivrosDisponiveis(l1,il1,contL,codLivro) << endl;
		cout << "Data do empréstimo" << endl;
		cout << "Dia: ";
		cin >> e1[cont].diaEmp;
		cout << "Mês: ";
		cin >> e1[cont].mesEmp;
		cout << "Ano: ";
		cin >> e1[cont].anoEmp;
		cout << "Data de devolução" << endl;
		cout << "Dia: ";
		cin >> e1[cont].diaDev;
		cout << "Mês: ";
		cin >> e1[cont].mesDev;
		cout << "Ano: ";
		cin >> e1[cont].anoDev;
		strcpy(e1[cont].statusEmp,"E");
		e1[cont].status=0;
    
    if(cont == 0){
	i1[0].cod = cod;
    i1[0].end = cont;
	}
	else{
    for (i = cont - 1; i1[i].cod > cod && i >= 0; i--){
        i1[i+1].cod = i1[i].cod;
        i1[i+1].end = i1[i].end;
    }
    i1[i+1].cod = cod;
    i1[i+1].end = cont;
}
    cout << "\n\nInclusao realizada com Sucesso";
    cont++;
    getch();

}

void devolverLivros(struct Emprestimos e1[],struct IdxEmprestimos idx[], int &cont, int cod, struct Livros l1[], struct IdxLivros il1[], int contL){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2){
        if (cod > idx[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idx[m].end;
    if ((cod == idx[m].cod) && strcmp(e1[i].statusEmp,"E") == 0 && e1[i].status == 0){
        strcpy(e1[i].statusEmp,"D");
        buscarLivrosEmprestados(l1,il1,contL,e1[i].codLivro);
        cout << "\n\n Empréstimo devolvido com Sucesso";
    }
    else
        cout << "Livro já foi devolvido ou o código é inválido.";	
	
}

void excluirEmprestimo(struct Emprestimos e1[], struct IdxEmprestimos idx[], int cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2){
        if (cod > idx[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idx[m].end;
    if ((cod == idx[m].cod) && e1[i].status == 0){
        e1[i].status = 1;
        cout << "\n\n Empréstimo excluido com Sucesso";
    }
    else
        cout << "Empréstimo não cadastrado";
}

void mostrarAtrasado(struct Emprestimos e1[],struct IdxEmprestimos i1[], int cont, struct Livros l1[], struct IdxLivros il1[], int contL, struct Alunos a1[], struct IdxAlunos ia1[], int contA){
	int m, dia, mes, ano;
	struct tm *p;
    time_t seconds;
    
    time(&seconds);
    p = localtime(&seconds);

	dia = p->tm_mday ;
	mes = p->tm_mon + 1;
	ano = p->tm_year + 1900;
	for(int i = 0;i<cont;i++){
		m=i1[i].end;
		if(e1[m].status == 0 && strcmp(e1[m].statusEmp,"E") == 0){
			if(ano == e1[m].anoDev){
				if(mes == e1[m].mesDev){
					if (dia > e1[m].diaDev){
						cout << "\n\nCódigo do empréstimo: " << e1[m].cod << endl;
						cout << "RA do aluno: " << e1[m].codRa << endl;
						cout << "Nome: " << buscarAlunos(a1,ia1,contA,e1[m].codRa) << endl;
						cout << "Código do livro: " << e1[m].codLivro << endl;
						cout << "Descrição: " << buscarLivros(l1,il1,contL,e1[m].codLivro) << endl;
						cout << "Data do empréstimo: " << e1[m].diaEmp << "/" << e1[m].mesEmp << "/" << e1[m].anoEmp << endl;
						cout << "Data de devolução: " << e1[m].diaDev << "/" << e1[m].mesDev << "/" << e1[m].anoDev << endl;
					}
				}
				else if(mes > e1[m].mesDev){
					cout << "\n\nCódigo do empréstimo: " << e1[m].cod << endl;
					cout << "RA do aluno: " << e1[m].codRa << endl;
					cout << "Nome: " << buscarAlunos(a1,ia1,contA,e1[m].codRa) << endl;
					cout << "Código do livro: " << e1[m].codLivro << endl;
					cout << "Descrição: " << buscarLivros(l1,il1,contL,e1[m].codLivro) << endl;
					cout << "Data do empréstimo: " << e1[m].diaEmp << "/" << e1[m].mesEmp << "/" << e1[m].anoEmp << endl;
					cout << "Data de devolução: " << e1[m].diaDev << "/" << e1[m].mesDev << "/" << e1[m].anoDev << endl;					
				}
			}
			else if (ano > e1[m].anoDev){
				cout << "\n\nCódigo do empréstimo: " << e1[m].cod << endl;
				cout << "RA do aluno: " << e1[m].codRa << endl;
				cout << "Nome: " << buscarAlunos(a1,ia1,contA,e1[m].codRa) << endl;
				cout << "Código do livro: " << e1[m].codLivro << endl;
				cout << "Descrição: " << buscarLivros(l1,il1,contL,e1[m].codLivro) << endl;
				cout << "Data do empréstimo: " << e1[m].diaEmp << "/" << e1[m].mesEmp << "/" << e1[m].anoEmp << endl;
				cout << "Data de devolução: " << e1[m].diaDev << "/" << e1[m].mesDev << "/" << e1[m].anoDev << endl;
			}	
		}
	}
	getch();
}

void mostrarEmprestimos(struct Emprestimos e1[],struct IdxEmprestimos i1[], int cont, struct Livros l1[], struct IdxLivros il1[], int contL, struct Alunos a1[], struct IdxAlunos ia1[], int contA){
	int m;
	for(int i = 0;i<cont;i++){
		m=i1[i].end;
		if(e1[m].status == 0 && strcmp(e1[m].statusEmp,"E") == 0){
					cout << "\n\nCódigo do empréstimo: " << e1[m].cod << endl;
					cout << "RA do aluno: " << e1[m].codRa << endl;
					cout << "Nome: " << buscarAlunos(a1,ia1,contA,e1[m].codRa) << endl;
					cout << "Código do livro: " << e1[m].codLivro << endl;
					cout << "Descrição: " << buscarLivros(l1,il1,contL,e1[m].codLivro) << endl;
					cout << "Data do empréstimo: " << e1[m].diaEmp << "/" << e1[m].mesEmp << "/" << e1[m].anoEmp << endl;
					cout << "Data de devolução: " << e1[m].diaDev << "/" << e1[m].mesDev << "/" << e1[m].anoDev << endl;
				}
			}
	getch();
}

void menuAlunos (struct Alunos a1[], struct IdxAlunos i1[], int &cont){
	int option = 0, x = 0, cod = 0;
	
	while(x == 0){
	fflush(stdin);
	system("cls");
	cout << "\n\nAlunos";
	cout << "\n0 - Voltar";
	cout << "\n1 - Ler Alunos";
	cout << "\n2 - Incluir Alunos";
	cout << "\n3 - Excluir Alunos";
	cout << "\n4 - Mostrar Alunos";
	cout << "\n\nDigite sua opção: ";
	cin >> option;
	
	switch(option){
		case 1:
			leituraAlunos(a1,i1,cont);
			break;
		case 2:
			cout << "\n\nInclusão de Aluno";
			cout << "\nRA: ";
    		cin >> cod;
			incluirAlunos(a1,i1,cont,cod);
			break;
		case 3:
			cout << "\n\nExclusão de Aluno";
			cout << "\nDigite o código do aluno que deseja excluir: ";
    		cin >> cod;
			excluirAlunos(i1,a1,cont,cod);
			break;
		case 4:
			mostrarAlunos(a1,i1,cont);
			break;
		case 0:
			x=1;
			break;		
		}
	}
}

void menuEditoras (struct Editoras e1[], struct IdxEditoras i1[], int &cont){
	int option = 0, x = 0, cod = 0;
	
	while(x == 0){
	fflush(stdin);
	system("cls");
	cout << "\n\nEditoras";
	cout << "\n0 - Voltar";
	cout << "\n1 - Ler Editoras";
	cout << "\n2 - Incluir Editoras";
	cout << "\n3 - Excluir Editoras";
	cout << "\n4 - Mostrar Editoras";
	cout << "\n\nDigite sua opção: ";
	cin >> option;
	
	switch(option){
		case 1:
			leituraEditoras(e1,i1,cont);
			break;
		case 2:
			cout << "\n\nInclusão de Editora";
			cout << "\nCodigo: ";
    		cin >> cod;
			incluirEditoras(e1,i1,cont,cod);
			break;
		case 3:
			cout << "\n\nExclusão de Editora";
			cout << "\nDigite o código da editora que deseja excluir: ";
    		cin >> cod;
			excluirEditoras(i1,e1,cont,cod);
			break;
		case 4:
			mostrarEditoras(e1,i1,cont);
			break;
		case 0:
			x=1;
			break;		
		}
	}
}

void menuLivros (struct Livros l1[], struct IdxLivros i1[], int &cont, struct Editoras e1[],struct IdxEditoras ie1[], int contEdit){
	int option = 0, x = 0, cod = 0;
	
	while(x == 0){
	fflush(stdin);
	system("cls");
	cout << "\n\nLivros";
	cout << "\n0 - Voltar";
	cout << "\n1 - Ler Livros";
	cout << "\n2 - Incluir Livros";
	cout << "\n3 - Excluir Livros";
	cout << "\n4 - Mostrar Livros";
	cout << "\n\nDigite sua opção: ";
	cin >> option;
	
	switch(option){
		case 1:
			leituraLivros(l1,i1,cont,e1,ie1,contEdit);
			break;
		case 2:
			cout << "\n\nInclusão de Livros";
			cout << "\nCodigo: ";
    		cin >> cod;
			incluirLivros(l1,i1,cont,cod,e1,ie1,contEdit);
			break;
		case 3:
			cout << "\n\nExclusão de Livros";
			cout << "\nDigite o código do Livro que deseja excluir: ";
    		cin >> cod;
			excluirLivros(i1,l1,cont,cod);
			break;
		case 4:
			mostrarLivros(l1,i1,cont,e1,ie1,contEdit);
			break;
		case 0:
			x=1;
			break;		
		}
	}
}

void menuEmprestimos (struct Emprestimos e1[],struct IdxEmprestimos i1[], int &cont, struct Livros l1[], struct IdxLivros il1[], int contL, struct Alunos a1[], struct IdxAlunos ia1[], int contA){
	int option = 0, x = 0, cod = 0;
	
	while(x == 0){
	fflush(stdin);
	system("cls");
	cout << "\n\nEmpréstimos";
	cout << "\n0 - Voltar";
	cout << "\n1 - Emprestar Livro";
	cout << "\n2 - Devolver Livro";
	cout << "\n3 - Excluir Empréstimo";
	cout << "\n4 - Mostrar Empréstimos Atrasados";
	cout << "\n5 - Mostrar Empréstimos";
	cout << "\n\nDigite sua opção: ";
	cin >> option;
	
	switch(option){
		case 1:
			cout << "\n\nEmpréstimo de Livros";
			cout << "\nCódigo: ";
    		cin >> cod;
			emprestarLivros(e1,i1,cont,cod,l1,il1,contL,a1,ia1,contA);
			break;
		case 2:
			cout << "\n\nDevolução de Livros";
			cout << "\nCódigo: ";
    		cin >> cod;
			devolverLivros(e1,i1,cont,cod,l1,il1,contL);
			break;
		case 3:
			cout << "\n\nExcluir Empréstimos";
			cout << "\nCódigo: ";
    		cin >> cod;
			excluirEmprestimo(e1,i1,cont,cod);
			break;
		case 4:
			mostrarAtrasado(e1,i1,cont,l1,il1,contL,a1,ia1,contA);
			break;
		case 5:
			mostrarEmprestimos(e1,i1,cont,l1,il1,contL,a1,ia1,contA);
			break;
		case 0:
			x=1;
			break;		
		}
	}
}

int main (){
	struct Alunos a1[20]; 
	struct Editoras e1[20]; 
	struct Livros l1[20];
	struct Emprestimos emp1[20];
	struct IdxAlunos ia1[20]; 
	struct IdxEditoras ie1[20]; 
	struct IdxLivros il1[20];
	struct IdxEmprestimos iemp1[20];
	int x = 1, option = 0, contA = 0, contE = 0, contL = 0, contEMP=0;
	setlocale(LC_ALL,"Portuguese");
	
	while(x == 1){
		mainMenu();
		fflush(stdin);
		
		cout << "\n\nDigite sua opção: ";
		cin >> option;
		
		switch(option){
			case 1:
				menuAlunos(a1,ia1,contA);
				break;
			case 2:
				menuLivros(l1,il1,contL,e1,ie1,contE);
				break;
			case 3:
				menuEditoras(e1,ie1,contE);
				break;
			case 4:
				menuEmprestimos(emp1,iemp1,contEMP,l1,il1,contL,a1,ia1,contA);
				break;
			case 0:
				x=0;
				break;
		
	}
}
getch();
}
