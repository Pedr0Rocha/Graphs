# Algoritmos em Grafos

### 1. Instruções de Uso
##### 1.1 Compilar
Para compilar basta entrar na pasta e digitar os comandos 
```
$ make clear
$ make
```
Esses comandos irão gerar um executável chamado 'graphs'
##### 1.2 Executar
Para executar o programa após compilado basta digitar 
```
$ ./graphs <parâmetros>
```
### 2. Parâmetros
O algoritmo possui quatro parâmetros
- -a <algoritmo>
   * Algoritmo a ser executado
- -f <arquivo>
   * Caminho para arquivo de teste
- -i <index>
   * Índice do vértice inicial
- -g <index>
   * Índice do vértice final

Para ver as dicas de uso no programa digite
```
$ ./graphs -h
```
##### 2.1 Algoritmos
Algoritmos implementados:

| NOME | USO | RETORNO |
| ----: | :----: | :----------- |
| Busca em Profundidade  | dfs | Retorna o tempo de descoberta, tempo final e a ordem topológica de todos os vértices |
| Busca em Largura  | bfs | Retorna a distância de todos os vértices em relação ao vértice inicial escolhido |
| BellmanFord  | bellman | Retorna o caminho mínimo com pesos entre o vértice inicial e final, também acha ciclos negativos |
| Componentes Fortemente Conectados  | scc | Retorna todos os componentes fortemente conectados do grafo |

##### 2.2 Exemplos de Uso
Executar o Dfs no teste 'input.txt' com vértice inicial 0
```
$ ./graphs -a dfs -i 0 -f input.txt
```

Executar o Bfs no teste 'input.txt' com vértice inicial 1
```
$ ./graphs -a bfs -i 1 -f input.txt
```

Executar o BellmanFord no teste 'input.txt' com vértice inicial 0 e vértice final 4
```
$ ./graphs -a bellman -i 0 -g 4 -f input.txt
```

Executar o Scc no teste 'input.txt' com vértice inicial 0
```
$ ./graphs -a scc -i 0 -f input.txt
```

