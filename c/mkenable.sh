#!/bin/bash

# Nome da variável é passado como argumento
VAR_NAME=$1

# Verifica se o nome da variável foi fornecido
if [ -z "$VAR_NAME" ]; then
	echo "Usage: mkenable <variable-name>"
	echo "Example: ./mkenable debug"
	exit 1
fi

ARG_LOWER=${VAR_NAME,,}
ARG_LOWER_FORMATED=${ARG_LOWER//-/_}
ARG_LOWER_SPACED=${ARG_LOWER//-/ }
ARG_UPPER_FORMATED=${ARG_LOWER_FORMATED^^}

# Gera o script
echo '## --enable-'"$ARG_LOWER"
cat <<EOF | sed 's/^/#  /'

- ------------------------------------------------ -
O Default da opção $ARG_UPPER_FORMATED é NULL, e quando
usar ./configure --enable-$ARG_LOWER a opção
$ARG_UPPER_FORMATED torna-se 1.
- ------------------------------------------------ -

No arquivo .c use:
#if $ARG_UPPER_FORMATED
  /* você usou: --enable-$ARG_LOWER */
  printf("$ARG_UPPER_FORMATED: %s\n", "ENABLE");
#else
  /* Modo default */
  printf("$ARG_UPPER_FORMATED: %s\n", "DISABLE");
#endif

EOF

cat <<EOF | w3m -dump -T 'text/html' | sed 's/^/# /'
<table border="1">
  <tr>
    <th>Command Line</th>
    <th>Variable</th>
    <th>State</th>
  </tr>
  <tr>
    <td>&quot;&quot;</td>
    <td>$ARG_UPPER_FORMATED</td>
    <td>NULL (->default)</td>
  </tr>
  <tr>
    <td>&quot;--enable-$ARG_LOWER&quot;</td>
    <td>$ARG_UPPER_FORMATED</td>
    <td>1</td>
  </tr>
</table>
EOF

cat <<EOF
AC_ARG_ENABLE([$ARG_LOWER_FORMATED],
  [AS_HELP_STRING([--enable-$ARG_LOWER],
    [Turn on $ARG_LOWER_SPACED @<:@default: no@:>@])],
  [case "\${enableval}" in
    yes) $ARG_LOWER_FORMATED=true ;;
    no)  $ARG_LOWER_FORMATED=false ;;
    *) AC_MSG_ERROR([bad value \${enableval} for --enable-$ARG_LOWER]) ;;
  esac],
  [$ARG_LOWER_FORMATED=false])

AM_CONDITIONAL([$ARG_UPPER_FORMATED], [test x\$$ARG_LOWER_FORMATED = xtrue])

if test "x\${$ARG_LOWER_FORMATED}" = xtrue; then
  AC_DEFINE($ARG_UPPER_FORMATED, 1, [Turn on $ARG_LOWER_SPACED])
fi
EOF
