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
alias update="uwu apt update && uwu apt upgrade -y && uwu apt autopurge -y"

export PS1="\[$(tput setaf 1)\][\[$(tput setaf 7)\]\W\[$(tput setaf 1)\]]\[$(tput setaf 3)\] -> \[$(tput sgr0)\]"

session_name="session"

# tmux thing to not make it cry
# https://koenwoortman.com/tmux-sessions-should-be-nested-with-care-unset-tmux-to-force/
tmux has-session -t=$session_name 2> /dev/null

if [[ $? -ne 0 ]]; then
  TMUX='' tmux new-session -d -s "$session_name"
fi

if [[ -z "$TMUX" ]]; then
  tmux attach -t "$session_name"
else
  tmux switch-client -t "$session_name"
fi