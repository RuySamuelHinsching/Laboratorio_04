# Laboratorio_04


2.Localize o arquivo RTX_Config.h na lista de
dependências do arquivo rtx_lib.c e
analise-o. Quais são as configurações para:
– OS_TICK_FREQ? ->    1000
– OS_THREAD_NUM? ->   1
– OS_THREAD_DEF_STACK_NUM? ->   1


3.Altere a configuração OS_TICK_FREQ para
500.
– Qual é o efeito dessa alteração na execução do
programa do projeto “tarefas”?  
R: Os LEDs D1 e D2 começam a piscar mais lentamente, aproximadamente na metade da velocidade.


4.Retorne a configuração OS_TICK_FREQ para
o seu valor original.
– Quais são os períodos de ativação das tarefas
thread1 e thread2?  
R: Como OS_TICK_FREQ é 1000 e OS_ROBIN_TIMEOUT é 5, então os períodos de ativação de thread1 e thread2 são de 5 ms.

