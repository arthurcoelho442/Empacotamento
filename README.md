# Empacotamento - Bin Packing

Este trabalho trata de Busca e Ordenação em Memória Principal, com objetivo de implementar quatro heurísticas para resolver um problema de empacotamento (bin packing). Este problema é uma abstração que serve para representar várias situações práticas. Para concretizar a situação, é considerado um cenário onde queremos armazenar arquivos de diferentes tamanhos em discos de tamanho fixo.
## Problematica
  O problema de bin packing é um problema fundamental para minimizar o consumo de um recurso escasso, geralmente espaço.

  ## Aplicações
    Empacotar os dados para tráfego na Internet, otimizar a alocação de arquivos, alocar a memória do computador para programas, etc. Indústrias de tecido, papel e outras utilizam a versão 2D desse problema para otimizar o corte de peças em placas de tamanho fixo. Empresas de logística utilizam a versão 3D para otimizar o empacotamento de caixas ou caminhões. 

  ## Implementação
    Suponha uma empresa que realiza um backup diário de todos os seus arquivos em discos com capacidade de 1 GB. Para diminuir os custos, idealmente a quantidade de discos utilizada a cada backup deve ser a mínima necessária para armazenar todos os arquivos. Em outras palavras, a tarefa é associar os arquivos a discos, usando a menor quantidade possível de discos. Infelizmente, esse problema e NP-hard, o que quer dizer que é muito pouco provável que exista um algoritmo eficiente (polinomial) para encontrar o empacotamento ótimo. Assim, o objetivo deste trabalho é projetar e implementar heurísticas que executam rapidamente e produzem boas soluções (próximas do ótimo).
  Podemos formular o problema de bin packing da seguinte forma: dado um conjunto de N arquivos, todos com tamanhos entre 0 e 1,000,000 KB (1 GB), devemos descobrir uma forma de associá-los a um número mínimo de discos, cada um com capacidade 1 GB. Duas heurísticas bastante intuitivas surgem imediatamente.
 ## Heurísticas Utilizadas
  As heurísticas utilizadas forma Worst-fit, Best-fit, Worst-fit decrescentes e Best-fit decrescentes.
  ## worst-fit
     A heurística worst-fit considera os arquivos na ordem que eles são apresentados: se o arquivo não cabe em nenhum dos discos atualmente em uso, crie um novo disco; caso contrário, armazene o arquivo no disco que tem o maior espaço restante. Por exemplo, este algoritmo colocaria os cinco arquivos de tamanho 700,000, 800,000, 200,000, 150,000 e 150,000 em três discos: {700,000, 200,000}, {800,000, 150,000} e {150,000}.
  ## best-fit
    A heurística best-fit é idêntica à exceção de que o arquivo é armazenado no disco que tem o menor espaço restante dentre todos os discos com espaço suficiente para armazenar o arquivo. Essa heurística colocaria a sequência anterior de arquivos em dois discos: {800,000, 200,000} e {700,000, 150,000, 150,000}. 
  ## Worst-fit e Best-fit decrescentes
    Empacotadores experientes sabem que se os itens menores são empacotados por último eles podem ser usados para preencher as lacunas em pacotes quase cheios. Essa ideia motiva uma estratégia mais esperta: processar os arquivos do maior para o menor. A heurística worst-fit decrescente é igual a worst-fit mas antes os arquivos são ordenados por tamanho em ordem decrescente. A heurística de best-fit decrescente é definida de forma análoga.
