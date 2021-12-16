FILES=/home/florian/Documents/dotfiles

# Start slstatus for resource usage, date, etc.
slstatus &

# Set wallpaper.
feh --no-fehbg --bg-fill $FILES/wallpapers/wallpaper.jpeg &

# Run script to set drawing tablet area
python3 $FILES/other/tablet.py & 

# Start transparency manager
xcompmgr -c & 

# Set digital vibrance (nvidia only)
nvidia-settings --assign DigitalVibrance=1023 &

# Start premid for soundcloud rich presence in discord
premid &