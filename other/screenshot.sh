#! /bin/bash

IMAGEPATH="/home/everly/Pictures/screenshots/"
FILENAME="%s.png"
QUALITY=90
EXEC="xclip -selection clipboard -t image/png -i \$f; notify-send \"Screenshot copied\" \"\$n\\n\$wx\$h\" -i \"\$f\""

scrot -s $IMAGEPATH$FILENAME -q $QUALITY -f -e "$EXEC"