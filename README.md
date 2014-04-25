autotools
=========

## Exemplos do uso do autotools


## checkinstall

Todas as distribuições incluem um conjunto generoso de pacotes, seja diretamente nos CDs de instalação, seja em repositórios disponíveis via web. Os repositórios oficiais do Debian, por exemplo, combinados com o repositório non-free e mais alguns repositórios não oficiais podem facilmente oferecer mais de 22.000 pacotes diferentes.

Mesmo assim, muitos drivers e softwares não estão disponíveis nos repositórios e precisam ser instalados manualmente a partir do código fonte. O checkinstall facilita esta tarefa, principalmente se você precisa instalar o mesmo software em várias máquinas ou quer distribuí-lo para amigos, gerando um pacote .deb, .tgz ou .rpm com o software pré-compilado, que pode ser instalado usando o gerenciador de pacotes de cada distribuição.

Para usá-lo, comece instalando o pacote usando o apt-get, urpmi, yun ou outro gerenciador de pacotes usado na sua distribuição. Ele é um pacote bastante comum, que vem incluído em todas as principais distribuições. 

Para usá-lo, comece instalando o pacote usando o apt-get, urpmi, yun ou outro gerenciador de pacotes usado na sua distribuição. Ele é um pacote bastante comum, que vem incluído em todas as principais distribuições. No Debian por exemplo bastaria um:

```bash
  # apt-get install checkinstall
```

O funcionamento do checkinstall é simples. Ao instalar qualquer pacote a partir do código fonte, substitua o comando "make install" pelo comando apropriado do checkinstall. Onde:

```bash
  # checkinstall -D
```
(gera um pacote .deb, para distribuições derivadas do Debian)

```bash
  # checkinstall -R
```
(gera um pacote .rpm, que pode ser usado em distribuições derivadas do Red Hat)


```bash
  # checkinstall -S
```
(gera um pacote .tgz, para o Slackware)
