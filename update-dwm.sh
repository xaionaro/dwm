cp config.def.h config.h; make && ( sudo mv /usr/bin/dwm.default /usr/bin/dwm.default-todelete; sudo cp dwm /usr/bin/dwm.default; kill "$(ps auxw | grep dwm | grep '/usr/bin/dw[m]' | awk '{print $2}')"; sleep 1; sudo rm -f /usr/bin/dwm.default-todelete )