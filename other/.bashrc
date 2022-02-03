shopt -s autocd
shopt -s histappend

case "$TERM" in
    xterm-color|*-256color) color_prompt=yes;;
esac

HISTSIZE=500
HISTFILESIZE=500

alias uwu="sudo"
alias ls="ls --color"
alias ll="ls -l"


export PS1="\[$(tput setaf 1)\][\[$(tput setaf 7)\]\u\[$(tput setaf 1)\]:\[$(tput setaf 7)\]\W\[$(tput setaf 1)\]]\[$(tput setaf 3)\] -> \[$(tput sgr0)\]"
