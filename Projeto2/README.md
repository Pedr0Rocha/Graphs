# Algoritmos em Grafos

### 1. Instruções de Uso
##### 1.1 Compilar
Para compilar basta entrar na pasta e digitar os comandos 
```
$ make clear
$ make
```
Esses comandos irão gerar um executável chamado 'mst'
##### 1.2 Executar
Para executar o programa após compilado basta digitar 
```
$ ./mst <parâmetros>
```
### 2. Parâmetros
O algoritmo possui três parâmetros
- -a <algoritmo>
   * Algoritmo a ser executado
- -f <arquivo>
   * Caminho para arquivo de teste
- -i <index>
   * Índice do vértice inicial

Para ver as dicas de uso no programa digite
```
$ ./mst -h
```
##### 2.1 Algoritmos
Algoritmos implementados:

| NOME | USO | RETORNO |
| ----: | :----: | :----------- |
| Prim  | prim | Retorna a árvore geradora mínima da entrada dada |
| Heurístico  | hrt | Retorna a árvore geradora mínima da entrada dada |

Todos os algoritmos foram implementados usando lista de adjacências.

##### 2.2 Exemplos de Uso
Executar o Prim no teste 'input.txt' com vértice inicial 0
```
$ ./mst -a prim -i 0 -f tests/input.txt
```

Executar o Heurístico no teste 'input.txt' com vértice inicial 1
```
$ ./mst -a hrt -i 1 -f tests/input.txt
```

### 3. Entradas
Os arquivos de input seguem o modelo a seguir
```
5               # numero de vértices
6               # número de arestas
0 1 1           # aresta entre vértice 0(A) e 1(B) com peso 1
0 3 2
2 1 5
1 4 2
3 0 8
```

Todos os grafos são não-orientados.