#include <stdio.h>

int validaQuantidade(int quantidade)
{
    if (quantidade >= 0)
    {
        return quantidade;
    }
    else
    {
        return -1;
    }
}

float calculaSalario(int quantidade)
{
    float salarioBase = 600.00;
    float salarioTotal = 0;
    float adicional = 0;

    if (quantidade <= 50)
    {
        printf("Não existe adicional de produtividade\n");
        return salarioBase;
    }
    else if (quantidade > 50 && quantidade <= 80)
    {
        adicional = 0.5 * (quantidade - 50);
    }
    else if (quantidade > 80)
    {
        adicional = 0.5 * (80 - 50) + 0.75 * (quantidade - 80);
    }

    salarioTotal = salarioBase + adicional;
    return salarioTotal;
}

void mostraFinal()
{
    int quantidade;
    float salarioTotal;

    for (int contadorFuncionario = 1;; contadorFuncionario++)
    {
        printf("Digite a quantidade de peças fabricadas pelo funcionário %d (ou digite 0 para encerrar): ", contadorFuncionario);
        scanf("%d", &quantidade);

        if (quantidade == 0)
        {
            printf("Encerrado!\n");
            break;
        }
        else
        {
            quantidade = validaQuantidade(quantidade);

            if (quantidade == -1)
            {
                printf("Quantidade inválida. Digite um valor não negativo.\n");
                continue;
            }

            salarioTotal = calculaSalario(quantidade);
            printf("O salário do funcionário %d é: %.2f\n", contadorFuncionario, salarioTotal);
        }
    }
}

int main()
{
    mostraFinal();
    return 0;
}
