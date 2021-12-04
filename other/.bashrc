shopt -s autocd
shopt -s histappend

case "$TERM" in
    xterm-color|*-256color) color_prompt=yes;;
esac

HISTSIZE=500
HISTFILESIZE=500

alias uwu="sudo"
alias die="shutdown -P now"
alias flex="neofetch"
alias ls="ls --color"
alias update="uwu apt update && uwu apt upgrade"

export PS1="\[$(tput setaf 4)\][\[$(tput setaf 6)\]\W\[$(tput setaf 4)\]]\[$(tput setaf 5)\] -> \[$(tput sgr0)\]"

cbonsai -p
