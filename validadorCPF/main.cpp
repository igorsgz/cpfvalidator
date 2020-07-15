#include <iostream>
#include <locale.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    //variaveis para separar os numeros do cpf
    int numCpf, num1, num2, num3, num4, num5, num6, num7, num8, num9;

    //variaveis para os resultados das multiplicacoes pelos pesos
    int digitoVerificador1, digitoVerificador2, restoDivisao;

    //input dos 9 números do cpf
    cout << "Digite os 9 dígitos do cpf: ";
    cin >> numCpf;

    //variaveis com cada numero digitado
    num1 = numCpf % 1000000000 / 100000000;
    num2 = numCpf % 100000000 / 10000000;
    num3 = numCpf % 10000000 / 1000000;
    num4 = numCpf % 1000000 / 100000;
    num5 = numCpf % 100000 / 10000;
    num6 = numCpf % 10000 / 1000;
    num7 = numCpf % 1000 / 100;
    num8 = numCpf % 100 / 10;
    num9 = numCpf % 10;

    //----- inicio do calculo do primeiro digito verificador -----

    //primeiro soma-se os pesos e depois calcula o resto da divisao
    restoDivisao = ((num1 * 10) + (num2 * 9) + (num3 * 8) + (num4 * 7) + (num5 * 6) + (num6 * 5) + (num7 * 4) + (num8 * 3) + (num9 * 2)) % 11;
    cout << "1: " << restoDivisao << "\n";
    //valida se o resto da divisao é menor que 2
    //se sim, o digito verificador se torna 0
    //se nao o digito verificador se torna resto da divisao menos 11
    if (restoDivisao < 2)
    {
        digitoVerificador1 = 0;
    }
    else
    {
        digitoVerificador1 = 11 - restoDivisao;
    }

    //------ fim do calculo do primeiro digito verificador -------

    //------ inicio do calculo do segundo digito verificador -----

    //praticamente como o passo anterior, só que agora adicionamos o digito verificador 1 com o peso 11 na somatoria
    restoDivisao = ((num1 * 11) + (num2 * 10) + (num3 * 9) + (num4 * 8) + (num5 * 7) + (num6 * 6) + (num7 * 5) + (num8 * 4) + (num9 * 3) + (digitoVerificador1 * 2)) % 11;

    cout << "2: " << restoDivisao << "\n";

    //valida se o resto da divisao é menor que 2
    //se sim, o digito verificador se torna 0
    //se nao o digito verificador se torna resto da divisao menos 11
    if (restoDivisao < 2)
    {
        digitoVerificador2 = 0;
    }
    else
    {
        digitoVerificador2 = 11 - restoDivisao;
    }

    //----- fim do calculo do segundo digito verificador ---------

    cout << "Os dois dígitos verificadores sao: " << digitoVerificador1 << ", " << digitoVerificador2 << "\n";
    cout << "------------------------------------------------- \n";
    cout << "Assim, o CPF final fica: " << numCpf << "-" << digitoVerificador1 << digitoVerificador2 << "\n";
    cout << "------------------------------------------------- \n";

    return 0;
}
