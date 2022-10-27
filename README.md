# Compilador-ASM-x64

Um app em C que compila um arquivo .s ou .asm no diretório atual.

Ao compilar um arquivo assembly, é necessário escrever múltiplos comandos cada vez que codigo diferente seja executado. Assim me veio a ideia de automatizar este processo.
Este projeto em C detecta o primeiro arquivo lexicográfico assembly no diretorio atual, o compila em objeto e executavel, deleta o objeto, executa o arquivo final e pausa o cmd para análise de output.
