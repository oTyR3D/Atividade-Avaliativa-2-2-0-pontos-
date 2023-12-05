#include <stdio.h>

typedef enum
{
    MASCULINO,
    FEMININO
} Genero;

typedef struct
{
    char nome[20];
    Genero genero;
    float salario;
} Funcionario;

void classificaSalario(float salario)
{
    if (salario > 1400)
    {
        printf("Acima do salário mínimo\n");
    }
    else if (salario == 1400)
    {
        printf("Igual ao salário mínimo\n");
    }
    else
    {
        printf("Abaixo do salário mínimo\n");
    }
}

float validarSalario()
{
    float salario;
    do
    {
        printf("Informe o salário em reais: ");
        scanf("%f", &salario);
        if (salario > 1.0)
        {
            return salario;
        }
        else
        {
            printf("Salário inválido! Tente novamente.\n");
        }
    } while (1);
}

Genero validarGenero()
{
    char sexo;
    do
    {
        printf("Informe o gênero (M ou F): ");
        scanf(" %c", &sexo);
        if (sexo == 'M')
        {
            return MASCULINO;
        }
        else if (sexo == 'F')
        {
            return FEMININO;
        }
        else
        {
            printf("Opção inválida! Tente novamente.\n");
        }

    } while (1);
}

void cadastrarFuncionario(Funcionario *funcionario)
{
    printf("Informe o nome: ");
    scanf("%s", funcionario->nome);

    funcionario->genero = validarGenero();
    funcionario->salario = validarSalario();
}

void mostrarClassificacao(Funcionario *funcionario)
{
    printf("\nNome: %s\n", funcionario->nome);
    printf("Salário: %.2f\n", funcionario->salario);
    printf("Classificação em relação ao salário mínimo: ");
    classificaSalario(funcionario->salario);
    printf("Gênero: %s\n", (funcionario->genero == MASCULINO) ? "Masculino" : "Feminino");
}

int main()
{
    int abaixoSalarioMinimo = 0, acimaSalarioMinimo = 0;

    #define TAM 50
    Funcionario funcionarios[TAM];

    for (int i = 0; i < TAM; i++)
    {
        printf("\nFuncionário %d\n", i + 1);
        cadastrarFuncionario(&funcionarios[i]);
        mostrarClassificacao(&funcionarios[i]);

        if (funcionarios[i].salario > 1400)
        {
            acimaSalarioMinimo++;
        }
        else
        {
            abaixoSalarioMinimo++;
        }
    }

    printf("\nQuantidade de funcionários abaixo do salário mínimo: %d\n", abaixoSalarioMinimo);
    printf("Quantidade de funcionários acima do salário mínimo: %d\n", acimaSalarioMinimo);

    return 0;
}
