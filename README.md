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


<img align="center" src="imgs/memoria.png"/> 

<p align="justify">
Quando entramos em nosso programa com a instrução int vetor[10], o que o computador faz é criar 10 posições sequenciais na memória RAM e fazer nossa variável vetor apontar para a primeira delas. Assim, se quisermos imprimir a terceira posição desse vetor podemos realizar essa operação de duas formas:
</p>

1. printf("Valor: %d", vetor[2]) : Modelo tradicional de execução, no qual a posição é utilizada; 

2. printf("Valor: %d", *(vetor+2)) : Modelo onde utilizamos a manipulação do ponteiro ao contrário da posição.

