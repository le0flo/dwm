# Dynamic Window Manager

Un window manager minimale e personalizzabile.

### Dipendenze 

Lista delle dipendenze fondamentali per la compilazione.

```sh
sudo pacman -S base-devel xorg-server xorg-xinit xorg-xinput xorg-xsetroot libinput libx11 libxinerama libxft
```

Lista di pacchetti necessari per questa build di dwm.

```sh
sudo pacman -S scrot alacritty feh dex ttf-firacode-nerd
```

### Installazione

```sh
cd dwm
sudo make clean install
```

Infine per installare dmenu:

```sh
git clone https://github.com/le0flo/dmenu.git
cd dmenu
sudo make clean install
```

### Configurazione

Prima si definisce il file di startup del X server (`~/.xinitrc`).

```sh
# Compositor
#picom -b

# Background
#feh --no-fehbg --bg-fill "/var/backgrounds/bg.jpg"

exec dwm
```

Poi si dice alla shell di avviare l'X server al login dell'utente (`~/.bash_profile`).

```sh
# X11

if [[ -z $DISPLAY ]] && [[ $(tty) = /dev/tty1 ]]; then
	startx &> /dev/null
fi
```

Infine, organizziamo il `.bashrc` con tutto ciò che ci serve.

```sh
# Env

export _JAVA_AWT_WM_NONREPARENTING=1
export GIT_EDITOR=vim

# Aliases

alias ls='ls --color=auto'
alias ll='ls --color=auto -al'
alias grep='grep --color=auto'
alias ssh='TERM=xterm-256color ssh'
alias shutdown='shutdown -h now'
```

Elencate sotto, sono alcune delle configurazioni che uso quotidianamente.

- Vim, [`~/.vimrc`](https://files.leoflo.me/config/others/.vimrc)

- Alacritty, [`~/.config/alacritty/alacritty.toml`](https://files.leoflo.me/config/alacritty/alacritty.toml)

- Touchpad, [`/etc/X11/xorg.conf.d/30-touchpad.conf`](https://files.leoflo.me/config/others/30-touchpad.conf)
