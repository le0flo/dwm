# Dynamic Window Manager

Un window manager minimale e personalizzabile.

### Dipendenze

Dipendenze fondamentali per la compilazione:

```sh
sudo pacman -S base-devel xorg-server xorg-xinit xorg-xinput libinput libx11 libxinerama libxft
```

Pacchetti necessari per questa build di dwm:

```sh
sudo pacman -S alacritty feh dex ttf-firacode-nerd
```

### Installazione

```sh
cd dwm
sudo make clean install
```

**Importante**

Scarica la mia versione di dmenu [quì](https://github.com/le0flo/dmenu).

### Configurazione

Crea il file di avvio per l'X server (`~/.xinitrc`).

```sh
# Background
#feh --no-fehbg --bg-fill "$HOME/.config/backgrounds/bg.jpg"

exec dwm
```

Aggiorna il file `.bashrc` (o `.zshrc` nel caso abbiate zsh), appendendo le seguenti definizioni:

```sh
# X11

if [[ -z $DISPLAY ]] && [[ $(tty) = /dev/tty1 ]]; then
	startx &> /dev/null
fi
```

Le configurazioni che utilizzo le potete trovare [quì](https://github.com/le0flo/configs).
