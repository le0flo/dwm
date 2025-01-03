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

Serve anche la mia versione di [dmenu](https://github.com/le0flo/dmenu)

### Installazione

```sh
cd dwm
sudo make clean install
```
