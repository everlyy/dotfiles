shopt -s autocd
shopt -s histappend

case "$TERM" in
    xterm-color|*-256color) color_prompt=yes;;
esac

function title { echo -en "\033]2;st - $1\007"; }
function cd { dir=$1; if [ -z "$dir" ]; then dir=~; fi; builtin cd "$dir" && title `pwd`; }

HISTSIZE=10000
HISTFILESIZE=10000

alias uwu="sudo"
alias ls="ls --color"

cd .

export PS1="\[$(tput setaf 2)\][\[$(tput setaf 0)\]\u\[$(tput setaf 2)\]:\[$(tput setaf 0)\]\W\[$(tput setaf 2)\]]\[$(tput setaf 0)\] -> \[$(tput sgr0)\]"
