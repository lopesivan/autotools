#!/bin/bash

# Nome da variável é passado como argumento
VAR_NAME=$1

# Verifica se o nome da variável foi fornecido
if [ -z "$VAR_NAME" ]; then
	echo "Usage: mkdisable <variable-name>"
	echo "Example: ./mkdisable gnu-args"
	exit 1
fi

ARG_LOWER=${VAR_NAME,,}
ARG_LOWER_FORMATED=${ARG_LOWER//-/_}
ARG_LOWER_SPACED=${ARG_LOWER//-/ }
ARG_UPPER_FORMATED=${ARG_LOWER_FORMATED^^}

# Gera o script
echo '## --disable-'"$ARG_LOWER"
cat <<EOF | sed 's/^/#  /'

- ------------------------------------------------ -
O Default da opção $ARG_UPPER_FORMATED é 1, e quando
usar ./configure --disable-$ARG_LOWER a opção
$ARG_UPPER_FORMATED torna-se NULL
- ------------------------------------------------ -

No arquivo .c use:
#if $ARG_UPPER_FORMATED
  /* Modo default */
  printf("$ARG_UPPER_FORMATED: %s\n", "ENABLE");
#else
  /* você usou: --disable-$ARG_LOWER */
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
    <td>1 (->default)</td>
  </tr>
  <tr>
    <td>&quot;--disable-$ARG_LOWER&quot;</td>
    <td>$ARG_UPPER_FORMATED</td>
    <td>NULL</td>
  </tr>
</table>
EOF

cat <<EOF
AC_ARG_ENABLE([$ARG_LOWER],
  [AS_HELP_STRING([--disable-$ARG_LOWER],
    [disable $ARG_LOWER_SPACED @<:@default: no@:>@])],
  [$ARG_LOWER_FORMATED=\${enableval}], [$ARG_LOWER_FORMATED=yes])

if test "x\${$ARG_LOWER_FORMATED}" = xyes; then
   AC_DEFINE($ARG_UPPER_FORMATED, 1, [Enable args])
fi
AM_CONDITIONAL([WITH_$ARG_UPPER_FORMATED], [test x\${$ARG_LOWER_FORMATED} = xyes])
EOF
