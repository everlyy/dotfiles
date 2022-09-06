FILES=/home/everly/Documents/dotfiles

# Start slstatus for resource usage, date, etc.
slstatus &

# Set wallpaper.
feh --no-fehbg --bg-fill $FILES/wallpapers/image.jpeg &

# Run script to set drawing tablet area
python3 $FILES/other/tablet.py & 

# Start transparency manager
picom & 

# Set digital vibrance (nvidia only)
nvidia-settings --assign DigitalVibrance=1023 &
