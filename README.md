<h1 align="justify">
Listas Lineares: Implementação em C
</h1>

<div style="display: inline-block;">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Maintained%3F-yes-green.svg"/> 
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
<a href="https://github.com/mpiress/midpy/issues">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat"/>
<img align="center" height="20px" width="80px" src="https://badgen.net/badge/license/MIT/green"/>
</a> 
</div>

<p> </p>
<p> </p>

<p align="justify">
Das estruturas tratadas em algoritmos e estruturas de dados I, o tipo lista é a mais flexível. Nela não há regras de inserção e remoção, o que justifica iniciarmos por ela nossa compreensão de tipos abstratos de dados. 
</p>

<p align="justify">
Primeiramente, vamos pensar o que essa estrutura (i.e., modelo estático baseado em vetores) faz em nosso computador assim que é criada. Para exemplificar, observe a imagem abaixo e imagine ela como a memória de nosso computador. Um computador modesto, com dois pentes de memória RAM, cada um com 4MB.
</p>


<img align="center" height="200px" width="800px" src="imgs/memoria.png"/> 

<p align="justify">
Quando entramos em nosso programa com a instrução int vetor[10], o que o computador faz é criar 10 posições sequenciais na memória RAM e fazer nossa variável vetor apontar para a primeira delas. Assim, se quisermos imprimir a terceira posição desse vetor podemos realizar essa operação de duas formas:
</p>


1. printf("Valor: %d", vetor[2]) : Modelo tradicional de execução, no qual a posição é utilizada; 

2. printf("Valor: %d", *(vetor+2)) : Modelo onde utilizamos a manipulação do ponteiro ao contrário da posição.


<p align="justify">
O que queremos mostrar com isso é simples: Um vetor em C/C++ é um ponteiro nato da linguagem e as posições que ele ocupa na memória são sequenciais, uma vez que a soma de seu endereço mais duas posições nos deixa apontando para o terceiro elemento do conjunto em RAM.
</p>

>*Porque a manipulação do ponteiro funciona como índice?* 
> - Como temos um vetor de inteiros, ele tem 4 bytes por posição (espaço ocupado por um int na RAM), quando somamos 2, isso não quer dizer apenas +2. Pelo contrário, ele está somando mais duas unidades de inteiros, ou seja, +8 bytes no endereço, o que o deixa exatamente na posição sequencial correta em RAM.
>
>*Porque foi apresentado isso?* 
>Para demonstrar que vetores são sequenciais e que há necessidade de espaço sequencial em RAM para que sejam alocados. Essa é a limitação das estruturas chamadas de estática, como as tratadas nesse módulo. 


<p align="justify">
Sem mais delongas, vamos ao que nos interessa. Vamos imaginar uma estrutura do tipo lista estática. O que precisamos então criar é simplesmente um vetor de **N** posições. Feita a criação, precisamos modelar um método / função para inserir dados nesse vetor, uma função para pesquisar, uma função para remover, e assim por diante. A nossa lista deve parecer com a figura abaixo:
</p>

<img align="center" height="130px" width="800px" src="imgs/lista.png"/> 

<p align="justify">
Na Figura que representa nossa lista, note que há uma variável chamada <b>primeiro</b> e uma outra chamada <b>último</b>. A variável primeiro marca o <b>início da lista</b>, enquanto o último denota <b>o final da lista</b>. Nesse modelo de lista apenas a variável último é trabalhada, ou seja, se modifica com o tempo a medida que vamos inserindo e removendo dados da lista. No início da execução, quando a <b>lista está totalmente vazia</b>, temos que <b>primeiro == último</b>, logo, estão na posição 0 do vetor. 
</p>

>Vamos as regras básicas:
>
>1. Quando a lista está fazia primeiro == último;
>2. Quando um novo elemento é inserido, o último aponta para o próximo espaço vazio da lista;
>3. Quando último maior que o tamanho do vetor (i.e., último > tamanho), a lista deve ser considerada cheia;
>4. Quando um elemento da lista é removido, todos os elementos que estão na sequência devem ser deslocados para frente e o ponteiro último deve ser atualizado, ou seja, ultimo --;

# Compilação e Execução

A lista linear disponibilizada possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando  |  Função  |
| ------------------- | ------------------- |
|  `make clean` |  Apaga a última compilação realizada e salva na pasta build |
|  `make`  |  Executa a compilação do programa utilizando o gcc nativo |
|  `make run` | Executa o programa após a realização da compilação |