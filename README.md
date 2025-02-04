# Dynamic Window Manager

### Dipendenze

Pacchetti fondamentali per la compilazione:

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
