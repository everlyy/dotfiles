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


export PS1="\[$(tput setaf 2)\][\[$(tput setaf 0)\]\u\[$(tput setaf 2)\]:\[$(tput setaf 0)\]\W\[$(tput setaf 2)\]]\[$(tput setaf 0)\] -> \[$(tput sgr0)\]"
