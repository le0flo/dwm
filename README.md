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

**Attenzione**

Questo programma necessita della mia versione di dmenu, perciò assicurati di scaricarla [quì](https://github.com/le0flo/dmenu).

### Configurazione

Prima definisci il file di avvio per l'X server (`~/.xinitrc`).

```sh
# Compositor
#picom -b

# Background
#feh --no-fehbg --bg-fill "/var/backgrounds/bg.jpg"

exec dwm
```

Poi assegna l'X server all'avvio automatico modificando il profilo di bash (`~/.bash_profile`).

```sh
# X11

if [[ -z $DISPLAY ]] && [[ $(tty) = /dev/tty1 ]]; then
	startx &> /dev/null
fi
```

In aggiunta, puoi appendere all'esistente `.bashrc`, le seguenti definizioni:

```sh
# Env

export _JAVA_AWT_WM_NONREPARENTING=1
export GIT_EDITOR=nvim

# Aliases

alias vim='nvim'
alias ls='ls --color=auto'
alias ll='ls --color=auto -al'
alias grep='grep --color=auto'
alias ssh='TERM=xterm-256color ssh'
alias shutdown='shutdown -h now'
```

Elencate sotto, sono alcune delle configurazioni che uso quotidianamente.

- Vim, [`~/.vimrc`](https://files.leoflo.me/configs/others/_vimrc)

- Alacritty, [`~/.config/alacritty/alacritty.toml`](https://files.leoflo.me/configs/alacritty/alacritty.toml)

- Touchpad, [`/etc/X11/xorg.conf.d/30-touchpad.conf`](https://files.leoflo.me/configs/others/30-touchpad.conf)
