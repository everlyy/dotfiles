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
alias update="uwu apt update && uwu apt upgrade -y && uwu apt autopurge"

export PS1="\[$(tput setaf 1)\][\[$(tput setaf 7)\]\W\[$(tput setaf 1)\]]\[$(tput setaf 3)\] -> \[$(tput sgr0)\]"

cbonsai -p
