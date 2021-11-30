import os

tw = 32768
th = 32768
taw = 16
tah = 9
mw = 21
mh = 9

w = int(tw)
h = int(th * (taw / tah) / (mw / mh))
s = 2.0

aw = int(w / s) 
ah = int(h / s)
ax = 0
ay = 0
m = "HEAD-0"
d = "UGTABLET 6 inch PenTablet stylus"

mc = "xsetwacom set \"" + d + "\" MapToOutput " + m
ac = "xsetwacom set \"" + d +  "\" Area " + str(ax) + " " + str(ay) + " " + str(aw) + " " + str(ah)

os.popen(mc)
os.popen(ac)   

print("Done!")
