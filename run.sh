# Script por Gustavo Simões

# Script para facilitar o desenvolvimento de 
# projetos em linguagem C.

# Programa compila automaticamente arquivos .c 
# toda vez que eles são modificados.

# ! Necessária a instalação da biblioteca fswatch (https://github.com/emcrisostomo/fswatch)


BLUE='\033[0;34m' #blue
GREEN='\033[0;32m' #green
NC='\033[0m' #no color

echo "\n${BLUE}Watch files change${NC}\n\n" 

fswatch -0 lib/*.c | while read -d "" event

    xbase=${event##*/}
    xpref=${xbase%.*}
 
    #set teste to $(tell application "Terminal" to do script ${dir})
    
    echo "Compilado alterações... \n"
    gcc $event -o ./build/${xpref}.out
    #&& osascript -e teste 

    echo "${BLUE}Arquivo '${xpref}' compilado com sucesso!${NC}"
    echo $(pwd)/build/${xpref}.out
    echo "\n\n"